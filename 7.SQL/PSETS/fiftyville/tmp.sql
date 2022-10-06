
SELECT name
    FROM people
    WHERE name
    IN (SELECT name
            FROM interviews
            WHERE year = '2021' AND month = '7' AND day = '28')


SELECT name FROM people
