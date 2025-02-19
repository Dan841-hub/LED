#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

// LED 8개 shift
//int main(void)
//{
   //DDRD = 0xff; // 포트 D를 출력으로 설정
   //
	////while (1) 
    //{
		//for(uint8_t i = 8; i > 0; i--)
		//{
			//PORTD = (0x01 << i);
			//// 0X01 == 0b0000001 << i(0)
			//// 0x01 == 0b0000010 << i(1)
			//// 0x01 == 0b0000100 <<i(2)
			//
			//_delay_ms(50);
		//}
		//
		//for(uint8_t i = 0; i < 8; i++)
		//{
			//PORTD = (0x01 << i);
			//_delay_ms(150);
		//}
    //}
//}


// LED 4개 좌우 양끝 에서 안쪽으로 이동
//
//#define LED_DDR		DDRD		//LED를 위한 포트 방향 레지스터
//#define LED_PORT	PORTD		// LED를 켜고 끄기 위한 포트 레지스터
//
//int main()
//{
		//LED_DDR = 0xFF;
		//
		//while(1)
		//{
			//// LED 양끝에서 안쪽으로 이동
			 //for(uint8_t i = 0; i < 4 ; i++)
			 //{
				 //LED_PORT = ((0x01 << i) | (0x80) >> i);
				 //_delay_ms(100);
			 //}
			//for(uint8_t i = 0 ; i < 4 ; i++)
			//{
				//
				//LED_PORT = (0x08 >>i ) | (0x10 << i );
				//_delay_ms(100);
			//}
		//}
//}

//int main()
//{
	//DDRD = 0xff;
	//unsigned char L = 0x01;
	//unsigned char R = 0x08;
	//
	//while(1)
	//{
		//PORTD = L | R;
		//L <<= 1;  // L = L << 1;
		//if(L == 0)
		//{
			//L = 0x01;
		//}
		//R >>=1;
		//if(R == 0)
		//{
			//
			//R = 0x80;
		//}
		//_delay_ms(300);
	//}
//}

// 함수 및 포인터 이용


#include "LED.h"


int main()
{
	ledInit();
	
	uint8_t ledData = 0x42; // 0b10000001
	
	while(1)
	{
		for(uint8_t i = 0; i < 8; i++)
		{
				ledShift(i,&ledData);
				GPIO_Output((ledData));
				_delay_ms(200);
		}
	}
}
