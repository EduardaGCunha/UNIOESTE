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
typedef struct no {
    LIVRO livro; 
    int cod;          // Informações do livro
    int esq;
    int dir;    
} no;

FILE* inicializa_arqbin(char* file_name);

void inicializarLivro(FILE* fb);

void escreve_no(FILE* arq, no* x, int pos);

no* le_no(FILE* arq, int pos);

void escreverCabecalho(FILE* fb, cabecalho* cab);

cabecalho* lerCabecalho(FILE* fb);

void cria_lista_vazia(FILE* arq);

int vazio(cabecalho *cab);

void menu();
int busca(FILE *arq, int pos_p, int pos, int cod);
void listarLivros(FILE *arq, int pos);
void cadastrar(FILE *arq);

#endif // FUNCOES_H
