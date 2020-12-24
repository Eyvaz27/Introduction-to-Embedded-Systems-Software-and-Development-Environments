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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

BASENAME = c1m3
TARGET = $(BASENAME).out

CC = arm-none-eabi-gcc
LINKER_FILE = ./msp432p401r.lds
SIZE = arm-none-eabi-size -Bd
SYMBOL = arm-none-eabi-nm -S
DUMP = arm-none-eabi-objdump #-t -T -r -R
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
ARC_SPCF_FLAGS = -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
LD = arm-none-eabi-gcc-ld
LDFLAGS = -Xlinker -Map=$(BASENAME).map -T$(LINKER_FILE)
CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall
CPPFLAGS = -DMSP432
GENERALFLAGS = \
	-Wall \
  	-Werror \
  	-g \
  	-O0 \
  	-std=c99 \

%.i : %.c
	$(CC) -E $< $(FLAGS) $(ARC_SPCF_FLAGS) $(CPPFLAGS) $(INCLUDES) -o $@

%.asm : %.c
	$(CC) -S $< $(FLAGS) $(ARC_SPCF_FLAGS) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o  $@
%.o : %.c
	$(CC) -c $< $(FLAGS) $(ARC_SPCF_FLAGS) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@
	$(DUMP) -t $@ #-T -r -R -S 
%.d : %.c
	$(CC) -M $< $(FLAGS) $(ARC_SPCF_FLAGS) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@


OBJS = $(SOURCES:.c=.o)
ASMS = $(SOURCES:.c=.asm)
PREPS = $(SOURCES:.c=.i)
DEPENDS = $(SOURCES:.c=.d)

.PHONY: compile-all
compile-all: all_OBJS
.PHONY: all_OBJS
all_OBJS: $(OBJS)

.PHONY: build
build: all_TARGET
.PHONY: all_TARGET
all_TARGET: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(ARC_SPCF_FLAGS) $(CFLAGS) $(FLAGS) $(CPPFLAGS) $(INCLUDES) $(LDFLAGS) -o $@
	$(SIZE) $@
	$(SYMBOL) $@
	#$(DUMP) -t $@ #-T -r -R -S 

.PHONY: clean
clean: 
	rm -f $(TARGET) $(OBJS) $(ASMS) $(PREPS) $(DEPENDS)  $(BASENAME).map 
