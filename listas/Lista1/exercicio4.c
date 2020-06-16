/*Pedro Henrique de Brito Agnes 18/0026305
 Exercicio 4 - Valor da compra com atraso*/

#include <stdio.h>

int main()
{
    int x, y;    
    
    printf("Digite o valor da compra em reais");
    scanf("%d", &x);
    printf("Digite o atraso do pagamento em dias");
    scanf("%d", &y);
    
    float v, t;
    v=x*0.05*y;
    t=x+v;
    
    printf("O valor com multa eh de %f reais\n", t);

    return 0;
}
