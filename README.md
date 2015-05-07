
Arduino from the Command Line
=============================
I've been  net surfing looking for a good explanation on using the
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


