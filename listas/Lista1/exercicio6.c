/*Pedro Henrique de Brito Agnes 18/0026305
 Exercicio 6 - Conversao de tempo*/

#include <stdio.h>

int main()
{
    int s, x, y, z;

    printf("digite o tempo em segundos ");
    scanf("%d", &s);
    
    x = s/3600;
    y = (s%3600)/60;
    z = (s%3600)%60;

    printf("Isso equivale a %d horas, %d minutos, %d segundos\n", x, y, z);

    return 0;
}
