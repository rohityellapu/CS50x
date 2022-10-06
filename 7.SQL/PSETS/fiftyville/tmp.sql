
SELECT people.name, airports.city
        FROM people
        JOIN passengers ON people.passport_number = passengers.passport_number
        JOIN flights ON passengers.flight_id = flights.id
        JOIN airports ON flights.destination_airport_id = airports.id
        WHERE  year = '2021' AND month = '7' AND day = '29'