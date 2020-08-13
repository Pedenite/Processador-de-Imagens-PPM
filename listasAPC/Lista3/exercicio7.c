/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercício 7 - Depende do caractere*/
#include <stdio.h>
int main()
{
    int a, b, d, e;
    char c;
    
    printf("Digite dois números inteiros no formato a e b: ");
    scanf("%d e %d", &a, &b);
    while(a < 0 || b < a)
    {
        printf("ERRO: 'a' deve ser maior que 0 e menor que b (0<a<b)\n");
        printf("Redigite a e b no mesmo formato: ");
        scanf("%d e %d", &a, &b);
    }
    printf("Digite um caractere: ");
    getchar();
    scanf("%c", &c);
    
    if(c == 'a')
    {
        printf("%d", a);
        d = a;
        while(d < b)
        {
            d = d+1;
            e = d%a;
            if(e == 0)
            {
                printf(", %d", d);
            }
        }
    }
    else
    {
        if(c == 'b')
        {
            e = a%2;
            if(e)
            {
                printf("%d", a);
                while(a < b)
                {
                    a = a+2;
                    printf(", %d", a);
                }
            }
            else
            {
                a = a+1;
                printf("%d", a);
                while(a < b)
                {
                    a = a+2;
                    printf(", %d", a);
                }
            }
        }
        else
        {
            return 0;
        }
    }
    printf("\n");

    return 0;
}
