/*
 * LED.c
 *
 * Created: 2025-02-18 오후 4:01:08
 *  Author: USER
 */ 

#include "LED.h" // LED H 라는 파일에 있는값을 불러올거야

void ledInit()
{
	LED_DDR = 0xff;
}

void GPIO_Output(uint8_t data)
{
	LED_PORT = data;
}

void ledShift(uint8_t i, uint8_t *data)
{
	*data = (1<<i) | (1<<(7-i));
}