#include <stdlib.h>
#include "funcoes.h"

int main() {
    FILE *file = fopen("./livro.b", "rb+");
    if (file == NULL) {
        file = fopen("./livro.b", "wb+");
        cria_lista_vazia(file);
    }else{

    }

    int n = -1;
    while(n!= 0){
        menu();
        scanf("%d", &n);
        if(n == 1){
            cadastrar(file);
        }if(n == 2){
            listarLivros(file, 0);
        }
        if(n == 3){
        }
    }

    return 0;
}
