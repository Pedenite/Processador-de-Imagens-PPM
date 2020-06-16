/* Pedro Henrique de Brito Agnes 18/0026305
 * Lista de Matrizes */
#include <stdio.h>
#define MAX 100

void leMatr(long int mat[][MAX], int n, int m)
{
    int i = 0, j;
    while(i != n)
    {
        j = 0;
        while(j != m)
        {
            printf("Digite o valor (%d,%d) da matriz: ", i, j);
            scanf("%ld", &mat[i][j]);
            j++;
        }
        i++;
    }
}
void lematrizint(int x[][MAX], int tam)
{
    int i, j;
    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam; j++)
        {
            printf("Digite o valor (%d,%d) da matriz: ", i, j);
            scanf("%d", &x[i][j]);
        }
    }
}
void impriMatr(long int mat[][MAX], int n, int m)
{
    int i, j;
    for(i = 0; i != n; i++)
    {
        for(j = 0; j != m; j++)
        {
            printf("%ld\t", mat[i][j]);
        }
        printf("\n");
    }
}
void levetor(float v[], int tam)
{
    int i;
    for(i = 0; i != tam; i++)
    {
        printf("Digite o valor do vetor[%d] > ", i);
        scanf("%f", &v[i]);
    }
}
/* Exercício 1 */
float mediagonalP(long int mat[][MAX], int n, int m)
{
    printf("Exercício 1 >\t");
    int i = 0;
    float me = 0;
    if(n == m)
    {
        while(i != n)
        {
            me = me+mat[i][i];
            i++;
        }
        me = me/n;
    }
    else
    {
        printf("ERRO: A matriz não é quadrada, portanto não tem diagonal principal\n");
        return -1000;
    }
    return me;
}
/* Exercício 2 */
void funcII(long int mat[][MAX], int n, int m)
{
    printf("Exercício 2 >\t");
    int i = 0, j;
    int po = 0, pa = 0;
    while(i != n)
    {
        j = 0;
        while(j != m)
        {
            if(mat[i][j] > 0)
            {
                po++;
            }
            if(mat[i][j]%2 == 0)
            {
                pa++;
            }
            j++;
        }
        i++;
    }
    printf("A quantidade de elementos positivos da matriz é %d\n", po);
    printf("A quantidade de elementos pares da matriz é %d\n", pa);
}
/* Exercício 3 */
void somaCol(long int mat[][MAX], long int v[], int n, int m)
{
    int i, j;
    printf("Exercício 3 >\t(");
    for(i = 0; i != m; i++)//colunas
    {
        v[i] = 0;
        for(j = 0; j != n; j++)//linhas
        {
            v[i] = v[i]+mat[j][i];
        }
        printf("%ld,", v[i]);
    }
    printf("\b)\n");
}
/* Exercício 4 */
void multiplic(long int x[][MAX], int y[][MAX], long int z[][MAX], int tam)
{
    printf("Exercício 4 >\t");
    int i, j, k;
    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam; j++)
        {
            z[i][j] = 0;
            for(k=0; k<tam; k++)
            {
                z[i][j] = z[i][j]+(x[i][k]*y[k][j]);
            }
        }
    }
}
/* Exercício 5 */
int busca(long int x[][MAX], float v[], int n, int m)
{
    printf("Exercício 5 >\t");
    int i, j, R = -1;
    for(i = 0; i != n; i++)
    {
        j = 0;
        if(v[j] == x[i][j])
        {
            for(j = 1; j < m; j++)
            {
                if(v[j] == x[i][j])
                {
                    R = i;
                }
                else
                {
                    R = -1;
                    j = 101;//Para garantir a saída da condicional
                }
            }
        }
    }
    return R;
}
/* Exercício 6 e 7 (são EXATAMENTE a mesma coisa) */
int repet(long int x[][MAX], int n, int m)
{
    printf("Exercício 6 >\t");
    int i, j, r = x[0][0];
    for(i = 0; i != n; i++)
    {
        for(j = 0; j != m; j++)
        {
            if(x[i][j] == x[i][j+1])
            {
                r = x[i][j];
            }
        }
    }
    return r;
}  
/* Exercício 8 */
int compMat(long int A[][MAX], long int B[][MAX], int n1, int m1, int n2, int m2)
{
    printf("Exercício 8 >\t");
    int i, j, k, l, resul = -1, j2;
    for(i = 0; i != n1; i++)
    {
        for(j = 0; j != m1; j++)
        {
            if(B[0][0] == A[i][j])
            {
                j2 = j;
                for(k = 0; k != n2; k++)
                {
                    j = j2;
                    for(l = 1; l != m2; l++)
                    {
                        j++;
                        if(B[k][l] == A[i][j])
                        {
                            resul = 1;
                        }
                        else
                        {
                            return -1;
                        }
                    }
                    i++;
                }
            }
        }
    }
    return resul;
}

int main()
{
    long int A[MAX][MAX], C[MAX][MAX], vet[MAX];
    int B[MAX][MAX], result;
    int m, n, n2, m2;
    float res, v[MAX];
    
    printf("Digite a quantidade de linhas da matriz: ");
    scanf("%d", &n);
    printf("Digite a quantidade de colunas da matriz: ");
    scanf("%d", &m);
    
    leMatr(A, n, m);
    impriMatr(A, n, m);
    
    res = mediagonalP(A, n, m);//Exercício 1
    if(res == -1000);
    else
    {
        printf("A média da diagonal principal da matriz é %f\n", res);
    }
    
    funcII(A, n, m);//Exercício 2
    
    somaCol(A, vet, n, m);//Exercício 3

    if(n == m)//Exercício 4
    {
        lematrizint(B, n);
        multiplic(A, B, C, n);
        printf("O resultado da multiplicação das matrizes é:\n");
        impriMatr(C, n, m);
    }
    else
    {
        printf("Exercício 4 >\tERRO: O algoritmo realiza mulitiplicação apenas de matrizes quadradas de mesmo tamanho\n");
    }
    
    levetor(v, m);//Exercício 5
    result = busca(A, v, n, m);
    if(result == -1)
    {
        printf("O vetor não se encontra na matriz\n");
    }
    else
    {
        printf("O vetor está na linha %d da matriz\n", result);
    }
    
    result = repet(A, n, m);//Exercício 6 e 7
    printf("O elemento mais repetido é %d\n", result);
    printf("Exercício 7 >\tO elemento mais repetido é %d\n", result);
    
    printf("Digite a quantidade de linhas da matriz: ");//Exercício 8
    scanf("%d", &n2);
    printf("Digite a quantidade de colunas da matriz: ");
    scanf("%d", &m2);
    
    leMatr(C, n2, m2);
    impriMatr(C, n2, m2);
    
    result = compMat(A, C, n, m, n2, m2);
    if(result == -1)
    {
        printf("A matriz 'A' NÃO contém a matriz 'B'\n");
    }
    else
    {
        printf("A matriz 'A' contém a matriz 'B'\n");
    }
    
    return 0;
}
