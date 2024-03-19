#include <pic14/pic12f675.h>

void delay(unsigned int tiempo);
void random(void);

void main(void)
{
    TRISIO = 0x00;      // Poner pines GPIO[5:0] (exceptuando GPIO3) como salidas
    GPIO = 0x00;        // Poner todas las salidas en bajo 
    
    unsigned int time = 100;
    
    while (1)
    {
        
    }
}

void delay(unsigned int tiempo)
{
    unsigned int i;
    unsigned int j;

    for(i = 0; i < tiempo; i++)
        for(j = 0; j < 1275; j++);
}

void random(void)
{
    return 6;
}
