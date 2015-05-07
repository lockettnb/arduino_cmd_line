
Arduino from the Command Line
=============================
I was net surfing looking for a good explanation on using the
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

+downloaded and install the latest Arduino IDE into my optional package directory
    "home/john/opt/arduino-1.6.1/"

+copied the Arduino core source and header files into my arduino source directory
    cp ~/opt/arduino-1.6.1/hardware/arduino/avr/variants/standard/pins_arduino.h ~/src/uno/core-1.6.1
    cp /home/john/opt/arduino-1.6.1/hardware/arduino/avr/cores/arduino/* ~/src/uno/core-1.6.1
    Note: I'm using the Arduino Uno so we copy the "standard" pins header file.
          There are other header file for mega/leonardo etc in the variant directory.

+ The IDE version 1.6.1 compiles the Arduino library on the fly into the tmp
directory.  My approach was to precompile it and save the library in my source
directory. Essentially I copied all the compiler and linker flag into a makefile
that compiles the core source files and combines them into a library.

+ The result of the compile/archive process are installed into "lib" and
"include" directories in my project source directory.

+ Each project has a makefile (Makefile.prj) that links to this core library and
the core header files.  This makefile still uses the tools (gcc, g++,
objcopy etc) from the Arduino IDE directory. This keep all the tool version
aligned with 1.6.1 of the arduino code.  

+ I an using the UNO and MEGA boards so I repeated this process for each board
type.  I keep the source files in seperate source directories 
(/src/uno and src/mega) each with a seperate copy of the library and header 
files.





Notes from IDE Verbose Output
=============================

ARCHIVE/LIBRARY
===============
~~~~
avr-ar rcs core.a wiring.c.o

avr-ar    archive tool
rcs
    r     Insert the files member... into archive (with replacement) 
    s     Add an index to the archive, or update it if it already exists
    c     Create the archive, is always created if it did not exist
core.a      library to be created
wiring.c.o  object to add to archive
~~~~

 


CPP SKETCH
==========
~~~~
-c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10601 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR 

-I/home/john/opt/arduino-1.6.1/hardware/arduino/avr/cores/arduino
    Arduino.h
    binary.h
    Client.h
    HardwareSerial.h
    HardwareSerial_private.h
    IPAddress.h
    new.h
    Printable.h
    Print.h
    Server.h
    Stream.h
    Udp.h
    USBAPI.h
    USBCore.h
    USBDesc.h
    WCharacter.h
    wiring_private.h
    WString.h

-I/home/john/opt/arduino-1.6.1/hardware/arduino/avr/variants/standard
    pins_arduino.h

Blinky_hi_low.cpp
-o Blinky_hi_low.cpp.o 
~~~~


C PROGRAM COMPILE
=================
~~~~
-c -g -Os -w -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10601 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR
-I/home/john/opt/arduino-1.6.1/hardware/arduino/avr/cores/arduino
-I/home/john/opt/arduino-1.6.1/hardware/arduino/avr/variants/standard
$(CORE)/wiring.c 
-o /wiring.c.o 

CORE = ARDUINO-1.6.1/hardware/arduino/avr/cores/arduino
~~~~

LINKING
=======
~~~~
avr-gcc -w -Os -Wl,--gc-sections -mmcu=atmega328p -o Blinky_hi_low.cpp.elf Blinky_hi_low.cpp.o /tmp/..../core.a -L/tmp.... -lm 

Using the GCC Compiler for linking:
        avr-gcc 

Flags:
    -w -Os -Wl,--gc-sections -mmcu=atmega328p

    -w
        Inhibit all warnings.  (Not sure why they do this)

    -Os
        Optimize for size.
        -Os enables all -O2 optimizations that do not typically increase code size

    -Wl,option
        Pass option as an option to the linker   
        gc-sections enables garbage collection of unused input sections
        This flag do is to ask the linker to get rid of unused sections

    -mmcu=atmega328p
        This option is defined for AVR implementations
        Specify Atmel AVR instruction set architectures (ISA) or MCU type.  
        atmega328p is included in the "avr5" group of “Enhanced” devices
        with 16 KiB up to 64 KiB of program memory. 

Output file is ELF format: 
    -o Blinky_hi_low.cpp.elf

Input Object File:
    Blinky_hi_low.cpp.o

Library to Link (note you need the full path on this):
    .../tmp/core.a

Directories to look in libraries:
-L/tmp/build8686837866046723265.tmp
-lm 
~~~~


CORE C COMPILE EXAMPLE
======================
~~~~~
/home/john/opt/arduino-1.6.1/hardware/tools/avr/bin/avr-gcc -c -g -Os -w -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10601 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -I/home/john/opt/arduino-1.6.1/hardware/arduino/avr/cores/arduino -I/home/john/opt/arduino-1.6.1/hardware/arduino/avr/variants/standard /home/john/opt/arduino-1.6.1/hardware/arduino/avr/cores/arduino/wiring.c -o /tmp/build8686837866046723265.tmp/wiring.c.o 
~~~~~

CORE CPP COMPILE EXAMPLE
========================
~~~~~
/home/john/opt/arduino-1.6.1/hardware/tools/avr/bin/avr-g++ -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10601 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -I/home/john/opt/arduino-1.6.1/hardware/arduino/avr/cores/arduino -I/home/john/opt/arduino-1.6.1/hardware/arduino/avr/variants/standard /home/john/opt/arduino-1.6.1/hardware/arduino/avr/cores/arduino/USBCore.cpp -o /tmp/build8686837866046723265.tmp/USBCore.cpp.o 
~~~~~

LIBRARY EXAMPLE
===============
~~~~~
/home/john/opt/arduino-1.6.1/hardware/tools/avr/bin/avr-ar rcs /tmp/build8686837866046723265.tmp/core.a /tmp/build8686837866046723265.tmp/wiring.c.o 
~~~~~



SKETCH C++ COMPILE EXAMPLE
==========================
~~~~~
/home/john/opt/arduino-1.6.1/hardware/tools/avr/bin/avr-g++ -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10601 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -I/home/john/opt/arduino-1.6.1/hardware/arduino/avr/cores/arduino -I/home/john/opt/arduino-1.6.1/hardware/arduino/avr/variants/standard /tmp/build8686837866046723265.tmp/Blinky_hi_low.cpp -o /tmp/build8686837866046723265.tmp/Blinky_hi_low.cpp.o 
~~~~~

LINKING EXAMPLE
===============
~~~~~
/home/john/opt/arduino-1.6.1/hardware/tools/avr/bin/avr-gcc -w -Os -Wl,--gc-sections -mmcu=atmega328p -o /tmp/build8686837866046723265.tmp/Blinky_hi_low.cpp.elf /tmp/build8686837866046723265.tmp/Blinky_hi_low.cpp.o /tmp/build8686837866046723265.tmp/core.a -L/tmp/build8686837866046723265.tmp -lm 
~~~~~

ELF-to-HEX EXAMPLE
==================
Note sure why they run objcopy twice; once with -j option and once with -R option
~~~~~
/home/john/opt/arduino-1.6.1/hardware/tools/avr/bin/avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 /tmp/build8686837866046723265.tmp/Blinky_hi_low.cpp.elf /tmp/build8686837866046723265.tmp/Blinky_hi_low.cpp.eep 

/home/john/opt/arduino-1.6.1/hardware/tools/avr/bin/avr-objcopy -O ihex -R .eeprom /tmp/build8686837866046723265.tmp/Blinky_hi_low.cpp.elf /tmp/build8686837866046723265.tmp/Blinky_hi_low.cpp.hex 
~~~~~

