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
    int prox;              // Posição do próximo nó na lista encadeada
} no;

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
void cria_lista_vazia(FILE* arq);

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
void insere(FILE* arq, LIVRO info);

// Remove o primeiro livro da lista encadeada
// Pré-condição: Arquivo aberto para leitura e escrita
// Pós-condição: Primeiro livro removido da lista e adicionado à lista de registros livres
void retira(FILE* arq);

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

// Lista todos os livros cadastrados no arquivo
// Pré-condição: Arquivo aberto para leitura
// Pós-condição: Todos os livros cadastrados são impressos na saída padrão
void listar(FILE* file);

// Calcula e imprime o número total de livros cadastrados
// Pré-condição: Arquivo aberto para leitura
// Pós-condição: O número total de livros cadastrados é impresso na saída padrão
void calcular_total(FILE *file);

// Carrega informações de livros de um arquivo de texto e os adiciona à lista
// Pré-condição: Arquivo de escrita aberto para leitura e escrita
// Pós-condição: Livros lidos do arquivo de texto são inseridos na lista no arquivo binário
void carregar_arquivo(FILE* file_write);

// Imprime as posições dos registros livres para reúso
// Pré-condição: Arquivo aberto para leitura
// Pós-condição: Posições dos registros livres são impressas na saída padrão
void registros_livres(FILE *file);

// Substitui vírgula por ponto
//Pré-condição: String para mudança;
//Pós-condição: nenhuma
void replace_comma_with_dot(char *str);



#endif // FUNCOES_H
