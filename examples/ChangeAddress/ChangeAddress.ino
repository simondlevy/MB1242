/*
   ChangeAddress.ino change I^2C address on MaxBotix MB1242 sonar

   Copyright (C) 2016 Simon D. Levy 
   
   This file is part of MB1242_Arduino.

   MB1242_Arduino is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   MB1242_Arduino is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with MB1242_Arduino.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <MB1242.h>

#if defined(__MK20DX256__) // Teensy 3.1/2
#include <i2c_t3.h>
#else
#include <Wire.h>
#endif

#define OLDADDR 0x70
#define NEWADDR 0x72

void setup()
{
    // Start I^2C
#if defined(__MK20DX256__) // Teensy 3.1/2
     Wire.begin(I2C_MASTER, 0x00, I2C_PINS_18_19, I2C_PULLUP_INT, 400000);
#else
    Wire.begin();
#endif


    MB1242::changeAddress(OLDADDR, NEWADDR);
}


void loop()
{
}
