#include <pic14/pic12f675.h>

// programación de los bits de configuración CONFIG
typedef unsigned int word;
word __at 0x2007 __CONFIG = (_MCLRE_OFF);

// declaración de funciones
void delay(unsigned int tiempo);

// función principal
void main(void)
{
    // declaraciones de variables
    int temp;   // variable aleatoria por implementar
    
    // inicialización de registros
    TRISIO &= 0x08;                 // Poner pines GPIO[5:4] y GPIO[2:0] como salidas. GPIO3 siempre se lee como 1
    GPIO &= 0x08;                   // Poner GPIO[5:4] y GPIO[2:0] en bajo
    
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

// función delay, para detener al MCU
// por un tiempo
void delay(unsigned int tiempo)
{
    unsigned int i;
    unsigned int j;

    for(i = 0; i < tiempo; i++)
        for(j = 0; j < 1275; j++);
}
