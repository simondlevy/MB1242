/*
   Implementation of MaxBotix MB1242 sonar driver

   Copyright (C) 2016 Simon D. Levy and Matt Lubas

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

#include "MB1242.h"

#include <CrossPlatformI2C.h>

void MB1242::begin(uint8_t address, uint8_t bus)
{
    _addr = cpi2c_open(address, bus);
}

void MB1242::changeAddress(uint8_t oldaddr, uint8_t newaddr)
{
    cpi2c_writeRegister_16_8(oldaddr, 0xAAA5, newaddr<<1); // support seven-bit addressing
}

void MB1242::requestDistance(void)
{
    cpi2c_writeRegister(_addr, 0x00, 0x51);
}

uint16_t MB1242::getDistance(void)
{
    uint16_t tmp = cpi2c_readRegister_8_16(_addr, 0x00);

    // Reverse endianness to get distance
    uint16_t distance = (tmp>>8) | (tmp<<8);

    return distance;

}
