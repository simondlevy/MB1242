<img src="mb1242.jpg">

The [MB1242](http://www.maxbotix.com/Ultrasonic_Sensors/MB1242.htm) 
rangefinder from MaxBotix is an inexpensive I<sup>2</sup>C-based ultrasonic (sonar) sensor that can provide
distances between 20mm and 765mm.  Likes its UART-based MB1240 sibling, it is the sonar unit that MaxBotix
recommends for use on Unmanned Aerial Vehicles.  Because I like to work with
this and others sensors on a variety of platforms (Android, RasperryPi, NVIDIA Jetson), I've written
a little library that will allow you to use the MB1242 on any of these
platforms, [CrossPlatformI2C](https://github.com/simondlevy/CrossPlatformI2C), which you will need to clone into
your Arduino/libraries folder as well.

The MB1242 library provides a simple API for reading distance in centimeters
from the MaxBotix MB1242 I<sup>2</sup>C sensor.  Although the datasheet for this sensor
indicates an operating voltage of 3-5.5V, I've had the most success with it by powering the
microcontroller from an external power supply.
