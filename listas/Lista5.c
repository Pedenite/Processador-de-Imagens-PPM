/* Pedro Henrique de Brito Agnes 18/0026305
 * Lista de Funções*/
#include <stdio.h>
#define MAX 100

int levetor(int v[], int n)//Elementos do vetor--------------------------
{
    int i=0;
    while(i != n && i < MAX)
    {
        printf("Digite o %d° elemento do vetor: ", i+1);
        scanf("%d", &v[i]);
        i++;
    }
    return i;
}
void imprime(int v[], int n)
{
    int i;
    printf("{");
    for(i = 0; i < n; i++)
    {
        printf("%d,", v[i]);
    }
    printf("\b}\n");
}
void levetoreal(float v[], int n)//Elementos do vetor da função 7------------
{
    int i=0;
    while(i != n && i < MAX)
    {
        printf("Digite o %d° elemento do vetor: ", i+1);
        scanf("%f", &v[i]);
        i++;
    }
}
int busca(int v[], int ch, int n)//Função 1----------------------------------
{
    printf("FUNÇÃO 1 >>>\t");
    int i;
    for(i = 0; i < n && i < MAX; i++)
    {
        if(v[i] == ch)
        {
            return i;
        }
    }
    return -1;
}

float media(int v[], int n, int i)//Função 2----------------------------------
{
    printf("FUNÇÃO 2 >>>\t");
    float med = 0;
    while(i)
    {
        med = med+v[i-1];
        i--;
    }
    med = med/n;
    
    return med;
}

int maiorval(int v[], int n)//Função 3-------------------------------------
{
    printf("FUNÇÃO 3 >>>\t");
    int i = 1;
    int ma = v[0];
    while(i < n)
    {
        if(v[i] > ma)
        {
            ma = v[i];
        }
        i++;
    }
    return ma;
}

int rep(int v[], int n)//Função 4--------------------------------------------
{
    printf("FUNÇÃO 4 >>>\t");
    int i = 0, j;
    int r;
    while(i < n)
    {
        for(j = i+1; j < n; j++)
        {
            if(v[i] == v[j])
            {
                r = v[i];
            }
        }
        i++;
    }
    return r;
}

void imppar(int v[], int n, int *p, int *im)//Função 5-------------------------
{
    printf("FUNÇÃO 5 >>>\t");
    int i;
    for(i = 0; i < n; i++)
    {
        if(v[i]%2)
        {
            *im = *im+1;
        }
        else
        {
            *p = *p+1;
        }
    }
}

void somaVet(int x[], int y[], int z[], int n)//Função 6---------------------
{
    printf("FUNÇÃO 6 >>>\t");
    int i;
    for(i = 0; i < n; i++)
    {
        z[i] = x[i]+y[i];
    }
}

float soPon(int v[], float w[], int n)//Função 7-----------------------------
{
    printf("FUNÇÃO 7 >>>\t");
    int i;
    float s = 0;
    for(i = 0; i < n; i++)
    {
        s = s+v[i]*w[i];
    }
    return s;
}

void espelho(int v[], int n, int i)//Função 8----------------------------------
{
    printf("FUNÇÃO 8 >>>\t");
    printf("{");
    while(i)
    {
        printf("%d,", v[i-1]);
        i--;
    }
    printf("\b}\n");
}
int main()//MAIN---------------------------------------------------------------
{
    int vetor[MAX], vet[MAX], resul[MAX];
    int tam, resultado, chave, I, par = 0, impar = 0;
    float res, pesos[MAX];
    
    printf("Digite a quantidadede elementos do vetor: ");
    scanf("%d", &tam);
    printf("Digite o valor a ser denotado por chave: ");
    scanf("%d", &chave);
    
    I = levetor(&vetor[MAX], tam);//Lê o vetor
    
    printf("\n");
    
    resultado = busca(&vetor[MAX], chave, tam);//Função 1
    if(resultado >= 0)
    {
        printf("O elemento %d está no índice %d\n", chave, resultado);
    }
    else
    {
        printf("O elemento %d não existe no vetor\n", chave);
    }
    res = media(&vetor[MAX], tam, I);//Função 2
    printf("A média dos elementos do vetor é %.2f\n", res);
    
    resultado = maiorval(&vetor[MAX], tam);//Função 3
    printf("O maior elemento do vetor é %d\n", resultado);
    
    resultado = rep(&vetor[MAX], tam);//Função 4
    printf("O elemento mais repetido é %d\n", resultado);
    
    imppar(&vetor[MAX], tam, &par, &impar);//Função 5
    printf("O vetor possui %d elementos pares e %d ímpares\n", par, impar);
    
    printf("\nSegundo vetor:\n");
    levetor(&vet[MAX], tam);//vetor para a função 6
    printf("\n");
    
    somaVet(&vetor[MAX], &vet[MAX], &resul[MAX], tam);//Função 6
    imprime(&resul[MAX], tam);
    
    printf("\nVetor de reais:\n");
    levetoreal(&pesos[MAX], tam);//Vetor para função 7
    printf("\n");
    
    res = soPon(&vetor[MAX], &pesos[MAX], tam);//Função 7
    printf("A soma ponderada dos vetores principal e real é %.2f\n", res);
    
    espelho(&vetor[MAX], tam, I);//Função 8
    
    printf("\n");
    
    return 0;
}
