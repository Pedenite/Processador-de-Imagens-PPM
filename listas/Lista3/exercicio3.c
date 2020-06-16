/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercício 3 - Produtório*/
#include <stdio.h>
int main()
{
    int a, b, c, d, p;
    
    printf("Digite os valores neste formato: a e b > ");
    scanf("%d e %d", &a, &b);
    
    while(a >= b)
    {
        printf("O valor de a deve ser menor que o de b!\n");
        printf("Digite os valores neste formato: a e b > ");
        scanf("%d e %d", &a, &b);
    }
    p = a*b;
    c = a;
    d = b-1;
    
    while(a != d)//deve-se ir até b-1 para não repetir a multiplicação de b
    {
        a = a+1;
        p = p*a;
    }
    printf("O produtório de todos os números de %d a %d é = %d\n", c, b, p);
    
    return 0;
}
