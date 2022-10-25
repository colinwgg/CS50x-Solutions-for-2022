-- Keep a log of any SQL queries you execute as you solve the mystery.
.schema --check all of the information available.

SELECT description
  FROM crime_scene_reports
 WHERE month = 7
   AND year = 2021
   AND day = 28
   AND street = "Humphrey Street";
-- 10:15am; Humphrey Street bakery; 3 witnesses; interview transcripts mentions the bakery.

SELECT *
  FROM interviews
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND transcript LIKE "%bakery%";
-- 1. bakery parking lot; within 10 minutes
-- 2. ATM on Leggett Street; the thief withdrawing some money
-- 3. take the earliest flight on 7.29, phonecall less than one minute

-- check the earliest flight on 7.29
SELECT *
  FROM flights
 WHERE year = 2021
   AND month = 7
   AND day = 29
 ORDER BY hour, minute;
-- id = 36 form 8 to 4, at 8:20.

-- check the people according to the evidence above.
SELECT name
  FROM people, bank_accounts
 WHERE bank_accounts.person_id = people.id
   AND account_number IN
       (SELECT account_number
          FROM atm_transactions
         WHERE year = 2021
           AND month = 7
           AND day = 28
           AND atm_location = "Leggett Street"
           AND transaction_type = "withdraw")
   AND license_plate IN
       (SELECT license_plate
          FROM bakery_security_logs
         WHERE year = 2021
           AND month = 7
           AND day = 28
           AND hour = 10
           AND minute > 15 AND minute <25)
   AND passport_number IN
       (SELECT passport_number
          FROM passengers
         WHERE flight_id = 36)
   AND phone_number IN
       (SELECT caller
          FROM phone_calls
         WHERE year = 2021
           AND month = 7
           AND day = 28
           AND duration < 60);
-- got the thief: Bruce

-- check his destination
SELECT city
  FROM airports
 WHERE id = 4;
-- New York City

-- check the phonecall's receiver
SELECT name
  FROM people
 WHERE phone_number =
       (SELECT receiver
        FROM phone_calls
        WHERE caller =
              (SELECT phone_number
                 FROM people
                WHERE name = "Bruce")
        AND year = 2021
        AND month = 7
        AND day = 28
        AND duration < 60);
-- accomplice: Robin