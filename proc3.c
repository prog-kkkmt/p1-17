/*Proc4◦
. Описать процедуру TrianglePS(a, P, S), вычисляющую по стороне a
равностороннего треугольника его периметр P = 3·a и площадь S = a2·√3/4
(a — входной, P и S — выходные параметры; все параметры являются ве-
щественными). С помощью этой процедуры найти периметры и площади
трех равносторонних треугольников с данными сторонами.*/

#include <stdio.h>
#include <math.h>
 
void triangleps(float a, float *p, float *s)
{
    *p = 3 * a;
    *s = pow(a,2) * sqrt(3) / 4;
}
 
int main()
{
    int i;
    for(i = 1; i <= 3; ++i){
        float a;
        scanf("%f", &a);
        float p, s;
        triangleps(a, &p, &s);
        printf("%f %f", p, s);
    }
    return 0;
}