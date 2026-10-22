// William Carmona Oct. 17, 2026
//
// Script for the time-capsule:
// - Creates I2C connection to DS3231 Module
// - Initalizes RTClib.h and Adafruit
// - RTC library begins and declares a DateTime object
// - Tracks seconds since a specific date through second accounting algorithim

#include<Wire.h>
#include<RTClib.h>

RTC_DS3231 myRTC;

// Seconds until June 10, 2027 from Oct. 17, 2026
unsigned long targetTime = 236 * 86400;

void setup() {
  Serial.begin(9600);

  Wire.begin();

  while(!myRTC.begin()) {
    Serial.println("RTC can not be found.");
  }
}

void loop() {
  // DateTime creates time and date
  // unixtime function gets epoch seconds
  DateTime now = myRTC.now();
  unsigned long totalSeconds = now.unixtime(); // Total seconds since Jan 1, 1970

  // Epoch Seconds counting since January 1st, 1970 00:00:00 UTC
  //      Serial.print("Total Unix Time: ");
  //      Serial.println(totalSeconds);
  
  // Subtracting Seconds since January 1st, 1970 00:00:00 UTC
  //      Serial.print("Time from Oct. 17, 2026 12 AM: ");
  // Time since 12 AM, for any day, just subtract number of days * 86400 if you want to change
  unsigned long secondsFromDate = totalSeconds - 982516785;
  //      Serial.println(secondsFromDate);

  if(secondsFromDate >= targetTime) {
    Serial.println("Target time reached.");
  }

  delay(1000);
}
