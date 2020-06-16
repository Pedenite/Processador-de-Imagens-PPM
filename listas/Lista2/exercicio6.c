/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercício 6 - Retângulo em um espaço bidimensional*/

#include <stdio.h>

int main()
{
    int x, y, h, l, a, b, hy, lx;
    
    printf("INFORME DO RETÂNGULO:\n");
    printf("-Um ponto de origem do no formato x,y: ");
    scanf("%d,%d", &x, &y);
    printf("-A largura: ");
    scanf("%d", &l);
    if(h < 0)
    {
        printf("A largura não pode ser negativa\n");
    }
    else
    {
        printf("-A altura: ");
        scanf("%d", &h);
        if(l < 0)
        {
            printf("A altura não pode ser negativa\n");
        }
        else
        {
            printf("Agora informe um outro ponto qualquer no formato a,b: ");
            scanf("%d,%d", &a, &b);
            
            hy = y+h;
            lx = x+l;
            if(a < lx && a > x && b < hy && b > y)
            {
                printf("O ponto (%d,%d) está dentro do retângulo\n", a, b);
            }
            else
            {
                if(a > lx || a < x || b > hy || b < y)
                {
                    printf("O ponto (%d,%d) está fora do retângulo\n", a, b);
                }
                else
                {
                    printf("O ponto (%d,%d) etá em alguma das linhas que definem o retângulo\n", a, b);
                }
            }
        }
    }
    return 0;
}
