#include <gpio.h>



#define   RCC_APB2ENR     (uint32_t*) 0x40021018
#define   Reg_Config_Bouton  (uint32_t*) 0x40010800 //adresse du registre de configuration du port A (relié au bouton)
#define   Reg_Config_Led     (uint32_t*) 0x40011004 // adresse du registre de configuration du Port C (relié aux leds)


uint8_t EtatBouton;

int main ()
{	
	//Activate GPIOs Clocks
 
	 *RCC_APB2ENR  |=  0X14; //Activation de l'horloge du PORT A/C

	//Configure GPIO Pins (Push Button)=PA0:Input Floating Mode
	 *Reg_Config_Bouton &= ~ ( (uint32_t) 0x0F ) ;// Input Floating
	*Reg_Config_Bouton |= 0x04 ;
	//Configure GPIO Pins (LED)=PC9/PC8:Output Push Pull 2 MHZ
  *Reg_Config_Led &= ~((uint32_t) 0xFF) ;
	*Reg_Config_Led |= 0x11;

	
 while (1)
  {		
		//Test Push Button
 		//Read Oush Button State (0=Pressed, 1=Released)
		EtatBouton=GPIO_TestPin(GPIOA,GPIO_PIN_0);
		
	if (EtatBouton==0)  //If Pressed, Led ON	
	GPIO_SetPin(GPIOC, GPIO_PIN_8|GPIO_PIN_9);
	else //Released, Led OFF
	GPIO_ResetPin(GPIOC, GPIO_PIN_8|GPIO_PIN_9);				
}
	}
