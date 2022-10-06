SELECT people.name AS accomplice
        FROM people
        JOIN phone_calls ON people.phone_number = phone_calls.receiver
        
