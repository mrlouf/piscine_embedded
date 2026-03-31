#include <avr/io.h>
#include <util/delay.h>

#include <stdlib.h>

int	main( void )
{
   	// Configure PORTB pins 0-7 as outputs
    DDRB = 0xFF;
	// Turn on LED on PORTB pin 0
    PORTB |= (1 << 0);

	DDRD = 0x00; // Configure PORTD pins as inputs
	PORTD |= (1 << 0); // Enable pull-up resistor on PORTD pin 0

	while (1) {

		PORTB ^= (1 << 0); // Toggle LED on PORTB pin 0
		if (PIND & (1 << 0)) { // Check if button on PORTD pin 0 is pressed
			PORTB |= (1 << 0); // Turn on LED if button is pressed
		} else {
			PORTB &= ~(1 << 0); // Turn off LED if button is not pressed
		}
		_delay_ms(100); // Delay for debounce
	};
    
/*     // Seed random number generator (use a timer or fixed value)
    uint16_t seed = 12345;
    srand(seed);

    while (1) {
        // Generate random pattern for LEDs
        uint8_t random_pattern = rand() % 16; // Random value 0-15
        
        // Clear all LEDs first
        PORTB = 0x00;
        
        // Set LEDs based on random pattern bits
        if (random_pattern & 0x01) PORTB |= (1 << 0);
        if (random_pattern & 0x02) PORTB |= (1 << 1);
        if (random_pattern & 0x04) PORTB |= (1 << 2);
        if (random_pattern & 0x08) PORTB |= (1 << 4);
        
        // Random delay between 100-500ms
        _delay_ms(100 + (rand() % 400));
    } */
    
    return (0);
}

 