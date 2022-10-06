
SELECT name,transcript
            FROM interviews
            WHERE year = '2021' AND month = '7' AND day = '28' 


-- SELECT people.name
--         FROM people
--         JOIN passengers ON people.passport_number = passengers.passport_number
--         WHERE passengers.flight_id
--         IN (SELECT id FROM flights WHERE year = '2021' AND month = '7' AND day = '28');
