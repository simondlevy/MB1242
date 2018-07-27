<img src="mb1242.jpg">

The [MB1242](http://www.maxbotix.com/Ultrasonic_Sensors/MB1242.htm) 
rangefinder from MaxBotix is an inexpensive I<sup>2</sup>C-based ultrasonic (sonar) sensor that can provide
distances between 20mm and 765mm.  Likes its UART-based MB1240 sibling, it is the sonar unit that MaxBotix
recommends for use on Unmanned Aerial Vehicles.  Because I like to work with this sensor on both Arduino/Teensy
and RaspberryPi/ODROID, I wrote a little library that will allow you to use the MB1242 on either of these
platforms, [CrossPlatformI2C](https://github.com/simondlevy/CrossPlatformI2C), which you will need to clone into
your Arduino/libraries folder as well.

The MB1242 library provides a simple API for reading distance in centimeters
from the MaxBotix MB1242 I<sup>2</sup>C sensor.  To run the example, connect
your MB1242 to your Arduino Uno as follows:

* Arduino GND to MB1242 GND
* Arduino 5V power to MB1242 V+
* Arduino A5 (SCL) to MB1242 5
* Arduino A4 (SDA) to MB1242 4

For Teensy 3.2, connect as follows:

* Teensy GND to MB1242 GND
* Teensy Vin to MB1242 V+
* Teensy 19 (SCL0) to MB1242 5
* Teensy 18 (SDA0) to MB1242 4

Then drag the MB1242 folder into your Arduino libraries folder, launch the
Arduino IDE, and look in <b>Examples/MB1242/showdistance</b>.  There is
also an example <b>changeaddress</b> that allows you to change the 
address of the MB1242.  

For WiringPi, look in the <b>extras/wiringPi</b> folder.
