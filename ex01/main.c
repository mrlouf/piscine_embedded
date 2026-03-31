#include <avr/io.h>
#include <util/delay.h>

int	main( void )
{
   	// Configure PORTB pins 0-7 as outputs (set DDRB to 0xFF)
    DDRB = 0xFF;
    PORTB |= (1 << 0); // Turn on LED on PORTB pin 0

	while (1) {

		// Toggle the state of the LED on PORTB pin 0
		PORTB ^= (1 << 0); // Toggle LED on PORTB pin 0
		_delay_ms(500); // Wait for 500 milliseconds

	};
    
    return (0);
}

 