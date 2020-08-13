/*Pedro Henrique de Brito Agnes 18/0026305
 Exercicio 7 - Homem ou mulher*/

#include <stdio.h>

int main()
{
    char c;
    
    printf("Digite f ou m > ");
    scanf("%c", &c);
    
    if(c == 'f' || c == 'F')
    {
        printf("Mulher\n");
    }
    else
    {
        if(c == 'm' || c == 'M')
        {
            printf("Homem\n");
        }
        else
        {
            printf("ERROR: Caractere inválido\n");
        }
    }
    
    return 0;
}
