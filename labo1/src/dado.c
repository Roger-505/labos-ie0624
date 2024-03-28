#include <pic14/pic12f675.h>

// programación de los bits de configuración CONFIG
typedef unsigned int word;
word __at 0x2007 __CONFIG = (_WDTE_OFF);

// función principal
void main(void)
{
    // declaraciones de variables
    unsigned int rand_dado;   
    
    // inicialización de registros
    TRISIO &= 0x09; // poner pines GPIO[5:4,2:1] como salidas, GPIO[0] como entrada 
    GPIO &= 0x08;   // poner GPIO[5:4,2:1] en bajo
    
    while (1)
    {
        switch (temp)
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
