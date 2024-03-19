#include <pic14/pic12f675.h>

void delay(unsigned int tiempo);
int random(void);

void main(void)
{
    TRISIO = (TRISIO << 6) | 0x01;          // Poner pines GPIO[5:4] y GPIO[2:0] como salidas, y GPIO3 como entrada
    GPIO &= 0x00;                           // Poner GPIO[5:4] y GPIO[2:0] en bajo
    
    unsigned int time = 100;
    int temp = randomADC();

    while (1)
    {
        switch (temp)
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
}

void delay(unsigned int tiempo)
{
    unsigned int i;
    unsigned int j;

    for(i = 0; i < tiempo; i++)
        for(j = 0; j < 1275; j++);
}

int randomADC(void)
{
    return 6;
}
