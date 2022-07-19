.PHONY: all clean flash

CC = avr-gcc
OBJCOPY = avr-objcopy
MCU = atmega328p
F_CPU = 16000000UL

# Grabador.
AVRDUDE = avrdude

PORT = /dev/ttyACM0
BAUD = 115200
PROTOCOL = arduino
PART = ATMEGA328P

# Variables generales.
AVRDUDEFLAGS = -F -V -c ${PROTOCOL} -p ${PART} -P ${PORT} -b ${BAUD}
CFLAGS += -g
CPPFLAGS += -DF_CPU=${F_CPU}
TARGET_ARCH = -mmcu=${MCU}
COPTFLAG = -Os
CFLAGS += ${COPTFLAG}
WFLAGS += -Wall -Wextra
CFLAGS += ${WFLAGS}
LDFLAGS += ${WFLAGS}
ASFLAGS += ${WFLAGS}

# archivos .c
SRC = main.c UART_utils.c
OBJ = $(SRC_C:.c=.o) 
#$(SRC_s:.s=.o) $(SRC_S:.S=.o)

all: main main.hex

${PROG}: ${OBJ}

%.hex: %
	${OBJCOPY} -O ihex -R .eeprom $< $@

clean:
	rm -f ${PROG} $(addprefix ${PROG}, .elf .hex) ${OBJ}

flash: ${PROG}.hex
	${AVRDUDE} ${AVRDUDEFLAGS} -U flash:w:$<
