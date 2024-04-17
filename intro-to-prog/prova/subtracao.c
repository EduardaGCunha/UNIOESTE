#include <stdio.h>

int main()
{
    int A, B, C;
    int sub;
    
    scanf("%d %d %d", &A, &B, &C);
    
    if(A > B && A > C){
        if(B > C){
            sub = A - C;
        }
        else if(C > B){
            sub = A - B;
        }
    }else if(B > A && B > C){
        if(A > C){
            sub = B - C;
        }
        else if(C > A){
            sub = B + C;
        }
    }
    else if(C > A && C > B){
        if(A > B){
            sub = C + A;
        }
        else if(B > A){
            sub = C + B;
        }
    }
    
    printf("%d\n", sub);

    return 0;
}