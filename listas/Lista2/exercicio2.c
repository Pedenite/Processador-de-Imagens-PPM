/*Pedro Henrique de Brito Agnes 18/0026305
 Exercicio 2 - Maior numero entre 3*/

#include <stdio.h>

int main()
{
    int a, b, c;
    
    printf("Informe tres valores inteiros a/b/c > ");
    scanf("%d/%d/%d", &a, &b, &c);
    
    if(a!=b && a!=c && b!=c)
    {
        if(a>b && a>c)
        {
            printf("%d, valor de a eh maior\n", a);
        }
        else
        {
            if(b>a && b>c)
            {
                printf("%d, valor de b eh maior\n", b);
            }
            else
            {
                printf("%d, valor de c eh maior\n", c);
            }
        }
    }
    else
    {
        printf("O valor de c eh %d\n", c);
    }
    
    return 0;
}
