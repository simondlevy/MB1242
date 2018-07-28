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

#include <CrossPlatformI2C.h>

#if defined(ARDUINO)
#include <Arduino.h>
#else
extern uint32_t micros(void);
#endif

static void update_timed_task(uint32_t * usec, uint32_t period)
{
    *usec = micros() + period;
}

static bool check_and_update_timed_task(uint32_t * usec, uint32_t period)
{
    bool result = (int32_t)(micros() - *usec) >= 0;

    if (result)
        update_timed_task(usec, period);

    return result;
}

bool MB1242::attempt_write(void)
{
    return cpi2c_writeRegister(_addr, 0x00, 0x51) > 0;
}

void MB1242::begin(uint8_t address)
{
    _addr = address;
    _state = 0;
    _distance = 0;
    _time = 0;
}

void MB1242::changeAddress(uint8_t oldaddr, uint8_t newaddr)
{
    cpi2c_beginTransmission(oldaddr);
    cpi2c_write(0xAA);
    cpi2c_write(0xA5);
    cpi2c_write(newaddr<<1); // write twice the new address, to support seven-bit addressing
    cpi2c_endTransmission();
}


uint16_t MB1242::getDistance(void)
{
    if (check_and_update_timed_task(&_time, CYCLE_PERIOD_USEC)) {

        if (_state == 0) {
            if (attempt_write())
                _state++;
        }
        else if (_state == 1) {
            uint8_t bytes[2];
            cpi2c_requestFrom(_addr, 2);
            if (cpi2c_available() == 2) {
                bytes[0] = cpi2c_read();
                bytes[1] = cpi2c_read();
                _distance = (bytes[0] << 8) + bytes[1];
                _state++;
            }
        }
        else {
            _state = 0;
        }
    }

    return _distance;
}
