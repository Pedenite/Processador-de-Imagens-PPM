/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercicio 5 - Operação*/

#include <stdio.h>

int main()
{
    float a, b, r;
    char c;
    
    printf("Digite um número, uma operação (+, -, * ou /) e outro número: ");
    scanf("%f%c%f", &a, &c, &b);
    
    if(c == '+')
    {
        r = a+b;
        printf("O resultado é %f\n", r);
    }
    else
    {
        if(c == '-')
        {
            r = a-b;
            printf("O resultado é %f\n", r);
        }
        else
        {
            if(c == '*')
            {
                r = a*b;
                printf("O resultado é %f\n", r);
            }
            else
            {
                if(c == '/')
                {
                    r = a/b;
                    printf("O resultado é %f\n", r);
                }
                else
                {
                    printf("Caractere (operação) inválido\n");
                }
            }
        }
    }
    
    return 0;
}
