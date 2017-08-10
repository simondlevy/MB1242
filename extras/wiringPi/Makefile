# Makefile : builds MB1242_WiringPi example
#
# Copyright (C) Simon D. Levy 2016
#
# This file is part of MB1242_WiringPi.
#
# MB1242_WiringPi is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# MB1242_WiringPi is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with MB1242_WiringPi.  If not, see <http://www.gnu.org/licenses/>.

all: readsonar

run: readsonar
	sudo ./readsonar

readsonar: readsonar.c
	gcc -o readsonar readsonar.c -lwiringPi -lpthread

clean:
	rm -f readsonar

edit:
	vim readsonar.c

sniff:
	sudo i2cdetect -y 4
