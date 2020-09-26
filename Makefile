#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************
#------------------------------------------------------------------------------
# Dual platform Makefile tha supports a host environment (LINUX) and the
# target embedded system MSP432 (ARM).
#
# Use: make build PLATFORM=MSP432
#      make build PLATFORM=HOST
#
# Build Targets:
#      <FILE>.o: Generates the object file for all c-source files (but do not 
#       	 link) by specifying the object file you want to compile.
#      <FILE>.i: Generates the preprocessed output of all c-program
#      		 implementation files.
#      <FILE>.asm: Generates assembly output of c-program implementation files 
#      		and the final output executable.
#      <FILE>.d: Generates dependency files for each source file.
#      compile-all: compiles all sources into output files <FILE>.o.
#      build: Compiles all object files and link into a final executable.
#      clean: Removes all compiled objects, preprocessed outputs, assembly
#      		 outputs, executable files and build output files.
#Platform Overrides:
#      CPU -  ARM Cortex Architecture(cortex-m4)                               
#      ARCH - ARM Architecture (thumb)                                         
#      SPECS - Specs file to give the linker (nosys.specs) 
#
#------------------------------------------------------------------------------
include sources.mk

ifeq ($(PLATFORM),MSP432)
		CC = arm-none-eabi-gcc
		LD = arm-none-eabi-ld
		LINKER_FILE = ../msp432p401r.lds
		LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
		CPU = cortex-m4
		ARMFLAGS = -mcpu=$(CPU) -mthumb -march=armv7e-m -mfloat-abi=hard\
			   -mfpu=fpv4-sp-d16 --specs=nosys.specs
		OBJDUMP = arm-none-eabi-objdump
		SIZE = arm-none-eabi-size
else
		CC = gcc
		LD = ld
		LDFLAGS = -Wl,-Map=$(TARGET).map 
		OBJDUMP = objdump
		SIZE = size
endif

TARGET = c1m2
CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM) $(ARMFLAGS) 
CPPFLAGS = -E

OBJS = $(SOURCES:.c=.o)
PREPRO = $(SOURCES:.c=.i)
ASMS = $(SOURCES:.c=.asm)
DEPS = $(SOURCES:.c=.d)

all: build

$(TARGET).out : $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS) $(CFLAGS)
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out

%.o : %.c
	$(CC) -o $@ -c $< $(INCLUDES) $(CFLAGS)

%.i : %.c
	$(CC) -o $@ $< $(INCLUDES) $(CFLAGS) $(CPPFLAGS)

%.asm : %.c
	$(CC) -o $@ -S $< $(INCLUDES) $(CFLAGS)

$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) --disassemble $< > $@

%.d : %.c
	$(CC) -o $@ -M $< $(INCLUDES) $(CFLAGS)


.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(DEPS) $(TARGET).out   

.PHONY: info
info: 
	$(info $(SOURCES))
	$(info $(INCLUDES))

.PHONY: clean
clean: 
	rm -f $(TARGET).out $(OBJS) $(ASMS) $(PREPRO) $(DEPS) $(TARGET).asm \
		$(TARGET).map


























