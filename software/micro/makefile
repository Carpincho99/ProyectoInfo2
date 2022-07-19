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
INCDIR = inc

TARGET = blink
OBJ = $(addprefix $(BUILDDIR)/,$(notdir $(SOURCE:.c=.o)))

default: compile flash clean

compile:
	$(OBJCOPY) -j .text -j .data -O ihex $(TARGET).elf $(TARGET).hex
	$(SIZE) --format=avr --mcu=$(DEVICE) $(TARGET).elf

flash:
	${DUDE} ${AVRDUDEFLAGS} -U flash:w:$(TARGET).hex

$(BUILDDIR)/%.o: $(SOURCE)/%.c
	$(COMPILE) -c -Wall -std=c99 $< -o $@

$(BUILDDIR)/$(TARGET).elf: $(OBJ)
	$(COMPILE) -o $(BUILDDIR)/$(TARGET).elf $(OBJ) -lm 

clean:
	rm -f $(TARGET).hex 
	rm -f $(BUILDDIR)/*.o 
#rm -f $(BUILDDIR)/*.d 
	rm -f $(BUILDDIR)/*.elf
