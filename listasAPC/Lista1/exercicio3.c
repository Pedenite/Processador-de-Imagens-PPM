/*Pedro Henrique de Brito Agnes 18/0026305
 Exercicio 3 - Distancia dos pontos no plano cartesiano 2D*/

#include <stdio.h>
#include <math.h>

int main()
{
    int px, py, qx, qy;
    
    printf("Digite as coordenadas no formato px,py,qx,qy ");
    scanf("%d,%d,%d,%d", &px, &py, &qx, &qy);

    int x=(px*px)-(2*px*qx)+(qx*qx);
    int y=(py*py)-(2*py*qy)+(qy*qy);
    int z=x+y;
    float d=sqrt(z);

    printf("a distancia dos pontos eh de %f\n", d);

    return 0;
}
