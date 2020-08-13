/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercício 5 - Soma cumulativa*/
#include <stdio.h>
int main()
{
    int a, b, i, c, d;
    
    printf("Digite 2 números inteiros com espaço entre eles (a b): ");
    scanf("%d %d", &a, &b);
    
    while(a > b)
    {
        printf("ERRO: 'a' deve ser menor que 'b'!!!");
        printf("Redigite a e b: ");
        scanf("%d %d", &a, &b);
    }
    printf("%d\t", a);
    
    c = a+1;
    d = a+c;
    
    for(i = a; i != b;i = i+1)
    {
        printf("%d\t", d);
        c = c+1;
        d = d+c;
    }
    printf("\n");

    return 0;
}
