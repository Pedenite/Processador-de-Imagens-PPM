/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercício 1 - Positivo ou negativo*/
#include <stdio.h>
int main()
{
    int nro;
    char c;
    
    do
    {
        printf("Digite um número inteiro: ");
        scanf("%d", &nro);
        
        if(nro>0)
        {
            printf("Número é positivo\n");
        }
        else
        {
            printf("Número é negativo\n");
        }
        printf("Deseja continuar? s = sim, n = não\n");
        scanf("%c", &c);
        c = getchar();
        while(c != 's' && c != 'n')
        {
            printf("Deseja continuar? s = sim, n = não\n");
            scanf("%c", &c);
            c = getchar();
        }
    }while(c == 's');
    
    return 0;
}
