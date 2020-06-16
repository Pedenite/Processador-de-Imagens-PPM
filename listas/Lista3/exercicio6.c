/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercício 6 - Tabuada de multiplicação 1 a 10*/
#include <stdio.h>
int main()
{
    int i, x, y;
    x = 1;
    
    printf("TABUADA DE 1 A 10\n");

    for(i = 0; i != 10; i = i+1)
    {
        y = x*1;
        printf("1x%d=%d\t", x, y);
        x = x+1;
    }
    printf("\n");
    x = 1;

    for(i = 0; i != 10; i = i+1)
    {
        y = x*2;
        printf("2x%d=%d\t", x, y);
        x = x+1;
    }
    printf("\n");
    x = 1;

    for(i = 0; i != 10; i = i+1)
    {
        y = x*3;
        printf("3x%d=%d\t", x, y);
        x = x+1;
    }
    printf("\n");
    x = 1;

    for(i = 0; i != 10; i = i+1)
    {
        y = x*4;
        printf("4x%d=%d\t", x, y);
        x = x+1;
    }
    printf("\n");
    x = 1;

    for(i = 0; i != 10; i = i+1)
    {
        y = x*5;
        printf("5x%d=%d\t", x, y);
        x = x+1;
    }
    printf("\n");
    x = 1;

    for(i = 0; i != 10; i = i+1)
    {
        y = x*6;
        printf("6x%d=%d\t", x, y);
        x = x+1;
    }
    printf("\n");
    x = 1;

    for(i = 0; i != 10; i = i+1)
    {
        y = x*7;
        printf("7x%d=%d\t", x, y);
        x = x+1;
    }
    printf("\n");
    x = 1;

    for(i = 0; i != 10; i = i+1)
    {
        y = x*8;
        printf("8x%d=%d\t", x, y);
        x = x+1;
    }
    printf("\n");
    x = 1;

    for(i = 0; i != 10; i = i+1)
    {
        y = x*9;
        printf("9x%d=%d\t", x, y);
        x = x+1;
    }
    printf("\n");
    x = 1;

    for(i = 0; i != 10; i = i+1)
    {
        y = x*10;
        printf("10x%d=%d\t", x, y);
        x = x+1;
    }
    printf("\n");

    return 0;
}
