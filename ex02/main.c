#include <avr/io.h>
#include <util/delay.h>

int	main( void )
{
   	// Configure PORTB pins 0-7 as outputs
    DDRB = 0xFF;
	// Turn on LED on PORTB pin 0
    PORTB |= (1 << 0);

	DDRD = 0x00; // Configure PORTD pins as inputs
	PORTD |= (1 << 2); // Enable pull-up resistor on PORTD pin 0

	static int8_t is_pressed = 1; // Variable to track button state

	while (1) {

		is_pressed = PIND & (1 << 2) ? 0 : 1; // Update button state

		PORTB ^= (1 << 0); // Toggle LED on PORTB pin 0
		if (is_pressed) { // Check if button on PORTD pin 0 is pressed
			PORTB |= (1 << 0); // Turn on LED if button is pressed
		} else {
			PORTB &= ~(1 << 0); // Turn off LED if button is not pressed
		}
		_delay_ms(100); // Delay for debounce

	};
    
    return (0);
}

 