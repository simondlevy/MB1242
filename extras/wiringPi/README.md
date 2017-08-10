This simple example shows how to read from the MaxBotix MB1242 I<sup>2</sup>C
sonar using the WiringPi library.  I have tested it on an ODROID XU4 with
shifter shield.  (Shifter shield voltage is set to 3.3V.)  It should also work
on a RaspberryPi.  I used the following connections:

<ul>
<li> MB1242 GND to Pi pin 6
<li> MB1242 V+ to Pi 1
<li> MB1242 pin 5 (SCL) to Pi 5
<li> MB1242 pin 4 (SDA) to Pi 3
</ul>
