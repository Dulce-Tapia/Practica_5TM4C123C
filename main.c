#include "lib/include.h"


/* Experimento 3
   Usando el modulo 0 de PWM con una frecuencia de reloj del sistema de 20,000,000 Hz
  junto con el generador 0,1,2  habilitar alguno de los pwm's asociados y obtener un PWM
  cuya frecuencia sea de 500Hz , utilizando el uart se enviara dato desde interfaz de simulink ****
  para controlar la intensidad luminosa usando un led RGB externa  */
 
    volatile uint8_t cR = 82; 
    volatile uint8_t cV = 86; 
    volatile uint8_t cA = 65; 
    volatile uint16_t color;

int main(void)
{
    Configurar_PLL(_20MHZ); 
    Configurar_UART0();
    Configura_Reg_PWM0(8);

    while (1)
    {
        color = readChar();
        
        switch (color)
        {
            case 'V':
                while (cV == 86)
                {
                    
                    cV = (int)readChar();
                }
                PWM0->_2_CMPA = 10000-((int)(cV*5000)/50); //PE4
                cV = 86;
            break;
            case 'R':
                while (cR == 82)
                {
                    cR = (int)readChar();
                }
                PWM0->_0_CMPB = 10000-((int)(cR*5000)/50); //PB7
                cR = 82;
            break;
            case 'A':
                while (cA == 65)
                {
                    cA = (int)readChar();
                }
                PWM0->_1_CMPA = 10000-((int)(cA*5000)/50); //PB4 
                cA = 65;
            break;

        }   
    }
}

