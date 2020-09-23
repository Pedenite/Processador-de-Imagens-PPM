/* Algoritmos e Programação de Computadores - 1/2018
 * Aluno: Pedro Henrique de Brito Agnes
 * Matrícula: 18/0026305
 * Turma: B
 * Descrição: O algoritmo abre uma imagem do formato ppm em disco e a modifica de acordo com o valor de K dado pelo usuário e, por fim, salva a imagem em disco */
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX_W 4000
#define MAX_H 2500

/* A matriz será muito grande, causando falha de segmentação se estiver dentro de uma função a menos que se utilize alocação dinâmica. Portanto, já que isso não é cobrado, usa-se variável global */
int I[MAX_W][MAX_H][4];
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
    char file_name[201], a, b[10], c[5], d[10];
    int i, j, k;
    
    printf("Digite o nome do arquivo: ");
    scanf("\n%[^\n]s", file_name);
    
    fp = fopen(file_name, "r");
    
    if(fp == NULL)
    {
        printf("\nERRO: o arquivo '%s' não existe!\n", file_name);
        return ;
    }
    else
    {/* comentário do irfanview: %c %s %s %s depois do %s | &a, b, c, d,*/
        fscanf(fp,"%s %d %d %d", Img->id, &Img->n, &Img->m, &Img->l);
        
        /* Verificação para saber se o arquivo é válido para o algoritmo */
        if(strcmp(Img->id, "P3") != 0)
        /* Aqui é comparado a string com 'P3' para ver se há diferença entre eles com a função strcmp da biblioteca string.h */
        {
            printf("ERRO: Identificador '%s' inválido!\n", Img->id);
            fclose(fp);
            return ;
        }
        /* Essa comparação é para que o arquivo não passe da resolução máxima ([MAX_W]x[MAX_H]) */
        if(Img->n > MAX_W||Img->m > MAX_H)
        {
            printf("ERRO: Esse Arquivo de %dx%d é muito grande! A resolução máxima é de %dx%d pixels\n", Img->n, Img->m, MAX_W, MAX_H);
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
    /* Imprime o comentário do irfanview */
    /*printf("%c ", a);
    printf("%s ", b);
    printf("%s ", c);
    printf("%s\n", d);*/
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
                printf("ERRO: 0<=c<=%d\nRedigite o valor de c%d %c: ", Img->l, i+1, color);
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
/* Opção 3 */
void contraPPM(img *Img)
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
                printf("ERRO: 0<=c<=%d\nRedigite o valor de c%d %c: ", Img->l, i+1, color);
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
/* Opção 4 */
void insatPPM(img *Img)
{
    int x, y;
    for(x = 0; x != Img->n; x++)
    {
        for(y = 0; y != Img->m; y++)
        {
            I[x][y][0] = (I[x][y][0]+I[x][y][1]+I[x][y][2])/3;
            I[x][y][1] = (I[x][y][0]+I[x][y][1]+I[x][y][2])/3;
            I[x][y][2] = (I[x][y][0]+I[x][y][1]+I[x][y][2])/3;
        }
    }
    printf("\n\nConcluído!\n");
}
/* Opção 5 */
void pebPPM(img *Img)
{
    int x, y;
    for(x = 0; x != Img->n; x++)
    {
        for(y = 0; y != Img->m; y++)
        {
            I[x][y][0] = (I[x][y][0]+I[x][y][1]+I[x][y][2])/3;
            I[x][y][1] = I[x][y][0];
            I[x][y][2] = I[x][y][0];
        }
    }
    printf("\n\nConcluído!\n");
}
/* Opção 6 */
void negPPM(img *Img)
{
    int x, y, z;
    for(x = 0; x != Img->n; x++)
    {
        for(y = 0; y != Img->m; y++)
        {
            for(z = 0; z != 3; z++)
            {
                I[x][y][z] = Img->l - I[x][y][z];
            }
        }
    }
    printf("\n\nConcluído!\n");
}
/* Opção 7 */
void espPPM(img *Img)
{
    int x, y, z, i;
    if(Img->m%2 != 0)
    {
        Img->m = Img->m-1;
    }
    for(x = 0; x != Img->n; x++)
    {
        i = Img->m/2;
        for(y = i; y != Img->m; y++)
        {
            for(z = 0; z != 3; z++)
            {
                I[x][y][z] = I[x][i][z];
            }
            i--;
        }
    }
    printf("\n\nConcluído!\n");
}
/* Opcão 9 */
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
    /*int i, j, k;*/
    
    printf("\n1 = Abrir uma imagem em disco\n2 = Processar a imagem\n3 = Processa a imagem ao contrário\n4 = Diminui a saturação da imagem\n5 = Preto e branco\n6 = Negativo\n7 = Espelho\n9 = Salvar a imagem processada em disco\n0 = Sair\n\nDigite o que deseja fazer >>> ");
    scanf("%d", &option);
    while(option > 9 || option < 0)
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
            contraPPM(&Imagem);
        }
        if(opt == 4)
        {
            insatPPM(&Imagem);
        }
        if(opt == 5)
        {
            pebPPM(&Imagem);
        }
        if(opt == 6)
        {
            negPPM(&Imagem);
        }
        if(opt == 7)
        {
            espPPM(&Imagem);
        }
        if(opt == 9)
        {
            savePPM(&Imagem);
        }
        /*printf("%s\n", Imagem->id);
        printf("%d %d\n", Imagem->n, Imagem->m);
        printf("%d\n", Imagem->l);
        
        for(i = 0; i != Imagem->n; i++)
        {
            for(j = 0; j != Imagem->m; j++)
            {
                for(k = 0; k != 3; k++)
                {
                    printf("%d ", rgb[i][j][k]);
                }
            }
        }*/
    }
       
    return 0;
}
