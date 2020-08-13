/*Pedro Henrique de Brito Agnes 18/0026305
 Exercicio - Conversao de nota*/

#include <stdio.h>

int main()
{
    float n;
    
    printf("Indique sua nota > ");
    scanf("%f", &n);
    if(0<=n && n<=10)
    {
        if(n<9)
        {
            if(n<7)
            {
                if(n<5)
                {
                    if(n<3)
                    {
                        printf("Sua nota foi II\n");
                    }
                    else
                    {
                        printf("Sua nota foi MI\n");
                    }
                }
                else
                {
                    printf("Sua nota foi MM\n");
                }
            }
            else
            {
                printf("Sua nota foi MS\n");
            }
        }
        else
        {
            printf("Sua nota foi SS\n");
        }
    }
    else
    {
        printf("Sua nota eh invalida\n");
    }
    return 0;
}
