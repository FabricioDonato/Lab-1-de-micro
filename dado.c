#include <pic14/pic12f683.h>

 
void delay (unsigned inttiempo);
 

// Función de inicialización
void main() {
    // Configurar pines como entrada/salida
    TRISIO = 0b00000001;  // Configurar GP0 como entrada (botón), GP1 como salida (LED1), GP2 a GP5 como salidas (otros LEDs)
    GPIO = 0x00; //Poner pines en bajo
   
    
    //contador para hacerlo random
    unsigned int counter = 0;
    unsigned int time = 1000;
    
    //loop
    while (1) {
    	counter++;
	if (counter == 100){
		counter = 0;
	}
		
        if (GP0 == 0) {  // Si el botón está presionado (estado bajo)
            // Realiza la acción deseada cuando se presiona el botón
            unsigned int dado = (counter % 6) + 1; // Utilizar la función de ruido
            if (dado == 1){
            	GP2 = 0x01;
		delay(time);
		GP2 = ~GP2;
            }
            else if (dado == 2){
            	GP1 = 0x01;
		delay(time);
		GP1 = ~GP1;
		
            }
            else if (dado == 3){
            	GP1 = 0x01;            	
            	GP2 = 0x01;
		delay(time);
		GP1 = ~GP1;
		GP2 = ~GP2;
            }
            else if (dado == 4){
            	GP1 = 0x01;
            	GP4 = 0x01;
            	
		delay(time);
		GP1 = ~GP1;
            	
            	GP4 = ~GP4;
            }
            else if (dado == 5){
            	GP1 = 0x01;
            	GP2 = 0x01;
            	
            	GP4 = 0x01;
		delay(time);
		GP1 = ~GP1;
		GP2 = ~GP2;
		
		GP4 = ~GP4;
            }
            else if (dado == 6){
            	GP1 = 0x01;
            	GP2 = 0x01;
            	
            	GP4 = 0x01;
            	GP5 = 0x01;
		delay(time);
            	GP1 = ~GP1;
		GP2 = ~GP2;
		
		GP4 = ~GP4;
		GP5 = ~GP5;
            }
            // Esperar a que se suelte el botón
            while (GP0 == 0);
        }
    }

	


}


void delay(unsigned int tiempo)
{
	unsigned int i;
	unsigned int j;

	for(i=0;i<tiempo;i++)
	  for(j=0;j<1275;j++);
}
