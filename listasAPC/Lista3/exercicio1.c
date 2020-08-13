/*Pedro Henrique de Brito Agnes 18/0026305
 * Exercício 1 - Altura e idade médias*/
#include <stdio.h>

int main()
{
    int n, N;
    float a, i, am, im;
    
    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &n);
    
    while(n <= 0)
    {
        printf("ERRO: a quantidade de pessoas deve ser maior que 0\n");
        printf("Redigite a quantidade de pessoas: ");
        scanf("%d", &n);
    }
    if(n == 1) //Caso tenha apenas 1 pessoa, isso fará com que se imprima os dados desta mesma pessoa.
    {
        printf("Digite a altura em metros: ");
        scanf("%f", &a);
        
        while(a <= 0)
        {
            printf("ERRO: a altura deve ser maior que 0\n");
            printf("Redigite a altura em metros: ");
            scanf("%f", &a);
        }
        printf("Digite a idade em anos: ");
        scanf("%f", &i);
        
        while(i <= 0)
        {
            printf("ERRO: a idade deve ser maior que 0\n");
            printf("Redigite a idade em anos: ");
            scanf("%f", &i);
        }
    printf("A altura da pessoa é de %f metros\n", a);
    printf("A idade da pessoa é de %f anos\n", i);
    }
    else //Aqui segue-se o programa normalmente com 2 ou mais pessoas.
    {    
        N = n;
        am = 0;
        im = 0;
        
        while(N)
        {
            N = N-1;
            printf("Digite a altura em metros: ");
            scanf("%f", &a);
            
            while(a <= 0)
            {
                printf("ERRO: a altura deve ser maior que 0\n");
                printf("Redigite a altura em metros: ");
                scanf("%f", &a);
            }
            printf("Digite a idade em anos: ");
            scanf("%f", &i);
            
            while(i <= 0)
            {
                printf("ERRO: a idade deve ser maior que 0\n");
                printf("Redigite a idade em anos: ");
                scanf("%f", &i);
            }
            am = am+a;
            im = im+i;
        }
        am = am/n;
        im = im/n;
        
        printf("A altura média das pessoas é de %f metros\n", am);
        printf("A idade média das pessoas é de %f anos\n", im);
    }
    return 0;
}
