
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
        OR phone_number IN (SELECT receiver
                    FROM phone_calls
                    WHERE year = '2021' AND month = '7' AND day = '28' AND duration < 60)
        OR license_plate
        IN (SELECT license_plate
                FROM bakery_security_logs WHERE year = '2021' AND month = '7' AND day = '28' AND minute < 10)
    AND passport_number
    IN (SELECT passport_number
            FROM passengers
            WHERE flight_id
            IN (SELECT id FROM flights WHERE year = '2021' AND month = '7' AND day = '28'))