/*
   ShowDistance.cpp show distances read by MaxBotix MB1242 sonar on Raspberry Pi

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

#include <MB1242.h>
#include <stdio.h>
#include <unistd.h>

static MB1242 sonar;

void setup()
{
    // Start sonar on I^2C bus 0
    sonar.begin(MB1242::DEFAULT_ADDRESS, 0);
}

void loop()
{
    sonar.requestDistance();

    // 100msec delay recommended by https://www.maxbotix.com/documents/I2CXL-MaxSonar-EZ_Datasheet.pdf
    usleep(100000);

    printf("%dcm\n", sonar.getDistance());
}
