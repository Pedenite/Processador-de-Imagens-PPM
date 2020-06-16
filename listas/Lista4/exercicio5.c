/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercício 5 - Parte inteira e parte fracionária*/
#include <stdio.h>
void frac(float num, int *inteiro, float *fracio)
{
    *inteiro = num;
    *fracio = num-*inteiro;
}
int main()
{
    float x, f;
    int i;
    
    printf("Digite um número real: ");
    scanf("%f", &x);
    
    frac(x, &i, &f);
    
    printf("Parte inteira: %d\nParte fracionária: %f\n", i, f);
    
    return 0;
}
