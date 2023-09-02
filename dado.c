#include <pic14/pic12f675.h>
 
//To compile:
//sdcc -mpic14 -p12f683 dado.c
 
//To program the chip using picp:
//Assuming /dev/ttyUSB0 is the serial port.
 
//Erase the chip:
//picp /dev/ttyUSB0 12f683 -ef
 
//Write the program:
//picp /dev/ttyUSB0 12f683 -wp dado.hex
 
//Write the configuration words (optional):
//picp /dev/ttyUSB0 12f683 -wc 0x2ff4 0x3fff
 
//Doing it all at once: erasing, programming, and reading back config words:
//picp /dev/ttyUSB0 12f683 -ef -wp dado.hex -rc
 
//To program the chip using pk2cmd:
//pk2cmd -M -PPIC12f683 -Fdado.hex
 
void delay (unsigned inttiempo);
 
void main(void)
{

    TRISIO = 0b00000010;  // Configurar GP0 como entrada (botón), GP1 como salida (LED1), GP2 a GP5 como salidas (otros LEDs)
	GPIO = 0x00; //Poner pines en bajo
 
    unsigned int time = 100;
 
    //Loop forever
    while ( 1 )
    {
			GP0 = 0x00;
			delay(time);

			GP0 = ~GP0;
			delay(time);
    }
 
}

void delay(unsigned int tiempo)
{
	unsigned int i;
	unsigned int j;

	for(i=0;i<tiempo;i++)
	  for(j=0;j<1275;j++);
}
