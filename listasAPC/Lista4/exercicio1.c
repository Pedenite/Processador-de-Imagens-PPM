/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercício 1 - Decimal para octal sucessivas divisões*/
#include <stdio.h>
int oct(int x)
{
    int y, i = 1, o = 0;
    
    while(x)
    {
        y = x%8;
        x = x/8;
        y = y*i;
        i = i*10;
        o = o+y;
    }
    return o;
}
int main()
{
    int d, octal;
    
    printf("Digite o número decimal a ser convertido para octal: ");
    scanf("%d", &d);
    
    octal = oct(d);
    printf("o octal equivalente ao decimal %d é >>> %d\n", d, octal);
    
    return 0;
}
