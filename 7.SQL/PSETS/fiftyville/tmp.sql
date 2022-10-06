


SELECT people.name, bakery_security_logs.activity,bakery_security_logs.minute
        FROM people
        JOIN bakery_security_logs
        ON people.license_plate = bakery_security_logs.license_plate
        WHERE year = '2021' AND month = '7' AND day = '28' AND activity = 'exit';
