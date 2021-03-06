
Arduino/Teensy from the Command Line
====================================

Currently under major construction..... ignore this readme.


A couple of years ago I was looking for a good explanation on using the
command line to compile/upload Arduino code. 
I found bits and pieces but nothing that really explained the whole process.
Much of it was for version 1.0 of the IDE and was out of date.

You can get the general jist of things from the net but many details are
missing; you need the core libraries, the header files, GCC for AVR, avrdude
etc.  

So... I turned on the "Show verbose output during Compile" option
in the Arduino IDE preferences.  Using this as a guide I was able to create 
makefiles to compile the core library and project source code.

Here is the highlevel overview of the process I used:

+ downloaded and install the latest Arduino IDE into my optional package directory
    "/home/john/opt/arduino-1.8.5/"

+ download and install teensy 1.4.1

     https://www.pjrc.com/teensy/td_141/TeensyduinoInstall.linux64

+ copy the Teensy core source and header files into my teensy project source directory

    $ cp -R /home/john/opt/arduino-1.8.5/hardware/teensy/avr/cores/teensy3/ ~/src/teensy/


+ copy the Arduino/Teensy tools (compiler, linker, uploader etc) 

    $ cp -R /home/john/opt/arduino-1.8.5/hardware/tools ~/src/teensy/

+ copy the Teensy core makefile into the teensy3 directory

        $ cp makefile_teensy_core-1.8.5 ~/src/teensy/teensy3/Makefile
        .........and then make the core library

+ The Arduino IDE  compiles the Arduino library on the fly into the tmp
directory.  My approach was to precompile it and save the library in my source
directory. Essentially I copied all the compiler and linker flag into a makefile
that compiles the core source files and combines them into a library.

+ The result of the compile/archive process are installed into "lib" and
"include" directories in my project source directory.

+ Each project has a makefile (copy of makefile_project-18.5) that links to
this core library and the core header files.  This makefile uses the tools
(gcc, g++, objcopy etc) from the local tools directory.

+ I'm not using sketches (.ino) files.  I put my source in cpp files and they
need to include the header files and have a main function. 

```
//
// 2018/03/08 arduinon 1.8.5/teensy 1.4.1 example 

#include <stdio.h>
#include <string.h>
#include "Arduino.h"
// #include "HardwareSerial.h"
// #include <avr/io.h>
// #include <avr/interrupt.h>

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

int main(void)
{
 int i;

    setup();

    // the loop function runs over and over again forever
    while (1) {  
      for (i=0; i<50; i++) {
        digitalWrite(LED_BUILTIN, HIGH);   
        delay(50); 
        digitalWrite(LED_BUILTIN, LOW);   
       delay(155);                      
      }
      
      digitalWrite(LED_BUILTIN, HIGH);   
      delay(500);                      
      digitalWrite(LED_BUILTIN, LOW);    
      delay(2000); digitalWrite(LED_BUILTIN, HIGH);   
      
    } // while
} // main
```


+ I am also using the UNO and MEGA boards so I repeated this process for each board
type.  I keep the source files in seperate source directories 
(/src/uno and src/mega) each with a seperate copy of the library and header 
files.

2018/03/08


Old Notes
---------
    cp ~/opt/arduino-1.8.5/hardware/arduino/avr/variants/standard/pins_arduino.h ~/src/uno/core-1.8.5
    cp /home/john/opt/arduino-1.8.5/hardware/arduino/avr/cores/arduino/* ~/src/uno/core-1.8.5
    Note: I'm using the Arduino Uno so we copy the "standard" pins header file.
          There are other header file for mega/leonardo etc in the variant directory.

Keyboard Notes
--------------
The normal sketch compile is configured to produce a USB serial device.  One of my 
project was to have the teensy be a USB keyboard device.  To do this I had
to change the compiler flags from:
-c -O2 -g -Wall -ffunction-sections -fdata-sections -nostdlib -MMD
 -fno-exceptions -felide-constructors -std=gnu++14 -fno-rtti -mthumb 
 -mcpu=cortex-m4 -fsingle-precision-constant -D__MK20DX256__ 
 -DTEENSYDUINO=141 -DARDUINO=10805 -DF_CPU=96000000
 -DUSB_SERIAL -DLAYOUT_US_ENGLISH 

to 
-c -O2 -g -Wall -ffunction-sections -fdata-sections -nostdlib -MMD
 -fno-exceptions -felide-constructors -std=gnu++14 -fno-rtti -mthumb
 -mcpu=cortex-m4 -fsingle-precision-constant -D__MK20DX256__ 
-DTEENSYDUINO=141 -DARDUINO=10805 -DF_CPU=96000000 
-DUSB_KEYBOARDONLY -DLAYOUT_US_ENGLISH

Notice the only diff is the -DUSB_SERIAL vs -DUSB_KEYBOARDONLY
This need to be changed in the project makefile.
