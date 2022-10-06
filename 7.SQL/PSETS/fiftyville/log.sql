-- Keep a log of any SQL queries you execute as you solve the mystery.

-- SELECT * FROM crime_scene_reports WHERE year = '2021' AND month = '7' AND day = '28' AND street = 'Humphrey Street';
-- .schema
SELECT name
    FROM people
    WHERE name
    IN (SELECT name
            FROM interviews
            WHERE year = '2021' AND month = '7' AND day = '28')
    AND (phone_number
        IN (SELECT caller
                FROM phone_calls
                WHERE year = '2021' AND month = '7' AND day = '28' AND duration < 60)
        OR passport_number
        IN (SELECT passport_number
                FROM passengers
                WHERE flight_id
                IN (SELECT id FROM flights WHERE year = '2021' AND month = '7' AND day = '28'))
        OR license_plate
        IN (SELECT license_plate
                FROM bakery_security_logs WHERE year = '2021' AND month = '7' AND day = '28' AND minute < 10)
        OR id
        IN (SELECT person_id
                FROM bank_accounts
                WHERE account_number
                IN (SELECT account_number
                        FROM atm_transactions
                        WHERE year = '2021' AND month = '7' AND day = '28' AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw')))