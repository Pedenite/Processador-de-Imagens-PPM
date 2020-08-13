/*Pedro Henrique de Brito Agnes 18/0026305
 Exercicio 1 - Calcular o valor de r na equaçao*/

#include <stdio.h>

int main()
{
    int a, b, c;
    
    printf("Digite os valores a:b:c ");
    scanf("%d:%d:%d", &a, &b, &c);
    
    float R=(float)((a*a)-(2*a*b)+(b*b))/(float)((a-c)*(a-b));
    
    printf("O resultado eh %f\n", R);

    return 0;
}
