/** @file dado.c
 *  @brief Esta es una implementación en C del firmware para un simulador de dado simplificado.
 *  @author [Roger Piovet](https://github.com/Roger-505)
 *  @details Esta implementación es para el microcontrolador PIC12F675, la cual aprovecha el módulo de conversión ADC para generar números aleatorios. 
 *  Dicho módulo lee un pin flotante del MCU, lo cual permite generar números aleatorios en el rango [0,1024[, los cuales son posteriormente convertidos 
 *  a un número aleatorio en el rango [1,6] para simular la aleatoriedad del dado.
 *
 *  La implementación consiste de un 'setup' en donde se inicializan registros y variables, y un 'loop', el cual se ejecuta cíclcicamente de forma indefinida.
 *  En el setup, se escoge la funcionalidad de cada pin del MCU según la siguiente tabla.
 *
 *  | Número de pin| Funcionalidad   |
 *  | :----------: | :-------------: |
 *  |     1        |      VDD        |
 *  |     2        |      GP5        |
 *  |     3        |      GP4        |
 *  |     4        |      MCLR       |
 *  |     5        |      GP2        |
 *  |     6        |      GP1        |
 *  |     7        |      AN0        |
 *  |     8        |      VSS        |
 *
 *  Para más información, consulte el datasheet del  <a href="https://ww1.microchip.com/downloads/en/devicedoc/41190c.pdf">PIC12F675</a>
 */
#include <pic14/pic12f675.h> 

/**
 * @brief Para configurar los bits CONFIG
 *
 * Es necesario deshabilitar el WDT para evitar interrupciones que reinicien el microcontrolador
 * cada vez que este timer se desborde. Para este laboratorio en particular, no se le dará ningún 
 * uso al WDT. 
 *
 */
typedef unsigned int word;      
word __at 0x2007 __CONFIG = (_WDTE_OFF);

/**
 * @brief Inicializa los puertos I/O del MCU.
 * @returns Registro TRISIO con los bits TRISIO[5:4,2:1] = 0000 para habilitar puertos GPIO[5:4,2:1] como salidas digitales.
 * @returns Registro ANSEL con los bits ANS[3:1] = 000 para asegurar que los pines 3, 5, y 6 estén configurados como puertos IO digitales y no analógicos.
 * @returns Registro GPIO con los bits GPIO[5:4,2:1] = 0000 para poner las salidas digitales en bajo.
 */
void setupIO(void);
/**
 * @brief Inicializa el módulo de conversión ADC del MCU.
 * @returns Registro ANSEL con los bits ADCS[2:0] = 111 para escoger el oscilador interno FRC como el reloj de conversión ADC.
 * @returns Registro CMCON con los bits CM[2:0] = 111 para deshabilitar los comparadores y asegurar el correcto funcionamiento del módulo ADC.
 * @returns Registro ADCON con los bits:
 * - ADON = 1 para habilitar el módulo ADC
 * - ADFM = 1 para que el resultado de la conversión ADC posea justificación derecha con respecto a los registros ADRESH y ADRESL
 *
 *   @note Los bits VCFG y CHS[1:0] son configurados en el POR, por lo que la referencia de voltaje es VDD y el canal analógico para la conversión ADC es AN0 (VCFG = 0, CHS[1:0] = 00).
 */
void setupADC(void);
/**
 * @brief Realiza una conversión ADC y obtiene el resultado.
 * @returns Resultado de la conversión ADC.
 */
unsigned int leerADC(void);
/**
 * @brief Generar un número en el dado por medio de los LEDs conectados a los GPIO
 * @param num_dado Número entero en el rango [1,6]  
 * @returns Registro GPIO mapeado de acuerdo con el número en num_dado.
 *
 *    | num_dado  |  GPIO[5:4,2:1]  |
 *    | :-------: | :-------------: |
 *    |     1     |      1000       |
 *    |     2     |      0010       |
 *    |     3     |      1100       |
 *    |     4     |      0101       |
 *    |     5     |      1101       |
 *    |     6     |      0111       |
 */
void mostrarDado(unsigned int num_dado);

/**
 * @brief Función principal
 */
void main(void)
{
    setupIO();
    setupADC();
    
    /** Convierte un número aleatorio mod 1024 de la conversión ADC al rango [1,6]*/
    unsigned int num_dado = (leerADC() % 6) + 1;
    
    while (1)
    {
        mostrarDado(num_dado);
    }
}

void setupIO(void)
{
    TRISIO &= 0x09; 
    ANSEL &= 0x71;  
    GPIO &= 0x08;   
}

void setupADC(void)
{
    ANSEL |= 0x70;  
    CMCON |= 0x07;  
    ADFM = 1;       
    ADON = 1;       
}

unsigned int leerADC(void)
{
    GO_DONE = 1;    
    while (GO_DONE) // esperar a que la conversión ADC termine
        continue;        
    return (ADRESH<<8) + ADRESL;  
}

void mostrarDado(unsigned int num_dado)
{
    switch (num_dado)
    {
        case 1:
            GPIO = 0x20;    
            break;
        case 2:
            GPIO = 0x04;    
            break;
        case 3:
            GPIO = 0x30;   
            break;
        case 4:
            GPIO = 0x12;  
            break;
        case 5:
            GPIO = 0x32; 
            break;
        case 6:
            GPIO = 0x16;
            break;
    }
}
