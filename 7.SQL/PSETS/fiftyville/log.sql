-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT *
FROM crime_scene_reports
WHERE year = '2021' AND month = '7' AND day = '28' AND street = 'Humphrey Street';


SELECT name,transcript
            FROM interviews
            WHERE year = '2021' AND month = '7' AND day = '28' AND transcript LIKE '%bakery%';



SELECT people.name, bakery_security_logs.activity,
        FROM people
        JOIN bakery_security_logs
        ON people.license_plate = bakery_security_logs.license_plate
        WHERE year = '2021' AND month = '7' AND day = '28' AND minute <= 25 AND activity = 'exit';


SELECT people.name,atm_transactions.amount
        FROM people
        JOIN bank_accounts ON people.id = bank_accounts.person_id
        JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
        WHERE atm_transactions.year = '2021'
                AND atm_transactions.month = '7'
                AND atm_transactions.day = '28'
                AND atm_transactions.atm_location = 'Leggett Street'
                AND atm_transactions.transaction_type = 'withdraw';


SELECT people.name, phone_calls.duration
        FROM people
        JOIN phone_calls
        ON people.phone_number = phone_calls.caller
        WHERE year = '2021' AND month = '7' AND day = '28' AND phone_calls.duration <= 60
        ORDER BY phone_calls.duration;


SELECT people.name, airports.city AS destination_city, flights.hour, flights.minute
        FROM people
        JOIN passengers ON people.passport_number = passengers.passport_number
        JOIN flights ON passengers.flight_id = flights.id
        JOIN airports ON flights.destination_airport_id = airports.id
        WHERE  flights.year = '2021' AND flights.month = '7' AND flights.day = '29' AND flights.hour <= 12
        ORDER BY flights.hour, flights.minute;



SELECT people.name AS accomplice
        FROM people
        JOIN phone_calls ON people.phone_number = phone_calls.receiver
        WHERE phone_calls.caller = (SELECT phone_number FROM people WHERE name = 'Bruce')
        AND phone_calls.year = '2021' AND phone_calls.month = '7' AND phone_calls.day = '28' AND phone_calls.duration <= 60
