/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercício 2 - Maior valor*/
#include <stdio.h>
float maior(float x, float y, float z)
{
    float w;
    
    if(x > y && x > z)
    {
        w = x;
    }
    else
    {
        if(y > z)
        {
            w = y;
        }
        else
        {
            w = z;
        }
    }
    return w;
}
int main()
{
    float a, b, c, r;
    
    printf("Digite a > ");
    scanf("%f", &a);
    printf("Digite b > ");
    scanf("%f", &b);
    printf("Digite c > ");
    scanf("%f", &c);
    
    r = maior(a, b, c);
    
    printf("O maior valor entre a, b e c é %f\n", r);
    
    return 0;
}
