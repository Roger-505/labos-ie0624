#include <pic14/pic12f675.h>

// programación de los bits de configuración CONFIG
typedef unsigned int word;
word __at 0x2007 __CONFIG = (_WDTE_OFF);

// función principal
void main(void)
{
    // declaraciones de variables
    unsigned int rand_dado;   
    unsigned int resultadoADC;
    
    // inicialización de registros
    TRISIO &= 0x09; // poner pines GPIO[5:4,2:1] como salidas, GPIO[0] como entrada 
    GPIO &= 0x08;   // poner GPIO[5:4,2:1] en bajo
    
    // inicialización del módulo ADC
    ANSEL &= 0x71;  // pines 3, 5, 6 se usarán como entradas digitales y no AN3, AN2, AN1 
    ANSEL |= 0x01;  // habilitar pin 7 como entrada analógica AN0
    ANSEL |= 0x70;  // escoger el oscilador interno FRC como reloj de conversión ADC 
    CMCON &= 0x00;  // apagar comparadores
    
    // empezar conversión ADC
    GO_DONE = 1;    // empezar conversión ADC
    while (GO_DONE) // esperar a que la conversión ADC termine
        continue;        
    resultadoADC = ADRESH;  // obtener resultado de la conversión ADC
     
    while (1)
    {
        rand_dado = (resultadoADC % 6) + 1;
        switch (rand_dado)
        {
            case 1:
                GPIO = 0x20;    // mostrar un 1 en la cara del dado
                break;
            case 2:
                GPIO = 0x04;    // mostrar un 2 en la cara del dado
                break;
            case 3:
                GPIO = 0x30;    // mostrar un 3 en la cara del dado
                break;
            case 4:
                GPIO = 0x12;    // mostrar un 4 en la cara del dado
                break;
            case 5:
                GPIO = 0x32;    // mostrar un 5 en la cara del dado
                break;
            case 6:
                GPIO = 0x16;    // mostrar un 6 en la cara del dado
                break;
        }
    }
}
