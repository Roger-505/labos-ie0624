#include <pic14/pic12f675.h>

// programación de los bits de configuración CONFIG
typedef unsigned int word;
word __at 0x2007 __CONFIG = (_WDTE_OFF);

// prototipos de funciones
void setupIO(void);
void setupADC(void);
unsigned int leerADC(void);
unsigned int mostrarDado(unsigned int num_dado);

// función principal
void main(void)
{
    setupIO();
    setupADC();

    unsigned int num_dado = (leerADC() % 6) + 1;
    
    while (1)
    {
        mostrarDado(num_dado);
    }
}

// inicialización de registros
void setupIO(void)
{
    TRISIO &= 0x09; // poner pines GPIO[5:4,2:1] como salidas, GPIO[0] como entrada 
    GPIO &= 0x08;   // poner GPIO[5:4,2:1] en bajo
    ANSEL &= 0x71;  // pines 3, 5, 6 se usarán como salidas digitales, y el pin 7 como AN0
}

// inicialización del módulo ADC
void setupADC(void)
{
    ANSEL |= 0x70;  // escoger el oscilador interno FRC como reloj de conversión ADC 
    CMCON &= 0x00;  // apagar comparadores
    ADFM = 1;       // justificación derecha en el resultado de 10 bits de la conversión ADC
    ADON = 1;       // habilitar módulo de conversión ADC
}

// empezar conversión ADC
unsigned int leerADC(void)
{
    GO_DONE = 1;    // empezar conversión ADC
    while (GO_DONE) // esperar a que la conversión ADC termine
        continue;        
    return (ADRESH<<8) + ADRESL;  // obtener resultado de la conversión ADC
}

// mostrar valor aleatorio en la cara del dado
unsigned int mostrarDado(unsigned int num_dado)
{
    switch (num_dado)
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
