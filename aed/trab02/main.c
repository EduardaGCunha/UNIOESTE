#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main() {
    FILE *file = fopen("./livro.b", "rb+");
    if (file == NULL) {
        file = fopen("./livro.b", "wb+");
        cria_arvore_vazia(file);
    }


    int n = 100;
    while(n != 0) {
        menu();
        scanf("%d%*c", &n);
        if(n == 1) {
            LIVRO livro;
            ler(&livro);
            insere_arvore(file, livro);
        }else if(n == 2) {
            remove_arvore(file);
        }else if(n == 3) {
            imprimir_livro(file);
        }else if(n == 4) {
            listar(file);
        }else if(n == 5) {
            busca_por_autor(file);
        }else if(n == 6){
            busca_por_titulo(file);
        }else if(n == 7){
            calcular_total(file);
        }else if(n == 8) {
            carregar_arquivo(file);
        }else if(n == 9){
            registros_livres(file);
        }else if(n == 10){
            imprimir_arvore_por_niveis(file);
        }else if(n == 11){
            imprimir_arvore_formatada(file);
        }else if(n!=0){
            printf("Código inválido. Tente novamente.\n");
        }
    }
    return 0;
}