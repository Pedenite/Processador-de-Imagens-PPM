/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercício 2 - Quebra do número em linhas*/
#include <stdio.h>

int main()
{
    int n, x;
    
    printf("Digite um número (de preferência maior que 10): ");
    scanf("%d", &n);
    
    while(n >= 0)
    {
        x = n%10;
        n = n/10;
        
        printf("%d\n", x);//está de trás para frente :(
    }
    return 0;
}
