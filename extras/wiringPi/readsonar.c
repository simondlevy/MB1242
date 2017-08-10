/*
 readsonar.c : MB1242_WiringPi example

 Copyright (C) Simon D. Levy 2016

 This file is part of MB1242_WiringPi.

 MB1242_WiringPi is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 MB1242_WiringPi is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with MB1242_WiringPi.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <wiringPiI2C.h>
#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Updates a timed task
static bool check_and_update_timed_task(unsigned long * usec, uint32_t period) 
{
    bool result = (int32_t)(micros() - *usec) >= 0;

    if (result)
        *usec = micros() + period;

    return result;
}

int main(int argc, char ** argv)
{
    // Connect to MB1242 at seven-bit address 0x70
    int fd = wiringPiI2CSetup (0x70);

    if (fd < 0) {
        perror("");
        exit(1);
    }

    // Initialize a timed task to wait a fixed period between request and read
    unsigned long tasktime = micros();

    int count = 0;

    while (true) 

        // Wait 50000 microseconds between request and read
        if (check_and_update_timed_task(&tasktime, 100000)) {

            // Read two-byte value from the MB1242
            uint16_t tmp = wiringPiI2CReadReg16 (fd, 0x8F);

            // Reverse endianness to get distance
            int16_t distance_cm = (tmp>>8) | (tmp<<8);

            printf("%d\n", distance_cm);

            // Make a new request
            wiringPiI2CWriteReg8 (fd, 0x00, 0x51) ;
        }

    return 0;
}
