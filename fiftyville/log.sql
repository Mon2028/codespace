select description from crime_scene_reports where day = "28" and month = "7" and year = "2020" and street = "Chamberlin Street";
select transcript from interviews where day = "28" and month = "7" and year = "2020" AND transcript like "%courthouse%";

-- Based on transcript of the first interview: Finding the names of the people who exit the courthouse 10 minutes after the theft.
SELECT name FROM people JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate WHERE day = "28" AND month = "7" AND year = "2020" AND hour = "10" AND minute >= "15" AND minute < "25" AND activity = "exit";

-- Based on transcript of the second interview: Finding the names of the people who withdrew money from the ATM on Fifer St on the day of the theft.
SELECT DISTINCT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number WHERE day = "28" AND month = "7" AND year = "2020" AND transaction_type = "withdraw" AND atm_location = "Fifer Street";

-- Based on the transcript of the third interview: Finding the names of the people who bought the first flight ticket for the day after the theft.
SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number WHERE flight_id = (SELECT id FROM flights WHERE day = "29" AND month = "7" AND year = "2020" ORDER BY hour,minute LIMIT 1);

-- Based on the transcript of the third interview: Finding the names of the people who had call for less than a minute on the day of the theft.
SELECT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller WHERE day = "28" AND month = "7" AND year = "2020" AND duration < "60";

-- Meet all the conditions to find the thief.
SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number WHERE flight_id = (SELECT id FROM flights WHERE day = "29" AND month = "7" AND year = "2020" ORDER By hour, minute LIMIT 1) INTERSECT SELECT DISTINCT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number WHERE day = "28" AND month = "7" AND year = "2020" AND transaction_type = "withdraw" AND atm_location = "Fifer Street" INTERSECT SELECT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller WHERE day = "28" AND month = "7" AND year = "2020" AND duration < "60" INTERSECT SELECT name FROM people JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate WHERE day = "28" AND month = "7" AND year = "2020" AND hour = "10" AND minute >= "15" AND minute < "25" AND activity = "exit";

-- Based on the transcript of the third interview: Finding the destination of the first flight ticket for the day after the theft.
SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE day = "29" AND month = "7" AND year = "2020" ORDER BY hour,minute LIMIT 1);

-- Based on the transcript of the third interview: Finding the name of the person whom the thief had call for less than a minute on the day of the theft.
SELECT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.receiver WHERE day = "28" AND month = "7" AND year = "2020" AND duration < "60" AND caller = (SELECT phone_number FROM people WHERE name = "Ernest");

-- The thief is Ernest, He ESCAPED TO London with Berthold help.

