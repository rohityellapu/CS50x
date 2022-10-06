

SELECT people.name,atm_transactions.amount
FROM people
INNER JOIN bank_accounts ON people.id = bank_accounts.person_id
INNER JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.year = '2021' AND atm_transactions.month = '7' AND atm_transactions.day = '28' AND atm_transactions.atm_location = 'Leggett Street' AND atm_transactions.transaction_type = 'withdrawal';