#include <stdio.h>
#include <math.h>

int main(){
    float x1, x2, y1, y2;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    float a = x2 - x1;
    float b = y2 - y1;
    float distance = sqrt(a*a + b*b);
    printf("%.4lf\n", distance);
}
