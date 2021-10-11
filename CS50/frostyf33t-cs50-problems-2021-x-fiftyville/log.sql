-- Keep a log of any SQL queries you execute as you solve the mystery.
--Initial search to get more details
SELECT description FROM crime_scene_reports WHERE day = 28 and month = 7 and street = "Chamberlin Street";
--Shows the crime at 10:15, 3 witnesses, and mention courthouse
--Read all the interviews on that day
SELECT * FROM interviews WHERE day = 28 and month = 7;
--Ruth mentions she says the car drive away.  Suggests looking for cars that left in the time frame
--Eugene says he saw the thief at an ATM on Fifer street
--Raymond says the call took less than a minute when they were leaving the courthouse.  Thief said they want earliest flight out of fiftyville the next day.
--The thief then asked the other person to buy the ticket
--Get license plate info
SELECT activity, license_plate FROM courthouse_security_logs WHERE day = 28 and month = 7 and hour between 10 and 11 and activity = "exit";
--there were no exits logged before noon?
exit | 5P2BI95
exit | 94KL13X
exit | 6P58WS2
exit | 4328GD8
exit | G412CB7
exit | L93JTIZ
exit | 322W7JE
exit | 0NTHK55
exit | 1106N58
--Search atm logs
Select * FROM atm_transactions WHERE day = 28 and month = 7 and atm_location = "Fifer Street";
--id | account_number | transaction_type | amount
--246 | 28500762 | withdraw | 48
--264 | 28296815 | withdraw | 20
--267 | 49610011 | withdraw | 50
--269 | 16153065 | withdraw | 80
--288 | 25506511 | withdraw | 20
--313 | 81061156 | withdraw | 30
--336 | 26013199 | withdraw | 35
--Search call logs
SELECT id, caller, receiver, duration FROM phone_calls WHERE day = 28 and month = 7 and duration <120;
--218 | (233) 555-0473 | (831) 555-0973 | 113
--221 | (130) 555-0289 | (996) 555-8899 | 51
--224 | (499) 555-9472 | (892) 555-8872 | 36
--233 | (367) 555-5533 | (375) 555-8161 | 45
--234 | (609) 555-5876 | (389) 555-5198 | 60
--237 | (394) 555-3247 | (035) 555-2997 | 111
--240 | (636) 555-4198 | (670) 555-8598 | 69
--244 | (704) 555-2131 | (891) 555-5672 | 103
--246 | (873) 555-3868 | (047) 555-0577 | 109
--247 | (867) 555-9103 | (068) 555-0183 | 116
--251 | (499) 555-9472 | (717) 555-1342 | 50
--254 | (286) 555-6063 | (676) 555-6554 | 43
--255 | (770) 555-1861 | (725) 555-3243 | 49
--260 | (669) 555-6918 | (971) 555-6468 | 67
--261 | (031) 555-6622 | (910) 555-3251 | 38
--266 | (016) 555-9166 | (336) 555-0077 | 88
--271 | (751) 555-6567 | (594) 555-6254 | 61
--279 | (826) 555-1652 | (066) 555-9701 | 55
--281 | (338) 555-6650 | (704) 555-2131 | 54
--283 | (730) 555-5115 | (343) 555-0167 | 101
--285 | (367) 555-5533 | (704) 555-5790 | 75
--Used this to find airport code
SELECT id FROM airports Where city like "Fiftyville";
--code is 8
--Searching for flights
SELECT city, flights.id FROM flights JOIN airports ON airports.id = destination_airport_id WHERE origin_airport_id = 8 and month = 7 and day = 29;
--SELECT passport_number, seat FROM passengers JOIN flights ON flights.id = passengers.flights_id WHERE month = 7 and day = 29
Boston | 18
San Francisco | 23
London | 36
Chicago | 43
Tokyo | 53
--cross reference phone numbers, personid in atm, where atm interactions, passport number in flights that dqy, license plate
--They called someone
Madison
Russell
Ernest
Madison called (676) 555-6554 james
Russell called (725) 555-3243 phillip
Ernesy called (375) 555-8161 berthold and (704) 555-5790 carl


Ernest and madison









