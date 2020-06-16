/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercício 4 - Sequência de Fibonacci*/
#include <stdio.h>

int main()
{
    int n, n1, n2, f1, f2, i;
    f1 = 1;
    f2 = 1;
    i = 3;
    
    printf("Digite um número: ");
    scanf("%d", &n);
    
    while(n <= 2)
    {
        printf("O número deve ser maior do que 2. Redigite o número: ");
        scanf("%d", &n);
    }
    n1 = n-1;
    n2 = n-2;
    
    printf("F(%d) = F(%d) + F(%d)", n, n1, n2);
    
    while(i != n)
    {
        i = i+1;
        n1 = n1-1;
        printf("F(%d) = 
    }
    
    return 0;
}
