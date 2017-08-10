/*
   Header for MaxBotix MB1242 sonar driver

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

class MB1242 {

    private:

        static const int DFLT_ADDR = 0x70;

        int addr;
        int state;
        int distance;
        unsigned int time;

        bool attempt_write(void);

    public:

        void begin(unsigned char address=DFLT_ADDR);

        static void changeAddress(unsigned char oldaddr, unsigned char newaddr);

        int getDistance(void);
};
