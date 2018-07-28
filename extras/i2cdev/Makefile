# 
# Makefile for MB1242 i2cdev examples
#
# Copyright (c) 2018 Simon D. Levy
#
# This file is part of MB1242.
#
# MB1242 is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# MB1242 is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with MB1242.  If not, see <http://www.gnu.org/licenses/>.

# Change this to whereever you installed CrossPlatformI2C
CPI2C = $(HOME)/CrossPlatformI2C/
  
ALL = ShowDistance

MBSRC = ../../src

all: $(ALL)

I2CINC = $(CPI2C)/src
I2CSRC = $(CPI2C)/extras/i2cdev/src

ShowDistance: ShowDistance.o MB1242.o I2CDevI2C.o main.o
	g++ -std=c++11 -o ShowDistance ShowDistance.o MB1242.o I2CDevI2C.o main.o 

ShowDistance.o: ShowDistance.cpp 
	g++ -std=c++11 -Wall -I$(I2CINC) -I$(MBSRC) -c ShowDistance.cpp

MB1242.o: $(MBSRC)/MB1242.cpp 
	g++ -std=c++11 -Wall -I$(I2CINC) -I$(MBSRC) -c $(MBSRC)/MB1242.cpp

I2CDevI2C.o: $(I2CSRC)/I2CDevI2C.cpp 
	g++ -std=c++11 -Wall -I$(I2CINC) -c $(I2CSRC)/I2CDevI2C.cpp

main.o: main.cpp 
	g++ -std=c++11 -Wall -c main.cpp

run: ShowDistance
	./ShowDistance

edit:
	vim ShowDistance.cpp

clean:
	rm -f $(ALL) *.o *~
