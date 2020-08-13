/* Algoritmos e Programação de Computadores - 1/2018
 * Aluno: Pedro Henrique de Brito Agnes
 * Matrícula: 18/0026305
 * Turma: B
 * Descrição: O programa irá aproximar a função exponencial e(x) e, em seguida calculá-la novamente usando a função exp(x) na biblioteca math.h e, por fim, calcular o erro ε entre elas. */
#include <stdio.h>
#include <math.h>

void valorn(int *n)//Verificação do valor de n
{
    while(*n < 0 || *n > 10)
    {
        printf("ERRO: 0<=n<=10\nRedigite n: ");
        scanf("%d", n);
    }
}

int pot(int base, int expoente)//Potenciação
{
    int poten;
    poten = pow(base,expoente);
    return poten;
}

int fat(int F, int C)//Fatorial
{
    while(C != 0)
    {
        F = F*C;
        C--;
    }
    return F;
}

int main()
{
    int n, x, i, f, c, p;
    float e, expon, erro;
    
    printf("Indique o valor de x: ");
    scanf("%d", &x);
    printf("Indique o valor de n: ");
    scanf("%d", &n);
    
    valorn(&n);
    
    e = 1;
    f = 1;
    i = 0;
    
    while(i != n)//Calcula a aproximação da função exponencial
    {
        c = i;
        f = fat(f, c);
        i++;
        p = pot(x, i);
        e = e+((float)p/(float)f);
        f = i+1;
    }
    printf("e(x) = %f\n", e);
    
    expon = exp(x);
    
    printf("exp(x) = %f\n", expon);
    
    erro = e-expon;//Calcula o erro ε
    
    printf("\nε = %f\n", erro);
    
    return 0;
}
