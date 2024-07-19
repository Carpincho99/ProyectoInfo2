.PHONY: default compile flash clean

PORT = /dev/ttyACM0
BAUD = 115200
PROTOCOL = arduino
DEVICE = atmega328p

CC = gcc
OBJCOPY = avr-objcopy
SIZE = avr-size
DUDE = avrdude
AVRDUDEFLAGS = -F -V -c ${PROTOCOL} -p ${DEVICE} -P ${PORT} -b ${BAUD}
COMPILE = avr-gcc -Wall -Os -I$(INCDIR) -mmcu=$(DEVICE) -DF_CPU=16000000

BUILDDIR = build
SOURCE = src
SOURCE_FILES = $(notdir $(wildcard $(SOURCE)/*.c))
INCDIR = inc

TARGET = main
OBJ = $(addprefix $(BUILDDIR)/,$(SOURCE_FILES:.c=.o))

default: compile flash clean 

compile: $(BUILDDIR)/$(TARGET).elf
	# @echo "compilando .elf -> .hex"
	$(OBJCOPY) -j .text -j .data -O ihex $(BUILDDIR)/$(TARGET).elf $(BUILDDIR)/$(TARGET).hex
	$(SIZE) --format=avr --mcu=$(DEVICE) $(BUILDDIR)/$(TARGET).elf

flash:
	${DUDE} ${AVRDUDEFLAGS} -U flash:w:$(BUILDDIR)/$(TARGET).hex

$(OBJ): $(BUILDDIR)/%.o: $(SOURCE)/%.c
	# @echo "compilando .c -> .o"
	$(COMPILE) -c -Wall -std=c99 $< -o $@

$(BUILDDIR)/$(TARGET).elf: $(OBJ)
	# @echo "compilando $(TARGET).c -> .elf"
	$(COMPILE) -o $(BUILDDIR)/$(TARGET).elf $(OBJ) -lm 

clean:
	rm -f $(TARGET).hex 
	rm -f $(BUILDDIR)/*.o
	rm -f $(BUILDDIR)/*.elf
