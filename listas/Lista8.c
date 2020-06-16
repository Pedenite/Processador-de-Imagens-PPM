/* Pedro Henrique de Brito Agnes 18/0026305
 * Lista de Recursividade */
#include <stdio.h>
#define MAX 100

void leVetor(int vet[], int n)
{
    int i;
    for(i = 0; i != n; i++)
    {
        printf("Digite o valor do vetor[%d]: ", i);
        scanf("%d", &vet[i]);
    }
}
/* Exercício 1 */
int strComp_rec(char string[], int i)
{
    if(string[i] == '\0')
    {
        return i;
    }
    return strComp_rec(string, i+1);
}
/* Exercício 2 */
int fibonacci(int n)
{
    if(n == 1)
    {
        return 1;
    }
    if(n == 0)
    {
        return 0;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
/* Exercício 3 */
int pot_rec(int b, int p)
{
    if(p == 1)
    {
        return b;
    }
    return pot_rec(b, p-1)*b;
}
/* Exercício 4 */
void imprimeStrRev_rec(char string[], int i)
{
    if(i == 0)
    {
        printf("%c", string[i]);
        return ;
    }
    printf("%c", string[i]);
    imprimeStrRev_rec(string, i-1);
}
/* Exercício 5 */
void imprimeVetor_rec(int vet[], int i)
{
    if(i == 0)
    {
        printf("%d", vet[i]);
        return ;
    }
    imprimeVetor_rec(vet, i-1);
    printf(", %d", vet[i]);
}
/* Exercício 6 */
int contaNumeros_rec(char string[], int i)
{
    int cont = 0;
    if(string[i] == '\0')
    {
        return 0;
    }
    if(string[i] > 47 && string[i] < 58)
    {
        cont = 1;
    }
    return contaNumeros_rec(string, i+1)+cont;
}
int main()
{
    int v[MAX];
    char str[MAX];
    int qtd, comp, result, n, p;
    
    printf("Digite uma string: ");
    scanf("%[^\n]s", str);
    getchar();
    
    printf("Exercício 1 >\t");
    comp = strComp_rec(str, 0);//Exercício 1
    printf("O comprimento da string é %d\n", comp);
    
    printf("Digite um valor: ");
    scanf("%d", &n);
    
    printf("Exercício 2 >\t");
    result = fibonacci(n);//Exercício 2
    printf("Seu valor correspondente à sequência de Fibonacci é %d\n", result);
    
    printf("Digite o expoente de %d: ", n);
    scanf("%d", &p);
    
    printf("Exercício 3 >\t");
    result = pot_rec(n, p);//Exercício 3
    printf("%d^%d = %d\n", n, p, result);
    
    printf("Exercício 4 >\t");
    imprimeStrRev_rec(str, comp);//Exercício 4
    printf("\n");
    
    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &qtd);
    
    leVetor(v, qtd);
    
    printf("Exercício 5 >\t{");
    imprimeVetor_rec(v, qtd-1);//Exercício 5
    printf("}\n");
    
    printf("Exercício 6 >\t");
    result = contaNumeros_rec(str, 0);//Exercício 6
    printf("A quantidade de números em '%s' é: %d\n", str, result);

    return 0;
}
