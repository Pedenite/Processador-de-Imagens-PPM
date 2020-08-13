/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercício 4 - Atribuição de y*/

#include <stdio.h>

int main()
{
    float x;
    
    printf("Digite o valor de x > ");
    scanf("%f", &x);
    
    if(x<-1)
    {
        printf("y = 0\n");
    }
    else
    {
        if(x<0)
        {
            printf("y = 1\n");
        }
        else
        {
            if(x<=1)
            {
                printf("y = 2\n");
            }
            else
            {
                printf("y = 3\n");
            }
        }
    }
    
    return 0;
}
