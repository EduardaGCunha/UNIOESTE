#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *prox;
    struct no *ant;
} Lista;

int vazia(Lista *l) {
    return (l == NULL);
}

Lista* inserir(Lista *l, int info) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = info;

    if (vazia(l)) {
        novo->prox = novo;
        novo->ant = novo;
        return novo;
    }

    Lista *ultimo = l->ant; // Último nó antes de inserir o novo nó
    ultimo->prox = novo;
    novo->ant = ultimo;
    novo->prox = l;
    l->ant = novo;

    return l;
}

Lista *remover(Lista *l, int info) {
    if (vazia(l)) return NULL;

    Lista *p = l;

    do {
        if (p->info == info) {
            if (p->prox == p) {  // Caso a lista tenha apenas um elemento
                free(p);
                return NULL;
            }

            // Ajustando os ponteiros dos nós anterior e próximo
            p->ant->prox = p->prox;
            p->prox->ant = p->ant;

            // Se o nó a ser removido é o primeiro da lista, precisamos atualizar o ponteiro da cabeça
            if (p == l) {
                l = p->prox;
            }

            free(p);
            return l;
        }
        p = p->prox;
    } while (p != l);

    // Se o elemento não foi encontrado, retorna a lista sem alterações
    return l;
}

void printar(Lista *l) {
    if (vazia(l)) {
        printf("[]\n");
        return;
    }

    Lista *p = l;
    printf("[");
    do {
        printf("%d", p->info);
        p = p->prox;
        if (p != l) printf(", ");
    } while (p != l);
    printf("]\n");
}

int main() {
    Lista *l = NULL;

    // Inserindo elementos na lista
    l = inserir(l, 1);
    l = inserir(l, 2);
    l = inserir(l, 3);
    l = inserir(l, 4);
    l = inserir(l, 5);

    // Exibindo a lista original
    printf("Lista original: ");
    printar(l);

    // Removendo elementos da lista
    l = remover(l, 3); // Remove o elemento 3
    printf("Após remover 3: ");
    printar(l);

    l = remover(l, 1); // Remove o elemento 1 (primeiro)
    printf("Após remover 1: ");
    printar(l);

    l = remover(l, 5); // Remove o elemento 5 (último)
    printf("Após remover 5: ");
    printar(l);

    l = remover(l, 2); // Remove o elemento 2
    printf("Após remover 2: ");
    printar(l);

    l = remover(l, 4); // Remove o elemento 4 (último restante)
    printf("Após remover 4: ");
    printar(l);

    return 0;
}
