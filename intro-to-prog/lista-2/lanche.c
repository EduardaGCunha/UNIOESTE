#include <stdio.h>

int main(){
    int n, m; scanf("%d %d", &n, &m);
    switch(n){
        case 1:
            printf("Total: R$ %.2lf\n", 4.00 * m);
            break;
        case 2:
            printf("Total: R$ %.2lf\n", 4.50 * m);
            break;
        case 3:
            printf("Total: R$ %.2lf\n", 5.00 * m);
            break;
        case 4:
            printf("Total: R$ %.2lf\n", 2.00 * m);
            break;
        case 5:
            printf("Total: R$ %.2lf\n", 1.50 * m);
            break;
    }
}