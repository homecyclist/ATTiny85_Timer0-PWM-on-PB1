/*
 * PWM Generation with Timer0
 *
 * This is an example for setting Timer0 to generate a PWM signal with an adjustable duty cycle.
 */ 
#define F_CPU 16000000

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>

void timer0_pwm(void)
{
	/*
	This timer will generate a 32KHz PWM signal to COM0B1.
	*/
	TCCR0A	= (1<<WGM00);	//Fast PWM, Phase Correct.
	TCCR0A |= (1<<COM0B1);	//Toggle OC0B(PB1) on BOTTOM
	TCCR0B	= (1<<CS00);	//F_CPU / 1
	OCR0B	= 64;			//Duty Cycle, 0-255
}

int main(void)
{
	DDRB |= (1<<DDB1);
	timer0_pwm();
    while(1)
    {
		// Something to set OCR0B (duty cycle) in response to something. 
    }
}