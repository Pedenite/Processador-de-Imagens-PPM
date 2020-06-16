/*Pedro Henrique de Brito Agnes 18/0026305
 Exercicio 2 - Media aritmetica*/

#include <stdio.h>

int main()
{
    float r1, r2;
    
    printf("Digite os numeros no formato: e ");
    scanf("%f e %f", &r1, &r2);
    
    float s=r1+r2;
    float R=s/2;
    
    printf("A media dos numeros eh %f\n", R);
    
    return 0;
}
