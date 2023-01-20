import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded

app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        name= request.form.get('name')
        month = request.form.get('month')
        day = request.form.get('day')

        missing = '';
        if not name:
            missing = 'Missing Name'
        elif not month:
            missing = 'Missing Month'
        elif not day:
            missing = 'Missing Day'
        else:
            db.execute(f"INSERT INTO birthdays (name, month, day) VALUES (?,?,?)", name, int(month), int(day))

        birthdays = db.execute(f"SELECT * FROM birthdays")
        return render_template('index.html', birthdays=birthdays, missing=missing)

    else:

        # TODO: Display the entries in the database on index.html
        birthdays = db.execute(f"SELECT * FROM birthdays")
        return render_template("index.html", birthdays=birthdays)


