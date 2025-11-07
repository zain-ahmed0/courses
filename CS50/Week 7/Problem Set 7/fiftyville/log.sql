-- Keep a log of any SQL queries you execute as you solve the mystery.

-- To find the crime scene description
/*
SELECT *
FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';
*/

-- What I learnt:
/*
    Theft of the CS50 duck took place at 10:15 at Humphrey Street bakery
    Interviews were conducted today with 3 witnesses who were present at the time
    Each of their interview transcripts mentions the bakery
*/

-- Finding the people that got interviewed
/*
SELECT *
FROM interviews
WHERE month = 7 AND day = 28;
*/

/*
    Thief got into a car in the bakery parking lot and drove away within 10 minutes of the crime taking place
    Eugene knows them, saw them walking by an ATM on Leggett Street and saw the thief there withdrawing money
    Saw the thief talk on the phone for less than a minute, and the thief asked the person on the other end to purchase a ticket
    For the  earliest flight out of Fiftyville tomorrow.
*/

-- Find the cars at 10:15
/*
SELECT *
FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND activity = "exit";
*/

-- Finding the ATM the Thief used
/*
SELECT *
FROM atm_transactions
WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
*/

-- Find phone calls that happened on the day of the crime and that were less than a minute
/*
SELECT *
FROM phone_calls
WHERE month = 7 AND day = 28 AND duration < 60;
*/

-- Find the earliest flight that took place the day after the crime
/*
SELECT *
FROM flights
WHERE month = 7 AND day = 29 AND hour = 8 AND minute = 20;
*/

-- Find the flight id to find the passenger
/*
SELECT *
FROM passengers
WHERE flight_id = (
    SELECT id
    FROM flights
    WHERE month = 7 AND day = 29 AND hour = 8 AND minute = 20
);
*/

-- The city the thief escaped to
/*
SELECT city
FROM airports
WHERE id = (
    SELECT destination_airport_id
    FROM flights
    WHERE month = 7 AND day = 29 AND hour = 8 AND minute = 20
);
*/

-- List of suspects that could be the thief: that were at bakery and seen withrawing

SELECT name, phone_number, passport_number, license_plate
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND activity = "exit"
)
AND id IN (
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"
    )
)
AND phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE month = 7 AND day = 28 AND duration < 60
)
AND passport_number IN (
    SELECT passport_number
    FROM passengers
    WHERE flight_id = (
        SELECT id
        FROM flights
        WHERE month = 7 AND day = 29 AND hour = 8 AND minute = 20
    )
);

SELECT name, phone_number, passport_number, license_plate, id
FROM people
WHERE phone_number IN (
    SELECT receiver
    FROM phone_calls
    WHERE month = 7 AND day = 28 AND duration <= 60 AND caller IN (
        SELECT phone_number
        FROM people
        WHERE license_plate IN (
            SELECT license_plate
            FROM bakery_security_logs
            WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND activity = "exit"
        )
        AND id IN (
            SELECT person_id
            FROM bank_accounts
            WHERE account_number IN (
                SELECT account_number
                FROM atm_transactions
                WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"
            )
        )
        AND phone_number IN (
            SELECT caller
            FROM phone_calls
            WHERE month = 7 AND day = 28 AND duration < 60
        ) 
        AND passport_number IN (
            SELECT passport_number
            FROM passengers
            WHERE flight_id = (
                SELECT id
                FROM flights
                WHERE month = 7 AND day = 29 AND hour = 8 AND minute = 20
            )
        )
    )
);

-- List of Suspects: Taylor, Bruce
-- Accomplice: James, Robin

-- Thief: Bruce
-- Accomplice: Robin
