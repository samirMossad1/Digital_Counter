
#include "gpio.h"
#include "segment7.h"



int main()
{

	uint8_t counter_units=0x00,counter_tens=0x08;

	GPIO_pinConfigStruct button_increment={PORT_A,PIN_0,_INPUT};

	GPIO_pinConfigStruct button_decrement={PORT_A,PIN_1,_INPUT};

	Segment7_ConfigStruct segment_units={PORT_C,_LEAST};
	Segment7_ConfigStruct segment_tens={PORT_C,_MOST};



	GPIO_pinInit(&button_increment);
	GPIO_pinInit(&button_decrement);
	GPIO_pinPullUpInit(PORT_A,PIN_0);
	GPIO_pinPullUpInit(PORT_A,PIN_1);


	SEGMENT7_init(&segment_units);
	SEGMENT7_init(&segment_tens);


	while(1)
	{


		SEGMENT7_write(PORT_C,_LEAST,counter_units);
		SEGMENT7_write(PORT_C,_MOST,counter_tens);




		if(!(GPIO_readPin(PORT_A,PIN_0)))
			{

				_delay_ms(20);

				if(!(GPIO_readPin(PORT_A,PIN_0)))
				{


				if(counter_units==0x09)
				{
					counter_units=0;

					if(counter_tens==0x09)
					{
					counter_tens=0x00;
					}
					else
					{
					counter_tens++;
					}
				}
				else
				{
				counter_units++;
				}

				while(!(GPIO_readPin(PORT_A,PIN_0)));

				}

			}




		if(!(GPIO_readPin(PORT_A,PIN_1)))
					{

						_delay_ms(20);

						if(!(GPIO_readPin(PORT_A,PIN_1)))
						{


						if(counter_units==0x00)
						{


							if(counter_tens==0x00)
							{
							counter_units=0x00;
							counter_tens=0x00;
							}
							else
							{
								counter_units=0x09;
								counter_tens--;

							}

						}
						else
						{
						counter_units--;
						}

						while(!(GPIO_readPin(PORT_A,PIN_1)));

						}

					}





	}




return 0;
}
