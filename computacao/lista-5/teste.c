/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef struct{
    char nome[MAX];
    int idade;
}PESSOA;

void lerqtd(int *qtd){
    scanf("%d%*c", qtd);
}

void lerpessoa(int qtd, PESSOA pessoa[]){
    int i;
    for(i=0;i<qtd;i++){
        
        scanf("%[^0-9]", pessoa[i].nome);
        scanf("%d%*c", &pessoa[i].idade);
    }
}
void troca(PESSOA *pessoa1, PESSOA *pessoa2){
    PESSOA aux = *pessoa1;
    *pessoa1 = *pessoa2;
    *pessoa2 = aux;
}

void printpessoa(int qtd, PESSOA pessoa[]){
    int i;
    for(i=0;i<qtd;i++){
        printf("NOME: %-15s",pessoa[i].nome);
        printf("IDADE: %d\n", pessoa[i].idade);
    }

    printf("\n");

}
void ordenarnomes(int qtd, PESSOA pessoa[]){
    int i,j;
    for(i=0;i<qtd;i++){
        for(j=i+1;j<qtd;j++){
            if(strcmp(pessoa[i].nome,pessoa[j].nome)>0){
                troca(&pessoa[i], &pessoa[j]);
            }
        }
    }
}

int main() {

    PESSOA pessoa [100];
    
    int qtd;

    lerqtd(&qtd);
    
    lerpessoa(qtd,pessoa);
    printpessoa(qtd, pessoa);
    
    // ordenarnomes(qtd,pessoa);
    // printpessoa(qtd, pessoa);
    
    return 0;
}

