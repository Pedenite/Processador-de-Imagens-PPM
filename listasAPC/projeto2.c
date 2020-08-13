/* Algoritmos e Programação de Computadores - 1/2018
 * Aluno: Pedro Henrique de Brito Agnes
 * Matrícula: 18/0026305
 * Turma: B
 * Descrição: O algoritmo abre uma imagem do formato ppm em disco e a modifica de acordo com o valor de K dado pelo usuário e, por fim, salva a imagem em disco
 * Para compilar: gcc nome.c -lm -o Nome */
#include <stdio.h>
#include <math.h>
#include <string.h>

/* A matriz será muito grande, causando falha de segmentação se estiver dentro de uma função a menos que se utilize alocação dinâmica. Portanto, já que isso não é cobrado, usa-se variável global */
int I[2000][2000][4];
/* O número 4 no final é para que o índice 0 seja R, 1 = G, 2 = B e o 3 para a atribuição de classe para o processamento da imagem */
struct imagem
{
    char id[3];
    int n;
    int m;
    int l;
    
};
typedef struct imagem img;
/* Opção 1 */
void openPPM(img *Img)
{
    FILE *fp;
    char file_name[201];
    int i, j, k;
    
    printf("Digite o nome do arquivo: ");
    scanf("\n%[^\n]s", file_name);
    
    fp = fopen(file_name, "r");
    
    if(fp == NULL)
    {
        printf("\nERRO: o arquivo '%s' não existe!\n", file_name);
    }
    else
    {/*O algoritmo não funcionará se houver um comentário na imagem*/
        fscanf(fp,"%s %d %d %d", Img->id, &Img->n, &Img->m, &Img->l);
        
        /* Verificação para saber se o arquivo é válido para o algoritmo */
        if(strcmp(Img->id, "P3") != 0)
        /* Aqui é comparado a string com 'P3' para ver se há diferença entre eles com a função strcmp da biblioteca string.h */
        {
            printf("ERRO: Identificador '%s' inválido!\n", Img->id);
            fclose(fp);
            return ;
        }
        /* Essa comparação é para que o arquivo não passe da resolução 2000x2000 */
        if(Img->n > 2000||Img->m > 2000)
        {
            printf("ERRO: Esse Arquivo de %dx%d é muito grande! A resolução máxima é de 2000x2000 pixels\n", Img->n, Img->m);
            fclose(fp);
            return ;
        }
        
        for(i = 0; i != Img->n; i++)
        {
            for(j = 0; j != Img->m; j++)
            {
                for(k = 0; k != 3; k++)
                {
                    fscanf(fp,"%d", &I[i][j][k]);
                }
            }
        }
        printf("\nSucesso!\n");
    }
    fclose(fp);
}
/* Opção 2 */
void processPPM(img *Img)
{
    int K, x, y, i, l, D, m, me, t, T;
    int c[100][3], C[100];
    char color;
    
    printf("Digite o valor de K: ");
    scanf("%d", &K);
    while(K < 2 || K > 100)
    {
        printf("ERRO: 2<=K<=100\nRedigite o valor de K: ");
        scanf("%d", &K);
    }
    for(i = 0; i != K; i++)
    {
        for(l = 0; l != 3; l++)
        {
            if(l == 0)
            {
                color = 'R';
            }
            if(l == 1)
            {
                color = 'G';
            }
            if(l == 2)
            {
                color = 'B';
            }
            printf("Digite um valor para c%d %c: ", i+1, color);
            scanf("%d", &c[i][l]);
            while(c[i][l] < 0 || c[i][l] > Img->l)
            {
                printf("ERRO: 0<=c<=255\nRedigite o valor de c%d %c: ", i+1, color);
                scanf("%d", &c[i][l]);
            }
        }
    }
    /* A todas as classes será atribuído o valor 0 referente á quantidade de pixels pertencentes a elas */
    for(i = 0; i != K; i++)
    {
        C[i] = 0;
    }
    for(x = 0; x != Img->n; x++)
    {
        for(y = 0; y != Img->m; y++)
        {
            m = 100000;
            for(i = 0; i != K; i++)
            {
                D = 0;
                for(l = 0; l != 3; l++)
                {
                    D = D + pow((I[x][y][l]-c[i][l]), 2);
                }
                D = sqrt(D);
                if(D < m)
                {
                    m = D;
                    me = i;
                }
            }
            /* O '3' no lugar do l é para atribuir a classe */
            I[x][y][3] = me;
            C[me] = C[me] + 1;
        }
    }
    for(i = 0; i != K; i++)
    {
        printf("Pixels pertencentes ao agrupamento C[%d]: %d\n", i+1, C[i]);
    }
    for(i = 0; i != K; i++)
    {
        for(l = 0; l != 3; l++)
        {
            c[i][l] = I[0][0][l];
            for(x = 0; x != Img->n; x++)
            {
                for(y = 1; y != Img->m; y++)
                {
                    if(I[x][y][3] == i)
                    {
                        /* Aqui será calculada a média de todos os pixels das classes */
                        c[i][l] = c[i][l] + I[x][y][l];
                    }
                }
            }
            if(C[i] != 0)
            {
                c[i][l] = c[i][l]/C[i];
            }
        }
    }
    for(i = 0; i!= K;i++)
    {
        for(l = 0; l!= 3;l++)
        {
            printf("%d ", c[i][l]);
        }
    }
    /* Agora será mudado o valor de cada pixel com base na média de sua classe */
    for(i = 0; i != K; i++)
    {
        for(x = 0; x != Img->n; x++)
        {
            for(y = 0; y != Img->m; y++)
            {
                if(I[x][y][3] == i)
                {
                    for(l = 0; l != 3; l++)
                    {
                        I[x][y][l] = c[i][l];
                    }
                }
            }
        }
    }
    printf("\n\nConcluído!\n");
}
/* Opcão 3 */
void savePPM(img *Img)
{
    FILE *fp;
    char nome[201];
    int i, j, k;
    
    printf("Digite o nome do novo arquivo (seguido do formato .ppm): ");
    scanf("\n%[^\n]s", nome);
    
    fp = fopen(nome, "w");
    
    fprintf(fp,"%s\n%d %d\n%d\n", Img->id, Img->n, Img->m, Img->l);
    for(i = 0; i != Img->n; i++)
    {
        for(j = 0; j != Img->m; j++)
        {
            for(k = 0; k != 3; k++)
            {
                fprintf(fp,"%d ", I[i][j][k]);
            }
        }
    }
    printf("\nSalvo com sucesso!\n");
    fclose(fp);
}

int menu()
{
    int option = -1;
    
    printf("\n1 = Abrir uma imagem em disco\n2 = Processar a imagem\n3 = Salvar a imagem processada em disco\n0 = Sair\n\nDigite o que deseja fazer >>> ");
    scanf("%d", &option);
    while(option != 1 && option != 2 && option != 3 && option != 0)
    {
        printf("ERRO: Opção inexistente\nDigite novamente >>> ");
        scanf("%d", &option);
    }
    return option;
}

int main()
{
    img Imagem;
    int opt = -1;
    
    while(opt != 0)
    {
        opt = menu();
        if(opt == 1)
        {
            openPPM(&Imagem);
        }
        if(opt == 2)
        {
            processPPM(&Imagem);
        }
        if(opt == 3)
        {
            savePPM(&Imagem);
        }
    }
       
    return 0;
}
