#include <stdio.h>
#include <string.h>

void substituirPalavra(char *string, char *referencia, char *troca) {
    char *posicao = string;
    while ((posicao = strstr(posicao, referencia)) != NULL) {
        strncpy(posicao, troca, strlen(troca)); // Substitui a palavra de referência pela palavra de troca
        posicao += strlen(troca); // Avança a posição para continuar a busca
    }
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char referencia[101], troca[101];
        scanf("%s %s", referencia, troca);

        char texto[1001];
        getchar(); // Limpar o buffer de entrada
        fgets(texto, sizeof(texto), stdin);

        substituirPalavra(texto, referencia, troca);
        printf("%s", texto);
    }

    return 0;
}
