//
// Created by Usuario on 02/09/2024.
//

#include "funcoes.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Escreve o cabeçalho no arquivo
// Pré-condição: Arquivo aberto para escrita, ponteiro de cabeçalho válido
// Pós-condição: Cabeçalho escrito na posição inicial do arquivo
void escreve_cabecalho(FILE* arq, cabecalho* cab){
    fseek(arq,0,SEEK_SET); //posiciona no in´ıcio do arquivo
    fwrite(cab,sizeof(cabecalho),1,arq);
}

// Substitui vírgula por ponto
//Pré-condição: String para mudança;
//Pós-condição: nenhuma
void replace_comma_with_dot(char *str) {
    while (*str) {
        if (*str == ',') {
            *str = '.';
        }
        str++;
    }
}



// Lê o cabeçalho do arquivo
// Pré-condição: Arquivo aberto para leitura
// Pós-condição: Retorna um ponteiro para o cabeçalho lido do arquivo
cabecalho* le_cabecalho(FILE * arq) {
    cabecalho * cab = (cabecalho*) malloc(sizeof(cabecalho));
    fseek(arq,0,SEEK_SET); // posiciona no in´ıcio do arquivo
    fread(cab,sizeof(cabecalho),1,arq);
    return cab;
}

// Cria uma lista vazia no arquivo
// Pré-condição: Arquivo aberto para escrita
// Pós-condição: Arquivo é inicializado com uma lista vazia
void cria_lista_vazia(FILE* arq){
    cabecalho * cab = (cabecalho*) malloc(sizeof(cabecalho));
    cab->pos_cabeca = -1;
    cab->pos_topo = 0;
    cab->pos_livre = -1;
    escreve_cabecalho(arq,cab);
    free(cab);
}

// Escreve um nó no arquivo em uma posição específica
// Pré-condição: Arquivo aberto para escrita, nó válido e posição válida
// Pós-condição: Nó escrito na posição especificada no arquivo
void escreve_no(FILE* arq, no* x, int pos){
    fseek(arq,sizeof(cabecalho)+ pos*sizeof(no),SEEK_SET);
    fwrite(x,sizeof(no),1,arq);
}

// Lê um nó do arquivo em uma posição específica
// Pré-condição: Arquivo aberto para leitura, posição válida
// Pós-condição: Retorna um ponteiro para o nó lido do arquivo
no* le_no(FILE* arq, int pos) {
    no* x = malloc(sizeof(no));
    fseek(arq,sizeof(cabecalho)+ pos*sizeof(no),SEEK_SET);
    fread(x,sizeof(no),1,arq);
    return x;
}

void insere(FILE* arq, LIVRO info){
    cabecalho* cab = le_cabecalho(arq);
    no x;
    x.livro = info;
    x.prox = cab->pos_cabeca;
    if(cab->pos_livre == -1) { // n~ao h´a n´os livres, ent~ao usar o topo
        escreve_no(arq,&x,cab->pos_topo);
        cab->pos_cabeca = cab->pos_topo;
        cab->pos_topo++;
    }
    else { // usar n´o da lista de livres
        no* aux = le_no(arq,cab->pos_livre);
        escreve_no(arq,&x,cab->pos_livre);
        cab->pos_cabeca = cab->pos_livre;
        cab->pos_livre = aux->prox;
        free(aux);
    }
    escreve_cabecalho(arq,cab); free(cab);
}

// Remove um livro da lista com base no código fornecido
// Pré-condição: Arquivo aberto para leitura e escrita, código do livro válido
// Pós-condição: Livro removido da lista, cabeçalho e lista de nós livres atualizados
void retira(FILE* arq){
    int codigo;
    printf("\nDigite o código do livro a ser removido\n");
    scanf("%d", &codigo);

    cabecalho* cab = le_cabecalho(arq);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;
    no* aux = NULL;
    //printf("teste antes do while\n");

    while(pos_aux != -1 && (aux = le_no(arq,pos_aux)) != NULL && aux->livro.codigo != codigo){// procura o elemento a ser retirado
        pos_ant = pos_aux;
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }
    if(pos_aux != -1) { //encontrou o elemento
        if(pos_ant == pos_aux){ // remo¸c~ao na cabe¸ca
            cab->pos_cabeca = aux->prox;
        }
        else { // remo¸c~ao no meio
            no *ant = le_no(arq,pos_ant);
            ant->prox = aux->prox;
            escreve_no(arq,ant,pos_ant);
            free(ant);
        }
        aux->prox = cab->pos_livre; // torna o no removido um no livre
        cab->pos_livre = pos_aux;
        escreve_no(arq,aux,pos_aux);
        escreve_cabecalho(arq,cab);
        free(aux);
        printf("Livro excluído com sucesso!\n");
    } else {
        printf("Livro não encontrado.\n");
    }
    free(cab);
}

// Lê as informações de um livro da entrada padrão
// Pré-condição: Ponteiro LIVRO válido
// Pós-condição: Campos da estrutura LIVRO preenchidos com os valores fornecidos
void ler(LIVRO *l){
    char preco_str[20];
    printf("Digite o código, título, autor, editora, edição, ano, preço e estoque nessa ordem\n");
    scanf("%d%*c", &l->codigo);
    scanf("%150[^\n]%*c", l->titulo);  // Lê até 150 caracteres ou até nova linha
    scanf("%200[^\n]%*c", l->autor);   // Lê até 200 caracteres ou até nova linha
    scanf("%50[^\n]%*c", l->editora);
    scanf("%d%*c", &l->edicao);
    scanf("%d", &l->ano);
    scanf("%19s", preco_str); 
    scanf("%d", &l->estoque);
    replace_comma_with_dot(preco_str);           // Substitui vírgula por ponto
    l->preco = atof(preco_str);  
}

// Imprime as informações de um livro com base no código fornecido
// Pré-condição: Arquivo aberto para leitura, código do livro válido
// Pós-condição: Informações do livro impressas na saída padrão se o livro for encontrado
void imprimir_livro(FILE* file) {
    cabecalho* cab = le_cabecalho(file);
    int codigo;
    printf("\nDigite o código do livro a ser impresso\n");
    scanf("%d", &codigo);

    int pos_aux = cab->pos_cabeca;
    no* aux = NULL;
    while(pos_aux != -1 && ((aux = le_no(file,pos_aux))!= NULL) && aux->livro.codigo != codigo) {// procura o elemento a ser retirado
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }
    if(pos_aux != -1) {
        printf("\n Título: %s;", aux->livro.titulo);
        printf("\n Autor: %s", aux->livro.autor);
        printf("\n Editora: %s", aux->livro.editora);
        printf("\n Edição: %d", aux->livro.edicao);
        printf("\n Ano: %d", aux->livro.ano);
        printf("\n Preço: R$ %.2lf", aux->livro.preco);
        printf("\n Estoque: %d\n\n", aux->livro.estoque);
    }
    else {
        printf("Livro nao encontrado.\n");
    }

    free(cab);
}

// Lista todos os livros cadastrados
// Pré-condição: Arquivo aberto para leitura
// Pós-condição: Informações de todos os livros cadastrados impressas na saída padrão
void listar(FILE* file) {
    cabecalho* cab = le_cabecalho(file);
    int pos_aux = cab->pos_cabeca;
    if (cab->pos_cabeca == -1) {
        printf("Ainda não há livros cadastrados!\n");
        return;
    }
    no* aux = NULL;
    printf("---------------LIVROS CADASTRADOS--------------\n");
    while(pos_aux != -1 && ((aux = le_no(file,pos_aux))!= NULL)) {

        printf("\n Código: %d", aux->livro.codigo);
        printf("\n Título: %s", aux->livro.titulo);
        printf("\n Autor: %s\n", aux->livro.autor);

        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }

    free(cab);
}

// Remove espaços em branco do início e do final de uma string
// Pré-condição: Ponteiro para string válido
// Pós-condição: Retorna a string sem espaços em branco no início e no final
char* trim(char* str) {
    char *end;

    // Remove espaços do início
    while(isspace((unsigned char)*str)) str++;
    // Se a string for toda de espaços
    if(*str == 0)
        return str;
    // Remove espaços do final
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    // Coloca o caractere de fim de string
    *(end + 1) = '\0';
    return str;
}

// Busca por livros de um determinado autor e imprime seus títulos
// Pré-condição: Arquivo aberto para leitura
// Pós-condição: Títulos dos livros encontrados para o autor fornecido são impressos na saída padrão
void busca_por_autor(FILE *file){
    char nome[201];
    cabecalho *cab = le_cabecalho(file);
    int pos_aux = cab->pos_cabeca, encontrou = 0;
    no* aux = NULL;

    printf("Digite o nome do autor a ser buscado\n");
    scanf("%[^\n]%*c", nome);
    nome[strcspn(nome, "\n")] = '\0';
    printf("\nLivros do Autor: %s\n", trim(nome));

    while(pos_aux != -1 && (aux = le_no(file, pos_aux)) !=NULL){
        if (strcmp(aux->livro.autor, trim(nome)) == 0) {
            printf("- %s\n", aux->livro.titulo);
            encontrou = 1;
        }
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }
    if (!encontrou) {
        printf("Nenhum livro encontrado para o autor: %s\n",  trim(nome));
    }
    free(cab);
}

// Busca por um livro com um determinado título e imprime suas informações
// Pré-condição: Arquivo aberto para leitura
// Pós-condição: Informações do livro com o título fornecido são impressas na saída padrão se encontrado
void busca_por_titulo(FILE *file){
    char titulo[201];
    cabecalho *cab = le_cabecalho(file);
    int pos_aux = cab->pos_cabeca, encontrado = 0;
    no* aux = NULL;

    printf("Digite o título do livro a ser buscado\n");
    scanf("%[^\n]%*c", titulo);
    titulo[strcspn(titulo, "\n")] = '\0';

    while(pos_aux != -1 && (aux = le_no(file, pos_aux)) !=NULL){
        if (strcmp(aux->livro.titulo, trim(titulo)) == 0) {
            printf("\nInformações do livro %s\n", trim(titulo));
            printf("%s\n", aux->livro.titulo);
            printf("Código: %d\n", aux->livro.codigo);
            printf("Edicao: %d\n", aux->livro.edicao);
            printf("Autor: %s\n", aux->livro.autor);
            printf("Editora: %s\n", aux->livro.editora);
            printf("Ano: %d\n", aux->livro.ano);
            printf("Preço: R$ %.2lf\n", aux->livro.preco);
            printf("Estoque: %d\n", aux->livro.estoque);
            encontrado = 1;
        }
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }
    if (!encontrado) {
        printf("Nenhum livro com esse título encontrado");
    }
    free(cab);
}

// Calcula e imprime o número total de livros cadastrados
// Pré-condição: Arquivo aberto para leitura
// Pós-condição: O número total de livros cadastrados é impresso na saída padrão
void calcular_total(FILE *file) {
    cabecalho *cab = le_cabecalho(file);
    no *aux = NULL;
    int pos_aux = cab->pos_cabeca;
    int contador = 0;

    while(pos_aux != -1 && (aux = le_no(file, pos_aux)) !=NULL){
        contador++;
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }
    printf("\n O número total de livros cadastrados é: %d\n ", contador);
    free(cab);
}

// Carrega informações de livros de um arquivo de texto e os adiciona à lista
// Pré-condição: Arquivo de escrita aberto para leitura e escrita
// Pós-condição: Livros lidos do arquivo de texto são inseridos na lista no arquivo binário
void carregar_arquivo(FILE* file_write) {
    FILE *file_read = fopen("livro.txt", "r");
    if (file_read == NULL) {
        printf("Não é possível abrir o arquivo.\n");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file_read)) {
        LIVRO livro;
        char *field = NULL;

        line[strcspn(line, "\n")] = '\0';

        field = strtok(line, ";");
        livro.codigo = (field ? atoi(trim(field)) : 0);

        field = strtok(NULL, ";");
        strcpy(livro.titulo, (field ? trim(field) : ""));

        field = strtok(NULL, ";");
        strcpy(livro.autor, (field ? trim(field) : ""));

        field = strtok(NULL, ";");
        strcpy(livro.editora, (field ? trim(field) : ""));

        field = strtok(NULL, ";");
        livro.edicao = (field ? atoi(trim(field)) : 0);

        field = strtok(NULL, ";");
        livro.ano = (field ? atoi(trim(field)) : 0);

        field = strtok(NULL, ";");
        if (field) {
            char *trimmed_field = trim(field); 
            replace_comma_with_dot(trimmed_field);  // Substitui vírgula por ponto
            livro.preco = atof(trimmed_field);  // Converte para double
        } else {
            livro.preco = 0.0;
        }

        field = strtok(NULL, ";");
        livro.estoque = (field ? atoi(trim(field)) : 0);

        insere(file_write, livro); // Adiciona o livro à lista
    }
    printf("Arquivo .txt cadastrado com sucesso\n");

    fclose(file_read);
}


// Imprime as posições dos registros livres para reúso
// Pré-condição: Arquivo aberto para leitura
// Pós-condição: Posições dos registros livres são impressas na saída padrão
void registros_livres(FILE *file) {
    cabecalho *cab = le_cabecalho(file);
    int pos_aux = cab->pos_livre;

    if (pos_aux == -1) {
        printf("Não há registros livres para reúso.\n");
        free(cab);
        return;
    }

    while(pos_aux != -1) {
        no* livre = le_no(file, pos_aux);
        printf("\nO registro de posição %d está disponível para uso\n", pos_aux);
        pos_aux = livre->prox;
        free(livre);
    }
    free(cab);
}

// Exibe o menu de opções para o usuário
// Pré-condição: Nenhuma
// Pós-condição: Menu de opções exibido na saída padrão
void menu(){
    printf("\n-----------MENU--------------\n");
    printf("Digite 1 para cadastrar um livro.\n");
    printf("Digite 2 para remover as informações de um livro.\n");
    printf("Digite 3 para imprimir dados de um livro.\n");
    printf("Digite 4 para listar todos os livros.\n");
    printf("Digite 5 para buscar livros de algum autor.\n");
    printf("Digite 6 para buscar por algum livro.\n");
    printf("Digite 7 para calcular o total de livros cadastrados\n");
    printf("Digite 8 para carregar livros.\n");
    printf("Digite 9 para imprimir lista de registros livres\n");
    printf("Digite 0 para sair do menu.\n");
    printf("----------------------------\n");
}