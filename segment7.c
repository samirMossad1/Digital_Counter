
#include "segment7.h"


static void GPIO_halfPortInit(const GPIO_PORT,const SEGMENT7_PORTPINS);
static void	GPIO_writeHalfPort(const GPIO_PORT,const SEGMENT7_PORTPINS,const uint8_t);


bool SEGMENT7_init(const Segment7_ConfigStruct* Struct_ptr)
{
	if(Struct_ptr==NULL_PTR) return FALSE;

	GPIO_halfPortInit(Struct_ptr->PORT,Struct_ptr->PINS);

	return TRUE;
}


void SEGMENT7_write(const GPIO_PORT PORT,const SEGMENT7_PORTPINS PINS,const uint8_t data)
{


	GPIO_writeHalfPort(PORT,PINS,data);


}




static void GPIO_halfPortInit(const GPIO_PORT PORT,const SEGMENT7_PORTPINS PINS)
{

		switch(PORT)
		{

		case PORT_A:
			GPIO_PORTA_DIRECTION_REGISTER|=(PINS==_LEAST)?0X0F:0XF0;
			break;

		case PORT_B:
			GPIO_PORTB_DIRECTION_REGISTER|=(PINS==_LEAST)?0X0F:0XF0;
			break;

		case PORT_C:
			GPIO_PORTC_DIRECTION_REGISTER|=(PINS==_LEAST)?0X0F:0XF0;
			break;

		case PORT_D:
			GPIO_PORTD_DIRECTION_REGISTER|=(PINS==_LEAST)?0X0F:0XF0;
			break;
		}

}


static void	GPIO_writeHalfPort(const GPIO_PORT PORT,const SEGMENT7_PORTPINS PINS, const uint8_t data)
{
		uint8_t clear_mask=0x0F,shift_mask=PINS*4;

		if(PINS==_LEAST)
		{
			clear_mask=0xF0;
		}
	switch(PORT)
		{
			case PORT_A: GPIO_PORTA_OUTPUT_REGISTER=((GPIO_PORTA_OUTPUT_REGISTER & clear_mask ) | (data<<shift_mask));
						   	   break;
			case PORT_B: GPIO_PORTB_OUTPUT_REGISTER=((GPIO_PORTB_OUTPUT_REGISTER & clear_mask ) | (data<<shift_mask));
							   break;
			case PORT_C: GPIO_PORTC_OUTPUT_REGISTER=((GPIO_PORTC_OUTPUT_REGISTER & clear_mask ) | (data<<shift_mask));
							   break;
			case PORT_D: GPIO_PORTD_OUTPUT_REGISTER=((GPIO_PORTD_OUTPUT_REGISTER & clear_mask ) | (data<<shift_mask));
							   break;
		}
}
