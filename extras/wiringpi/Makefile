# Makefile for MB1242 WiringPi examples
#
# Copyright (c) 2018 Simon D. Levy
#
# This file is part of MB1242.
#
# MB1242 is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# MB1242 is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with MB1242.  If not, see <http://www.gnu.org/licenses/>.
# This file is part of MB1242.
#
# Library may be used freely and without limit with attribution.
#  
# Change this to whereever you installed CrossPlatformDataBus
CPDB = $(HOME)/CrossPlatformDataBus/

ALL = ShowDistance

MBSRC = ../../src

CPSRC  = $(CPDB)/src
CPEXT  = $(CPDB)/extras
I2CSRC = $(CPDB)/extras/i2c/wiringpi/src

all: $(ALL)

ShowDistance: ShowDistance.o MB1242.o WiringPiI2C.o main.o
	g++ -std=c++11 -o ShowDistance ShowDistance.o MB1242.o WiringPiI2C.o main.o -lwiringPi

ShowDistance.o: ShowDistance.cpp 
	g++ -std=c++11 -Wall -I$(CPSRC) -I$(MBSRC) -c ShowDistance.cpp

MB1242.o: $(MBSRC)/MB1242.cpp  $(MBSRC)/MB1242.h
	g++ -std=c++11 -Wall -I$(CPSRC) -I$(MBSRC) -c $(MBSRC)/MB1242.cpp

WiringPiI2C.o: $(I2CSRC)/WiringPiI2C.cpp 
	g++ -std=c++11 -Wall -I$(CPSRC) -c $(I2CSRC)/WiringPiI2C.cpp

main.o: $(CPEXT)/main.cpp 
	g++ -std=c++11 -Wall -c $(CPEXT)/main.cpp

edit:
	vim ShowDistance.cpp

clean:
	rm -f $(ALL) *.o *~
