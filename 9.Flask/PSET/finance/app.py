import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime
from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    user_stocks = db.execute(
        "SELECT symbol,stock_name, SUM(no_of_shares) AS shares FROM history WHERE username = ? GROUP BY symbol;", session['user'])

    return render_template('index.html')

# INSERT INTO history ()

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        # Ensure symbol was submitted
        if not request.form.get("symbol"):
            return apology("Must provide symbol", 403)

        # Ensure shares was submitted
        elif not request.form.get("shares") or int(request.form.get('shares')) < 1:
            return apology("Must provide valid number of shares", 403)

        quote = lookup(request.form.get('symbol'))

        if quote:
            balance = db.execute(
                'SELECT cash FROM users WHERE username = ?', session["user"])
            total = quote['price'] * float(request.form.get('shares'))

            if balance[0]['cash'] >= total:
                balance[0]['cash'] -= total

                db.execute(
                    'INSERT INTO history (username, transaction_type, symbol,stock_name, stock_price,no_of_shares,total, transacted) VALUES (?,?,?,?,?,?,?,?)',
                    session["user"], "buy", quote["symbol"], quote["name"], quote["price"], request.form.get('shares'), total, datetime.now())
                db.execute('UPDATE users SET cash = ? WHERE username = ?',
                           balance[0]['cash'], session['user'])

                return redirect("/")

            else:
                return apology('No enough balance.Try different number of shares')

        else:
            return apology('Invalid stock symbol.')

    else:
        return render_template('buy.html')


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("Must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?",
                          request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("Invalid username and/or password", 403)

        # Remember which user has logged in
        session["user"] = rows[0]["username"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        if not request.form.get('symbol'):
            return apology('Must provide Symbol', 403)

        quote = lookup(request.form.get('symbol'))
        if quote:
            return render_template('quoted.html', quote=quote)
        else:
            return apology('Invalid stock symbol.')

    else:
        return render_template('quote.html')


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == 'POST':
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("Must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("Must provide password", 403)

        elif request.form.get('password') != request.form.get('password2'):
            return apology('Passwords doesn"t match', 403)
        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?",
                          request.form.get("username"))
        if len(rows) != 0:
            return apology("User already exists, try loggin in", 403)

        db.execute('INSERT INTO users (username, hash) VALUES (?,?)',
                   request.form.get("username"), generate_password_hash(request.form.get("password")))
        # Remember which user has logged in
        session["user"] = request.form.get("username")
        flash('Registered!')
        # Redirect user to home page
        return redirect("/")

    else:
        return render_template('register.html')


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    user_stocks = db.execute(
        'SELECT symbol, SUM(no_of_shares) AS shares FROM history WHERE username = ? GROUP BY symbol', session['user'])
    print(user_stocks)
    if len(user_stocks) == 0:
        return aplogy('You don"t have any stocks yet, Goto buy option to buy some', 403)
    if request.method == 'POST':

        if not request.form.get("shares") or int(request.form.get('shares')) < 1:
            return apology("Must provide valid number of shares", 403)

        quote = lookup(request.form.get('symbol'))

        for stock in user_stocks:
            if stock['symbol'] == request.form.get('symbol'):
                if stock['shares'] < int(request.form.get('shares')):
                    return apology('Number of shares are more than you own. Try a different number.', 403)
        balance = db.execute(
                'SELECT cash FROM users WHERE username = ?', session["user"])
        total = quote['price'] * float(request.form.get('shares'))
        balance[0]['cash'] += total
        shares = -int(request.form.get('shares'))
        db.execute(
            'INSERT INTO history (username, transaction_type, symbol,stock_name, stock_price,no_of_shares,total, transacted) VALUES (?,?,?,?,?,?,?,?)',
            session["user"], "sell", quote["symbol"], quote["name"], quote["price"], shares, total, datetime.now())

        db.execute('UPDATE users SET cash = ? WHERE username = ?',
                   balance[0]['cash'], session['user'])
        return redirect('/')
    else:

        return render_template('sell.html', stocks=user_stocks)



