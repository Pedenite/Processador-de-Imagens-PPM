/*Pedro Henrique de Brito Agnes 18/0026305
 Exercicio 5 - Velocidade media*/

#include <stdio.h>

int main()
{
    int me, h0, m0, s0, h, m, s;

    printf("Digite a distancia em metros > ");
    scanf("%d", &me);
    printf("Digite o horario de saida (hh:mm:ss) > ");
    scanf("%d:%d:%d", &h0, &m0, &s0);
    printf("Digite o horario de chegada (hh:mm:ss) > ");
    scanf("%d:%d:%d", &h, &m, &s);
    
    int sec, min, hour;
    float km, ts, tm, t, x;
    km = (float)me/(float)1000;
    sec = s-s0;
    min = m-m0;
    hour = h-h0;
    ts = (float)sec/(float)3600;
    tm = (float)min/(float)60;
    t = hour+ts+tm;
    x = km/t;
    
    printf("A velocidade media foi de %f km/h\n", x);

    return 0;
}
