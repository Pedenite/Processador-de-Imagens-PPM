/*Pedro Henrique de Brito Agnes 18/0026305
 Exercicio 1 - Maior numero*/

#include <stdio.h>

int main()
{
    int a, b;
    
    printf("Informe dois valores inteiros a e b > ");
    scanf("%d e %d", &a, &b);
    
    if(a!=b)
    {
        if(a>b)
        {
            printf("%d, valor de a eh maior\n", a);
        }
        else
        {
            printf("%d, valor de b eh maior\n", b);
        }
    }
    else
    {
        printf("O valor de a eh %d\n", a);
    }
    
    return 0;
}
