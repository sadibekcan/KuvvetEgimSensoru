/*
 * KuvvetEgimSensor.c
 *
 * Created: 21.02.2022 13:12:25
 *  Author: sadib
 */ 


#include <avr/io.h>
#include "adc.h"
#include "ser_il.h"
#include <util/delay.h>

int main(void)
{
	int kosPin;
	int kosReading;
	
	adc_yukle();
	seri_yukle(16,19200);
	
    while(1)
    {
		kosReading =adc_oku(0);
		kosPin = kosReading;	
		printf("Analog deger = %i ",kosReading);
		if (kosReading < 10)
		{
			printf("eðim yok");
		}
		else if (kosReading < 200)
		{
			printf("hafif dokunma");
		}
		else if (kosReading < 500)
		{
			printf("hafif sikma");
		}
		else if (kosReading < 800)
		{
			printf("orta derece sikma");
		}
		else {
			printf("büyük sikma");
		}
		_delay_ms(1000);
    }
}