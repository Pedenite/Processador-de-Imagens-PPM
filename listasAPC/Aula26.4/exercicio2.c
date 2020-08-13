/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercicio 2 - Média aritmética de vários números*/
#include <stdio.h>
int main()
{
    int n;
    float a, b, ad, den, m, c;
    
    while(n < 2)
    {
        printf("Informe a quantidade de valores que irá digitar: ");
        scanf("%d", &n);
    }
    n = n-1;
        
    printf("Informe o valor: ");
    scanf("%f", &a);
    
    n = n-1;
    
    printf("Informe o valor: ");
    scanf("%f", &b);
    
    ad = a+b;
    den = 2;
    m = ad/den;
    
    while(n > 0)
    {
        n = n-1;
        
        printf("Informe o valor: ");
        scanf("%f", &c);
        
        ad = ad+c;
        den = den+1;
        m = ad/den;
    }
    printf("A média dos números é %f\n", m);
    
    return 0;
}
