-- Keep a log of any SQL queries you execute as you solve the mystery.

-- SELECT * FROM crime_scene_reports WHERE year = '2021' AND month = '7' AND day = '28' AND street = 'Humphrey Street';
-- .schema
SELECT name
    FROM people
    WHERE name
    IN (SELECT name
            FROM interviews
            WHERE year = '2021' AND month = '7' AND day = '28')
    AND phone_number
    IN (SELECT caller FROM phone_calls WHERE year = '2021' AND month = '7' AND day = '28')