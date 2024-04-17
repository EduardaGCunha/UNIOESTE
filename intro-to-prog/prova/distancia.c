#include <stdio.h>
#include <math.h>

int main(){
    int n, m, x, y; scanf("%d %d %d %d", &n, &m, &x, &y);
    
    double d = sqrt(((n - x)*(n - x) + (m - y)*(m - y)));
    printf("%.2lf\n", d);
}