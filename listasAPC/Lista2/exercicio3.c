/*Pedro Henrique de Brito Agnes 180026305
 Exercicio 3 - IMC*/

#include <stdio.h>

int main()
{
    float kg, h, R;
    
    printf("Indique o seu peso em kg: ");
    scanf("%f", &kg);
    printf("Indique a sua altura em m: ");
    scanf("%f", &h);
    
    R = kg/(h*h);
    
    printf("Seu IMC é %f\n", R);
    
    if(R<18)
    {
        printf("Vc está abaixo do peso\n");
    }
    else
    {
        if(R>=18 && R<25)
        {
            printf("Vc está saudável\n");
        }
        else
        {
            if(R>=25 && R<30)
            {
                printf("Vc está com peso em excesso\n");
            }
            else
            {
                if(R>=30 && R<35)
                {
                    printf("Vc está obeso\n");
                }
                else
                {
                    if(R>=35 && R<40)
                    {
                        printf("Vc está com obesidade severa\n");
                    }
                    else
                    {
                        printf("Vc está com obesidade mórbida\n");
                    }
                }
            }
        }
    }
    
    return 0;
}
