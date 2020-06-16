/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercício 4 - Endereço de valor maior*/
#include <stdio.h>
double end(double *p1, double *p2)
{
    printf("Endereço x: %p\nEndereço y: %p\n", p1, p2);
    if(p1 > p2)
    {
        return *p1;
    }
    else
    {
        return *p2;
    }
}
int main()
{
    double x, y, m;
    
    printf("Dê o valor de x y: ");
    scanf("%lf %lf", &x, &y);
    
    m = end(&x, &y);
    
    printf("Endereço de maior valor: %lf\n", m);
    
    return 0;
}
