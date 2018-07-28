/*
   Header for MaxBotix MB1242 sonar driver

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

#pragma once

#include <stdint.h>

class MB1242 {

    private:

        uint8_t  _addr;

    public:

        static const uint8_t  DEFAULT_ADDRESS = 0x70;

        void begin(uint8_t address=DEFAULT_ADDRESS, uint8_t bus=1);

        static void changeAddress(uint8_t oldaddr, uint8_t newaddr);

        void requestDistance(void);

        uint16_t getDistance(void);
};
