/* Pedro Henrique de Brito Agnes 18/0026305
 * Exercícios de string */

#include <stdio.h>
#define MAX 100

/* Exercicio 1: Funcao que calcula e retorna o comprimento de uma string 
 Argumento 1: a string(cadeia de caracteres) - passado por referencia  */
int str_length(char str[])
{
    printf("Exercício 1 >\t");
    int i = 0;
    
    while(str[i]!='\0')//Usado para chegar ao final da string
    {
        i++;
    }
    
    return i;
}

/* Exercicio 2 */
int str_toInt(char str[], long long int *number)
{
    printf("Exercício 2 >\t");
    int i = 0, j, asc;
    long long int m = 1;
    
    while(str[i] != '\0')
    {
        i++;
    }
    i--;
    
    for(j = i; j >= 0; j--)
    {
        asc = str[j]-48;
        if(asc < 0 || asc > 9)
        {
            return 0;//Falhou: algum caractere da string não é numérico
        }
        *number = *number+asc*m;
        m = m*10;
    }
    return 1;//Sucesso: converteu o número de string para inteiro
}

/* Exercício 3 */
int str_search(char str[], char chave)
{
    printf("Exercício 3 >\t");
    int i, j = -1;
    
    for(i = 0; str[i] != '\0'; i++);//Vai ao final da string
    while(i >= 0)//Se houver mais de 1 ocorrência de chave, retorna-se a 1ª
    {
        if(str[i] == chave)
        {
            j = i;
        }
        i--;
    }
    return j;
}

/* Exercicio 4 */
void str_copylowercase(char str_orig[], char str_minusc[])
{
    printf("Exercício 4 >\t");
    int i, asc;
    for(i = 0; str_orig[i] != '\0'; i++)
    {
        asc = str_orig[i];
        if(asc >= 65 && asc <= 90)
        {
            asc = asc+32;
        }
        str_minusc[i] = asc;
    }
    printf("Transforma '%s' em '%s'\n", str_orig, str_minusc);
}

/* Exercício 5 */
int str_lexico(char str1[], char str2[])
{
    printf("Exercício 5 >\t");
    int y = 0, i, asc, ASC;
    for(i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
    {
        if(str1[i] != str2[i])
        {
            asc = str1[i];
            ASC = str2[i];
            y = asc-ASC;
            return y;
        }
    }
    return y;
}

/* Exercicio 6 */
int str_cont(char str1[], char str2[])
{
    printf("Exercício 6 >\t");
    int i, j, y = -1;
    for(i = 0; str1[i] != '\0'; i++)
    {
        if(str2[0] == str1[i])
        {
            for(j = 0; str2[j] != '\0'; j++)
            {
                if(str2[j] == str1[j+i])
                {
                    y = i;
                }
                else
                {
                    return -1;
                }
            }
        }
    }
    return y;
}

int main()
{
    char string[MAX], string2[MAX], chav;
    int comp, res;
    long long int n;

    printf("Digite uma string: ");
    scanf("\n%[^\n]s", string);
    
    comp = str_length(string);//Exercicio 1
    printf("Comprimento de '%s': %d\n",string,comp);
        
    n = 0;
        
    res = str_toInt(string, &n);//Exercicio 2
    if(res == 1)
    {
        printf("Converte '%s' em %lld\n", string, n);
    }
    else
    {
        printf("ERRO: '%s' não é um número válido\n", string);
    }
    
    printf("Informe um caractere a ser denotado por chave: ");
    scanf("\n%c", &chav);
    
    res = str_search(string, chav);//Exercicio 3
    if(res >= 0)
    {
        printf("A ocorrência de '%c' deu-se no índice %d\n", chav, res);
    }
    else
    {
        printf("'%c' não se encontra em '%s'\n", chav, string);
    }
    
    str_copylowercase(string, string2);//Exercício 4
    
    printf("Digite uma segunda string: ");
    scanf("\n%[^\n]s", string2);
    
    res = str_lexico(string, string2);//Exercicio 5
    printf("De acordo com a comparação lexicográfica, y = %d\n", res);
    
    res = str_cont(string, string2);//Exercício 6
    if(res == -1)//No exercício diz que deve ser 0, porém seria inconveniente já que se a 2ª string começar no índice 0 da 1ª, mesmo que pertença à 1ª, será imprimido que não exite nela
    {
        printf("A string '%s' não existe em '%s'\n", string2, string);
    }
    else
    {
        printf("A string '%s' se encontra a partir do índice %d em '%s'\n", string2, res, string);
    }
    
    return 0;
}
