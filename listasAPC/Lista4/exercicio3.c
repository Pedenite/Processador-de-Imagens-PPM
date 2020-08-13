/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercício 3 - Triângulo*/
#include <stdio.h>
float triangulo(float x, float y, float z)
{
    int tr;
    
    if(x >= y+z || y >= x+z || z >= x+y)
    {
        tr = 0;
    }
    else
    {
        if(x == y && x == z && y == z)
        {
            tr = 3;
        }
        else
        {
            if(x != y && x != z && y != z)
            {
                tr = 1;
            }
            else
            {
                tr = 2;
            }
        }
    }
    return tr;
}
int main()
{
    float a, b, c;
    int t;
    
    printf("Digite a b c: ");
    scanf("%f %f %f", &a, &b, &c);
    
    t = triangulo(a, b, c);
    
    if(t == 0)
    {
        printf("a b c não pode ser um triângulo\n");
    }
    else
    {
        if(t == 1)
        {
            printf("a b c pode ser um triângulo escaleno\n");
        }
        else
        {
            if(t == 2)
            {
                printf("a b c pode ser um triângulo isósceles\n");
            }
            else
            {
                printf("a b c pode ser um triângulo equilátero\n");
            }
        }
    }
    
    return 0;
}
