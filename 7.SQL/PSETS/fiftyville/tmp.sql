
SELECT name
    FROM people
    WHERE name
    IN (SELECT name
            FROM interviews
            WHERE year = '2021' AND month = '7' AND day = '28')


SELECT people.name FROM people JOIN passengers ON people.passport_number = passengers.passport_number WHERE passport_number IN (SELECT)
