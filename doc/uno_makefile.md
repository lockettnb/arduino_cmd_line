UNO Makefile for Arduino 1.8.8
==============================
2019/03/18

Turned on verbose output for IDE environment to record build process.
From this output we can review the flags and options for compile of 
.S .c and .cpp files.



Assembler Flags
---------------
common:     -c -g
asm only:   -x assembler-with-cpp
common:     -flto -MMD -mmcu=atmega328p
options:     -DF_CPU=16000000L -DARDUINO=10808 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR

include:    -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/cores/arduino
include:    -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/variants/standard

C Flags
-------
common:     -c -g
cc common:  -Os -w
c only:     -std=gnu11
cc common:   -ffunction-sections -fdata-sections
common:     -MMD -flto -mmcu=atmega328p 
c only:     -fno-fat-lto-objects 
options:     -DF_CPU=16000000L -DARDUINO=10808 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR

include:    -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/cores/arduino
include:    -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/variants/standard

C++ Flags
---------
common:     -c -g
cc common:  -Os -w
c++ only:   -std=gnu++11 -fpermissive -fno-exceptions
cc common:  -ffunction-sections -fdata-sections
c++ only:   -fno-threadsafe-statics -Wno-error=narrowing
common:     -MMD -flto -mmcu=atmega328p
options:     -DF_CPU=16000000L -DARDUINO=10808 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR

include:    -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/cores/arduino
include:    -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/variants/standard 

Final Results
-------------
OPTIONS = -DF_CPU=16000000L -DARDUINO=10808 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR
CPPFLAGS =  -c -g -MMD -flto -mmcu=atmega328p -Os -w -ffunction-sections -fdata-sections
CFLAGS = -std=gnu11 -fno-fat-lto-objects
CXXFLAGS = -std=gnu++11 -fpermissive -fno-exceptions -fno-threadsafe-statics -Wno-error=narrowing
ASFLAGS =  -c -g -MMD -flto -mmcu=atmega328p -x assembler-with-cpp


The Gory Details
----------------
Here are the details of each compile/build

ASSEMBLER
/home/john/opt/arduino-1.8.8/hardware/tools/avr/bin/avr-gcc -c -g -x assembler-with-cpp -flto -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10808 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/cores/arduino -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/variants/standard /home/john/opt/arduino-1.8.8/hardware/arduino/avr/cores/arduino/wiring_pulse.S -o /tmp/arduino_build_258357/core/wiring_pulse.S.o

FLAGS :: -c -g -x assembler-with-cpp -flto -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10808 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/cores/arduino -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/variants/standard 



C PROGRAM
/home/john/opt/arduino-1.8.8/hardware/tools/avr/bin/avr-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10808 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/cores/arduino -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/variants/standard /home/john/opt/arduino-1.8.8/hardware/arduino/avr/cores/arduino/WInterrupts.c -o /tmp/arduino_build_258357/core/WInterrupts.c.o

FLAGS :: -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10808 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/cores/arduino -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/variants/standard


CPP PROGRAM
/home/john/opt/arduino-1.8.8/hardware/tools/avr/bin/avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10808 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/cores/arduino -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/variants/standard /home/john/opt/arduino-1.8.8/hardware/arduino/avr/cores/arduino/Print.cpp -o /tmp/arduino_build_258357/core/Print.cpp.o

FLAGS :: -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10808 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/cores/arduino -I/home/john/opt/arduino-1.8.8/hardware/arduino/avr/variants/standard 



LINKER FLAGS

/home/john/opt/arduino-1.8.8/hardware/tools/avr/bin/avr-gcc -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p -o /tmp/arduino_build_258357/sketch_foo.ino.elf /tmp/arduino_build_258357/sketch/sketch_foo.ino.cpp.o /tmp/arduino_build_258357/core/core.a -L/tmp/arduino_build_258357 -lm

-w -Os -g
-flto -fuse-linker-plugin 
-Wl,--gc-sections -mmcu=atmega328p 
<out file> -o /tmp/arduino_build_258357/sketch_foo.ino.elf
<in file>/tmp/arduino_build_258357/sketch/sketch_foo.ino.cpp.o
<library> /tmp/arduino_build_258357/core/core.a
<lib directory> -L/tmp/arduino_build_258357
<library> -lm



OBJECT COPY FLAGS (ELF --> EEP)
/home/john/opt/arduino-1.8.8/hardware/tools/avr/bin/avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 /tmp/arduino_build_258357/sketch_foo.ino.elf /tmp/arduino_build_258357/sketch_foo.ino.eep

-O ihex
-j .eeprom 
--set-section-flags=.eeprom=alloc,load
--no-change-warnings
--change-section-lma .eeprom=0
<in  file> /tmp/arduino_build_258357/sketch_foo.ino.elf
<out file> /tmp/arduino_build_258357/sketch_foo.ino.eep


OBJECT COPY FLAGS (ELF --> HEX)
/home/john/opt/arduino-1.8.8/hardware/tools/avr/bin/avr-objcopy -O ihex -R .eeprom /tmp/arduino_build_258357/sketch_foo.ino.elf /tmp/arduino_build_258357/sketch_foo.ino.hex

-O ihex
-R .eeprom
<in  file> /tmp/arduino_build_258357/sketch_foo.ino.elf
<out file> /tmp/arduino_build_258357/sketch_foo.ino.hex


SIZE OF ELF
/home/john/opt/arduino-1.8.8/hardware/tools/avr/bin/avr-size -A /tmp/arduino_build_258357/sketch_foo.ino.elf

-A /tmp/arduino_build_258357/sketch_foo.ino.elf




Review of the Flags 
====================

-w  
Inhibit all warning messages.

-Wall  
enables all compilers warning messages


-c  
Compile or assemble the source files, but do not link. The linking stage
simply is not done. The ultimate output is in the form of an object file for
each source file. 

-D name=definition  
The contents of definition are tokenized and processed as if they appeared
during translation phase three in a ‘#define’ directive. In particular, the
definition is truncated by embedded newline characters. 

-O2  
GCC performs nearly all supported optimizations that do not
involve a space-speed trade-off. The compiler does not perform loop unrolling or
function inlining when you specify -O2. As compared to -O, this option
increases both compilation time and the performance of the generated code. 

-Os  
Optimize for size. -Os enables all -O2 optimizations that do not typically
increase code size. It also performs further optimizations designed to reduce
code size.
    -Os disables the following optimization flags:
              -falign-functions  -falign-jumps  -falign-loops 
              -falign-labels  -freorder-blocks  -freorder-blocks-and-partition 
              -fprefetch-loop-arrays  -ftree-vect-loop-version

-g  
Produce debugging information in the operating system’s native format (stabs,
COFF, XCOFF, or DWARF). GDB can work with this debugging information. 

-ffunction-sections  
By default every functions are combined into single .text function. With this
flag the compiler creates different text section for each function.
Generates a separate ELF section for each function in the source file. The
unused section elimination feature of the linker can then remove unused
functions at link time.

-fdata-sections, -fno-data-sections  
By default variables belongs .data are combined into single .data function.
With this flag the compiler creates different .data section for each.

The unused section elimination feature of the linker can then remove unused
functions at link time.

-nostdlib  
Do not use the standard system startup files or libraries when linking. No
startup files and only the libraries you specify are passed to the linker, and
options specifying linkage of the system libraries, such as -static-libgcc or
-shared-libgcc, are ignored. 
The compiler may generate calls to memcmp, memset, memcpy and memmove. These
entries are usually resolved by entries in libc. These entry points should be
supplied through some other mechanism when this option is specified. 
-nostdlib is disabled by default.

-MMD  
Generate a dependency output file. Like -MD except mention only user header
files, not system header files.
        -MD..
        Used to generate a dependency output file (with a suffix of
        .d) as a side effect of the compilation process
        -M..
        output a rule suitable for make describing the dependencies
        of the main source file.  The preprocessor outputs one make
        rule containing the object file name for that source file, a
        colon, and the names of all the included files, including
        those coming from -include or -imacros command-line options. 

-mthumb  
-marm  
Select between generating code that executes in ARM and Thumb states. The
default for most configurations is to generate code that executes in ARM state,
but the default can be changed by configuring GCC with the --with-mode=state
configure option. 

-mcpu=name[+extension…]  
This specifies the name of the target ARM processor. GCC uses this name to
derive the name of the target ARM architecture (as if specified by -march) and
the ARM processor type for which to tune for performance (as if specified by
-mtune). Where this option is used in conjunction with -march or -mtune, those
options take precedence over the appropriate part of this option. 

-mfloat-abi=hard  
Specifies which floating-point ABI to use. Permissible values are: ‘soft’,
‘softfp’ and ‘hard’.
Specifying ‘soft’ causes GCC to generate output containing library calls for
floating-point operations. ‘softfp’ allows the generation of code using
hardware floating-point instructions, but still uses the soft-float calling
conventions. ‘hard’ allows generation of floating-point instructions and uses
FPU-specific calling conventions.

-mfpu=fpv4-sp-d16  
This specifies what floating-point hardware is available on the target.

-fsingle-precision-constant  
Causes floating-point constants to be loaded in
single precision even when this is not exact. This avoids promoting operations
on single precision variables to double precision like in x + 1.0/3.0. Note that
this also uses single precision constants in operations on double precision
variables. This can improve performance due to less memory traffic.


\pagebreak

--fexceptions, -fno-exceptions  
Command-line options that is only meaningful for C++ programs. 
Enables or disables the generation of code needed to support C++ exceptions.
Compiling with -fno-exceptions disables exceptions support and uses the variant
of C++ libraries without exceptions. Use of try, catch, or throw results in an
error message.

-felide-constructors  
Command-line options that is only meaningful for C++ programs. 
Elide constructors when this seems plausible. 
The default behavior (-fno-elide-constructors) is specified by the draft ANSI
C++ standard. If your programs constructors have side effects,
`-felide-constructors can change your programs behavior, since some
constructor calls may be omitted.

std=gnu++14  
GCC supports the original ISO C++ standard published in 1998, and the 2011 and
2014 revisions.  By default, GCC also provides some additional extensions to the
C++ language that on rare occasions conflict with the C++ standard. You may also
select an extended versionof the C++ language explicitly with -std=gnu++14 (for
C++14 with GNU extensions).  The default, if no C++ language dialect options are
given, is -std=gnu++14. 

-fno-rtti  
Command-line options that is only meaningful for C++ programs. 
Disable generation of information about every class with virtual functions for
use by the C++ runtime type identification features (dynamic_cast and
typeid). If you donot use those parts of the language, you can save some space
by using this flag. Note that exception handling uses the same information, but
it will generate it as needed. 


\pagebreak

LINKER FLAGS
------------

-O2 vs -Os  
-O2  nearly all supported optimizations that do not involve a space-speed
     tradeoff 
-Os Optimize for size. -Os enables all -O2 optimizations that do not typically
    increase code size. 

-Wl,option  
Pass option as an option to the linker. If option contains commas, it is split
into multiple options at the commas.

--gc-sections  
This tells linker to remove unused sections.

--relax  
An option with machine dependent effects. This option is only supported on a few
targets.  On some platforms, the '--relax' option performs global optimizations
that become possible when the linker resolves addressing in the program On
platforms where this is not supported, '--relax' is accepted, but ignored. 

--defsym=__rtc_localtime=
defsym symbol=expression creates a global symbol in the output file.
The teensy firmware uses __rtc_localtime to initialize the RTC.
This only ever gets used if you have added the 32.768 kHz RTC crystal, and even
then, only if the RTC is found to be uninitialized.
The arduino IDE sets this value, a makefile will need a script to do this.

~~~~
        TS = $(shell date +%s)
        --defsym=__rtc_localtime=$(TS)
~~~~


-T script  
Use script as the linker script. This option is supported by most systems using
the GNU linker. On some targets, such as bare-board targets without an
operating system, the -T option may be required when linking to avoid
references to undefined symbols.


-L  
looks in directory for library files.

-l  
links with a library file.

-lstdc++  
The flag -l<library> simply specifies that the library <library> should be
searched when linking. Since we are using arm-none-eabi-gcc, I assume this will
use the stdc++ lib in the
~/opt/arduino-1.8.8/hardware/tools/arm/arm-none-eabi/lib directory.

-mthumb  
-mcpu=$(CPUARCH)  
-mfloat-abi=hard  
-mfpu=fpv4-sp-d16  
-fsingle-precision-constant  
See the common (CPPFLAGS) flags for description.

