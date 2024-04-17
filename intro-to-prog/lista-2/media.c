#include <stdio.h>

int main(){
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    double media = (2*a + 3*b + 4*c + 1*d)/10;

    printf("Media: %.1lf\n", media);
    if(media > 7.0){
        printf("Aluno aprovado.\n");
        return 0;
    }else if (media < 5.0){
        printf("Aluno reprovado.\n");
        return 0;
    }
    printf("Aluno em exame.\n");
    double e;
    scanf("%lf", &e); 
    printf("Nota do exame: %.1lf\n", e);
    media = (media + e)/2;
    if(media > 4.9){
        printf("Aluno aprovado.\n");
        printf("Media final: %.1lf\n", media);
        return 0;
    }
    printf("Aluno reprovado.\n");
    
}