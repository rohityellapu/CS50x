-- Keep a log of any SQL queries you execute as you solve the mystery.

-- First we go through the crime scenes happened in July 28th 2021 at Humphrey Street;
SELECT *
        FROM crime_scene_reports
        WHERE year = '2021' AND month = '7' AND day = '28' AND street = 'Humphrey Street';

-- Two crime incidents happened on that day, one is related to Theft and other is related to Littering .We can exlude the latter case
-- As per description in crime report, the theft took place at 10:15 AM at the Humphrey Street bakety.
-- Interviews were conducted with three witness, all of them mentioned bakery. So we list the names and transcript accordingly
SELECT name,transcript
            FROM interviews
            WHERE year = '2021' AND month = '7' AND day = '28' AND transcript LIKE '%bakery%';


-- The names of the three witnessess are Ruth, Eugene and Raymond
-- Ruth claimed that the thief had left the bakery within ten minutes by car in parking lot.
-- We list all the people who left the bakery in that time frame and order them name and put them on suspect list;
SELECT people.name, bakery_security_logs.activity
        FROM people
        JOIN bakery_security_logs
        ON people.license_plate = bakery_security_logs.license_plate
        WHERE bakery_security_logs.year = '2021'
                AND bakery_security_logs.month = '7'
                AND bakery_security_logs.day = '28'
                AND bakery_security_logs.hour = 10
                AND bakery_security_logs.minute <= 25
                AND bakery_security_logs.minute >= 15
                AND bakery_security_logs.activity = 'exit'
        ORDER BY people.name;

-- Eugene gave us clue that he saw the thief withrawing some money from an ATM on Legget Street
-- We list the names of people who withrawed money on that ATM and add them on suspect list
SELECT people.name,atm_transactions.amount
        FROM people
        JOIN bank_accounts ON people.id = bank_accounts.person_id
        JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
        WHERE atm_transactions.year = '2021'
                AND atm_transactions.month = '7'
                AND atm_transactions.day = '28'
                AND atm_transactions.atm_location = 'Leggett Street'
                AND atm_transactions.transaction_type = 'withdraw'
        ORDER BY people.name;

-- Raymond informed that the thief called somebody and talked for less than a minute about booking the earliest flight from Fiftyville on next day i.e. on July 29th
-- First we list all the people who called on that day and talked for less than 60 seconds
SELECT people.name, phone_calls.duration
        FROM people
        JOIN phone_calls
        ON people.phone_number = phone_calls.caller
        WHERE year = '2021' AND month = '7' AND day = '28' AND phone_calls.duration <= 60
        ORDER BY people.name;

-- Then we list names of people who booked the earliest flights on 29th July from Fiftyville along with destination city of the flights and them to suspect list
SELECT people.name, airports.city AS destination_city, flights.hour, flights.minute
        FROM people
        JOIN passengers ON people.passport_number = passengers.passport_number
        JOIN flights ON passengers.flight_id = flights.id
        JOIN airports ON flights.destination_airport_id = airports.id
        WHERE  flights.year = '2021' AND flights.month = '7' AND flights.day = '29' AND flights.hour < 12 AND flights.origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville')
        ORDER BY flights.hour, flights.minute,people.name;

-- We found the earliest flights starting at 8:20 AM, 9: 30 AM , flying to New York City and Chicago
-- Among all the suspect lists, Bruce is common in all. Therefore, Bruce must be thief and is flying to New York City.
-- To find the accomplice we list the name of person who recieved the call from Bruce at the day of theft
SELECT people.name AS accomplice
        FROM people
        JOIN phone_calls ON people.phone_number = phone_calls.receiver
        WHERE phone_calls.caller = (SELECT phone_number FROM people WHERE name = 'Bruce')
        AND phone_calls.year = '2021' AND phone_calls.month = '7' AND phone_calls.day = '28' AND phone_calls.duration <= 60


-- There is only one person named Robin, therefore he is the accomplice who helped Bruce in booking the flight ticket.