/*Pedro Henrique de Brito Agnes 18/0026305
 Exercicio 7 - Soma de numeros racionais*/

#include <stdio.h>

int main()
{
    int x, y, z, w, n, d;

    printf("Digite um numero racional no formato: numerador/denominador > ");
    scanf("%d/%d", &x, &y);
    printf("Digite outro numero racional no formato: numerador/denominador > ");
    scanf("%d/%d", &z, &w);
    
    n = (x*w)+(z*y);
    d = (y*w);
    
    printf("O resultado eh %d/%d\n", n, d);
    
    return 0;
}
