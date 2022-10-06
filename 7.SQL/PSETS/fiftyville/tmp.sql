
SELECT name
    FROM people
    WHERE name
    IN (SELECT name
            FROM interviews
            WHERE year = '2021' AND month = '7' AND day = '28')
    AND (phone_number
        IN (SELECT caller
                FROM phone_calls
                WHERE year = '2021' AND month = '7' AND day = '28' AND duration < 60))
    OR (phone_number IN (SELECT reciever
                FROM phone_calls
                WHERE year = '2021' AND month = '7' AND day = '28' AND duration < 60))