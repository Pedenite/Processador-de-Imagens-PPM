/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercício 3 - Ímpares entre os números*/
#include <stdio.h>
int main()
{
    int n, m, rn, rm;
    
    printf("Digite dois números inteiros positivos com espaço entre eles: ");
    scanf("%d %d", &n, &m);
    
    while(n < 0)
    {
        printf("ERROR: n deve ser positivo. Redigite n: ");
        scanf("%d", &n);
    }
    while(m < 0)
    {
        printf("ERROR: m deve ser positivo. Redigite m: ");
        scanf("%d", &m);
    }
    while(n >= m)
    {
        printf("ERROR: n não pode ser maior ou igual m!");
        printf("Redigite os valores: ");
        scanf("%d %d", &n, &m);
    }
    rn = n%2;
    rm = m%2;
    
    if(rn == 0)
    {
        n = n+1;
        printf("%d\n", n);
        
        if(rm == 0)
        {
            while(n != (m-1))
            {
                n = n+2;
                printf("%d\n", n);
            }
        }
        else
        {
            while(n != m)
            {
                n = n+2;
                printf("%d\n", n);
            }
        }
    }
    else
    {
        printf("%d\n", n);
        
        if(rm == 0)
        {
            while(n != (m-1))
            {
                n = n+2;
                printf("%d\n", n);
            }
        }
        else
        {
            while(n != m)
            {
                n = n+2;
                printf("%d\n", n);
            }
        }
    }
    return 0;
}
