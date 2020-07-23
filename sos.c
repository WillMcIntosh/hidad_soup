/**********************************************************************
* Filename    : sos.c
* Description : Basic usage of GPIO.
* 				It just does morse code for SOS 5 times.
* modification: 2020-07-23
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define LED_PIN 0 // BCM pin 0 is GPIO 17
// set intervals
#define DAH 450
#define DIT 150
#define INNER 100
#define SPACE 300
#define WORD_SPACE 1050

void do_sos(int repeat);
void do_an_s(int led_pin);
void do_an_o(int led_pin);

int main(int argc, char* argv[])
{	
	wiringPiSetup();	//Initialize wiringPi.
	pinMode(LED_PIN, OUTPUT);//Set the pin mode
	
	do_sos(5);
	
	return 0;
}

void do_sos(int repeat)
{
	for (int i = 0; i < repeat; i++)
	{
		printf("S.O.S.\n");
		do_an_s(LED_PIN);
		do_an_o(LED_PIN);
		do_an_s(LED_PIN);
		delay(WORD_SPACE);
    }
}

void do_an_s(int led_pin)
{
	// three dits
	for (int i = 0; i < 3; i++)
	{
		digitalWrite(led_pin, HIGH);
		delay(DIT);
		digitalWrite(led_pin, LOW);
		delay(INNER);
	}
	delay(SPACE);
}

void do_an_o(int led_pin)
{
	// three dahs
	for (int i = 0; i < 3; i++)
	{
		digitalWrite(led_pin, HIGH);
		delay(DAH);
		digitalWrite(led_pin, LOW);
		delay(INNER);
	}
	delay(SPACE);
}

