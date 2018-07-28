/* 
   main.pp: Generic main() for caling Arduino-style setup(), loop()

   Copyright (c) 2018 Simon D. Levy

   This file is part of MPU9250.

   Library may be used freely and without limit with attribution.
*/

extern void setup(), loop();

int main(int argc, char ** argv)
{
    setup();

    while (true) {
        loop();
    }
}
