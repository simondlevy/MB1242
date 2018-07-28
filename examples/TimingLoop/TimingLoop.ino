/*
   TimingLoop.ino show distances read by MaxBotix MB1242 sonar

   This version uses an efficient timing loop instead of a delay

   Copyright (C) 2018 Simon D. Levy

   This file is part of MB1242.

   MB1242 is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   MB1242 is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with MB1242.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <MB1242.h>

#if defined(__MK20DX256__) // Teensy 3.1/2
#include <i2c_t3.h>
#else
#include <Wire.h>
#endif

static MB1242 sonar;

void setup()
{
    // Start I^2C
#if defined(__MK20DX256__) // Teensy 3.1/2
     Wire.begin(I2C_MASTER, 0x00, I2C_PINS_18_19, I2C_PULLUP_INT, 400000);
#else
    Wire.begin();
#endif

    // Start sonar
    sonar.begin();

    // Start serial
    Serial.begin(115200);
}


void loop()
{
    static uint32_t prevtime;
    static bool requested;

    if (requested) {

        uint32_t time = millis();

        // 100msec delay recommended by https://www.maxbotix.com/documents/I2CXL-MaxSonar-EZ_Datasheet.pdf
        if ((time-prevtime) > 100) {
            Serial.print(sonar.getDistance());
            Serial.println("cm");
            prevtime = time;
            requested = false;
        }
    }

    else {
        sonar.requestDistance();
        requested= true;
    }
}
