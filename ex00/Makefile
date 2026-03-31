CC		= avr-gcc
OBJCOPY	= avr-objcopy

MCU		= atmega328p
F_CPU	= 16000000UL
PORT	= /dev/ttyACM0
BAUD	= 115200
PROGRAMMER	= arduino

CFLAGS	= -mmcu=$(MCU) -DF_CPU=$(F_CPU) -lm

BIN		= main.bin
HEX		= main.hex

all: hex flash

hex:
	$(CC) $(CFLAGS) main.c -o $(BIN)
	$(OBJCOPY) -O ihex -R .eeprom $(BIN) $(HEX)

flash: $(HEX)
	avrdude -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -D -U flash:w:$(HEX):i

clean:
	rm -f $(BIN) $(HEX)

.PHONY: all hex flash clean
