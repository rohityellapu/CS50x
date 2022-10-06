

SELECT people.name, phone_calls.duration
        FROM people
        JOIN phone_calls
        ON people.phone_number = phone_calls.caller
        WHERE year = '2021' AND month = '7' AND day = '28' AND phone_calls.duration <= 60
        ORDER BY phone_calls.duration;
