This Arduino library provides a simple API for reading distance in centimeters
from the MaxBotix MB1242 I<sup>2</sup>C sensor.  To run the example, connect
your MB1242 to your Arduino Uno as follows:

<ul>
<li> Arduino GND to MB1242 GND
<li> Arduino 5V power to MB1242 V+
<li> Arduino A5 (SCL) to MB1242 5
<li> Arduino A4 (SDA) to MB1242 4
</ul>

For Teensy 3.2, connect as follows:

<ul>
<li> Teensy GND to MB1242 GND
<li> Teensy 3.3V power to MB1242 V+
<li> Teensy 19 (SCL0) to MB1242 5
<li> Teensy 18 (SDA0) to MB1242 4
</ul>

Then drag the MB1242 folder into your Arduino libraries folder, launch the
Arduino IDE, and look in <b>Examples/MB1242/showdistance</b>.  There is
also an example <b>changeaddress</b> that allows you to change the 
address of the MB1242.  To make sure that you have the correct old address
and can check the new address, use an 
[I<sup>2</sup>C scanner](http://playground.arduino.cc/Main/I2cScanner) program.
