//
// Created by Usuario on 02/09/2024.
//

#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>

// Estrutura que representa um livro no sistema
typedef struct {
    int codigo;            // Código identificador do livro
    char titulo[151];      // Título do livro
    char autor[201];       // Autor do livro
    char editora[51];      // Editora do livro
    int edicao;            // Número da edição
    int ano;               // Ano de publicação
    double preco;          // Preço do livro
    int estoque;           // Quantidade em estoque
} LIVRO;

// Estrutura que representa o cabeçalho do arquivo binário
typedef struct {
    int pos_cabeca;        // Posição da cabeça da lista no arquivo
    int pos_topo;          // Posição do topo do arquivo (para novas inserções)
    int pos_livre;         // Posição da lista de registros livres (para reutilização)
} cabecalho;

// Estrutura que representa um nó da lista encadeada de livros
typedef struct {
    LIVRO livro;           // Informações do livro
    int esq;              //
    int dir;              //
}no;

typedef struct node {
    int pos;                     // Posição do nó no arquivo
    struct node* next;
} noFila;

typedef struct Queue {
    noFila* front;
    noFila* rear;
} Fila;

// Exibe o menu de opções para o usuário
// Pré-condição: Nenhuma
// Pós-condição: Menu de opções exibido na saída padrão
void menu();

// Escreve o cabeçalho no início do arquivo
// Pré-condição: Arquivo aberto para leitura e escrita, ponteiro do cabeçalho não nulo
// Pós-condição: Cabeçalho gravado no início do arquivo
void escreve_cabecalho(FILE* arq, cabecalho* cab);

// Lê o cabeçalho do arquivo e retorna um ponteiro para ele
// Pré-condição: Arquivo aberto para leitura
// Pós-condição: Cabeçalho lido do arquivo e retornado
cabecalho* le_cabecalho(FILE * arq);

// Cria uma lista encadeada vazia no arquivo
// Pré-condição: Arquivo aberto para leitura e escrita
// Pós-condição: Lista encadeada vazia criada e gravada no arquivo
void cria_arvore_vazia(FILE* arq);

// Escreve um nó da lista encadeada no arquivo na posição especificada
// Pré-condição: Arquivo aberto para leitura e escrita, ponteiro do nó não nulo
// Pós-condição: Nó gravado na posição especificada no arquivo
void escreve_no(FILE* arq, no* x, int pos);

// Lê um nó da lista encadeada do arquivo a partir da posição especificada
// Pré-condição: Arquivo aberto para leitura, posição válida
// Pós-condição: Nó lido do arquivo e retornado, ou NULL se a leitura falhar
no* le_no(FILE* arq, int pos);

// Insere um novo livro na lista encadeada
// Pré-condição: Arquivo aberto para leitura e escrita, livro válido fornecido
// Pós-condição: Livro inserido na lista encadeada no arquivo
void insere_arvore(FILE* arq, LIVRO info);

// Função auxiliar para encontrar o maior nó na subárvore esquerda
//Pré-condição: arq deve estar aberto para leitura, e posicao é a posição do nó inicial para busca.
//Pós-condição: Retorna a posição do maior nó encontrado na subárvore; ajusta as ligações na árvore caso o maior nó tenha um filho esquerdo.
int busca_menor(FILE* arq, int pos);

// Remove o primeiro livro da lista encadeada
// Pré-condição: Arquivo aberto para leitura e escrita
// Pós-condição: Primeiro livro removido da lista e adicionado à lista de registros livres
void remove_arvore(FILE* arq);

// Lê os dados de um livro do usuário
// Pré-condição: Ponteiro para LIVRO válido
// Pós-condição: Dados do livro lidos e armazenados na estrutura LIVRO
void ler(LIVRO *l);

// Imprime as informações de um livro
// Pré-condição: Arquivo aberto para leitura
// Pós-condição: Informações do livro são impressas na saída padrão
void imprimir_livro(FILE* file);

// Remove os espaços em branco no início e no final de uma string
// Pré-condição: Ponteiro para string válido
// Pós-condição: String modificada para remover espaços em branco extras
char* trim(char* str);

// Busca por livros de um determinado autor e imprime seus títulos
// Pré-condição: Arquivo aberto para leitura
// Pós-condição: Títulos dos livros encontrados para o autor fornecido são impressos na saída padrão
void busca_por_autor(FILE *file);

// Busca por um livro com um determinado título e imprime suas informações
// Pré-condição: Arquivo aberto para leitura
// Pós-condição: Informações do livro com o título fornecido são impressas na saída padrão se encontrado
void busca_por_titulo(FILE *file);

//Percorre a lista em inorder.
//Pré-condição: file deve estar aberto para leitura.
//Pós-condição: Exibe os livros cadastrados na árvore, em ordem.
void listar_em_ordem(FILE* file, int pos_atual);

// Lista todos os livros cadastrados no arquivo
// Pré-condição: Arquivo aberto para leitura
// Pós-condição: Todos os livros cadastrados são impressos na saída padrão
void listar(FILE* file);

// Calcula e imprime o número total de livros cadastrados
// Pré-condição: Arquivo aberto para leitura
// Pós-condição: O número total de livros cadastrados é impresso na saída padrão
void calcular_total(FILE *file);

//Função auxiliar para calcular o total de livros cadastrados.
//Pré-condição: file deve estar aberto para leitura; pos_atual é uma posição válida de um nó ou -1.
//Pós-condição: Retorna o total de nós a partir de pos_atual.
int calcular_total_aux(FILE* file, int pos_atual);

// Carrega informações de livros de um arquivo de texto e os adiciona à lista
// Pré-condição: Arquivo de escrita aberto para leitura e escrita
// Pós-condição: Livros lidos do arquivo de texto são inseridos na lista no arquivo binário
void carregar_arquivo(FILE* file_write);

// Imprime as posições dos registros livres para reúso
// Pré-condição: Arquivo aberto para leitura
// Pós-condição: Posições dos registros livres são impressas na saída padrão
void registros_livres(FILE *file);

//Pré-condição: q deve ser um ponteiro válido para uma estrutura de fila.
//Pós-condição: Inicializa a fila vazia.
void initQueue(Fila* q);

// Função para verificar se a fila está vazia
//Pré-condição: q deve ser um ponteiro válido para uma estrutura de fila inicializada.
//Pós-condição: Retorna 1 se a fila estiver vazia, 0 caso contrário.
int isEmpty(Fila* q);

// Função para adicionar um elemento à fila
//Pré-condição: q deve ser um ponteiro válido para uma estrutura de fila inicializada.
//Pós-condição: Insere um novo elemento com pos na fila q.
void enqueue(Fila* q, int pos);

// Função para remover um elemento da fila
//Pré-condição: q deve ser um ponteiro válido para uma estrutura de fila inicializada e não vazia.
//Pós-condição: Remove e retorna o primeiro elemento da fila q.
int dequeue(Fila* q);

// Função para imprimir a árvore binária por níveis
void imprimir_arvore_por_niveis(FILE* arq);

// Função auxiliar para imprimir a árvore formatada como lista
//Pré-condição: arq deve estar aberto e ser um arquivo binário contendo a estrutura de uma árvore binária.
//Pós-condição: A árvore é exibida em formato de lista no console, onde cada nó é representado com seu código.
void imprimir_arvore_como_lista(FILE* arq, int pos);


// Função principal para imprimir a árvore
//Pré-condição: arq deve estar aberto e ser um arquivo binário contendo a estrutura de uma árvore binária.
//Pós-condição: A árvore é impressa no console no formato de lista. Se a árvore estiver vazia, exibe uma mensagem indicando isso.
void imprimir_arvore_formatada(FILE* arq);


#endif // FUNCOES_H
