/*
   Implementation of MaxBotix MB1242 sonar driver

   Copyright (C) 2016 Simon D. Levy and Matt Lubas

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

#include "MB1242.h"

#include <stdint.h>
#include <Arduino.h>

#if defined(__MK20DX256__) // Teensy 3.1/2
#include <i2c_t3.h>
#else
#include <Wire.h>
#endif

#define CYCLE_PERIOD_USEC 10000

static void update_timed_task(unsigned int * usec, uint32_t period)
{
    *usec = micros() + period;
}

static bool check_and_update_timed_task(unsigned int * usec, uint32_t period)
{
    bool result = (int32_t)(micros() - *usec) >= 0;

    if (result)
        update_timed_task(usec, period);

    return result;
}

bool MB1242::attempt_write(void)
{
    Wire.beginTransmission(this->addr);
    Wire.write(0x51);
    return !Wire.endTransmission();
}


void MB1242::begin(unsigned char address)
{
    this->addr = address;
    this->state = 0;
    this->distance = 0;
    this->time = 0;
}

void MB1242::changeAddress(unsigned char oldaddr, unsigned char newaddr)
{
    Wire.beginTransmission(oldaddr);
    Wire.write(0xAA);
    Wire.write(0xA5);
    Wire.write(newaddr<<1); // write twice the new address, to support seven-bit addressing
    Wire.endTransmission();
}


int MB1242::getDistance(void)
{
    if (check_and_update_timed_task(&this->time, CYCLE_PERIOD_USEC)) {

        if (this->state == 0) {
            if (attempt_write())
                this->state++;
        }
        else if (this->state == 1) {
            uint8_t bytes[2];
            Wire.requestFrom(this->addr, 2);
            if (Wire.available() == 2) {
                bytes[0] = Wire.read();
                bytes[1] = Wire.read();
                this->distance = (bytes[0] << 8) + bytes[1];
                this->state++;
            }
        }
        else {
            this->state = 0;
        }
    }

    return this->distance;
}
