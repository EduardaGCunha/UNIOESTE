#include "funcoes.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Escreve o cabeçalho no arquivo
//Pré-condição: arq deve ser um arquivo aberto para escrita, e cab deve ser um ponteiro válido para uma estrutura de cabeçalho inicializada.
//Pós-condição: O cabeçalho é escrito no início do arquivo arq.
void escreve_cabecalho(FILE* arq, cabecalho* cab) {
    fseek(arq, 0, SEEK_SET);
    fwrite(cab, sizeof(cabecalho), 1, arq);
}

// Lê o cabeçalho do arquivo
//Pré-condição: arq deve ser um arquivo aberto para leitura.
//Pós-condição: Retorna um ponteiro para uma estrutura de cabeçalho lida do arquivo.
cabecalho* le_cabecalho(FILE* arq) {
    cabecalho * cab = (cabecalho*) malloc(sizeof(cabecalho));
    fseek(arq, 0, SEEK_SET);
    fread(cab, sizeof(cabecalho), 1, arq);
    return cab;
}

// Cria uma árvore binária vazia no arquivo
//Pré-condição: arq deve ser um arquivo aberto para escrita.
//Pós-condição: Um cabeçalho inicializado de árvore binária vazia é escrito no início do arquivo arq.
void cria_arvore_vazia(FILE* arq) {
    cabecalho * cab = (cabecalho*) malloc(sizeof(cabecalho));
    cab->pos_cabeca = -1;
    cab->pos_topo = 0;
    cab->pos_livre = -1;
    escreve_cabecalho(arq, cab);
    free(cab);
}

// Escreve um nó na posição específica
//Pré-condição: arq deve estar aberto para escrita; x é um ponteiro válido para um nó inicializado e pos é uma posição válida para escrita no arquivo.
//Pós-condição: O nó x é escrito no arquivo na posição especificada por pos.
void escreve_no(FILE* arq, no* x, int pos) {
    fseek(arq, sizeof(cabecalho) + pos * sizeof(no), SEEK_SET);
    fwrite(x, sizeof(no), 1, arq);
}

// Lê um nó do arquivo em uma posição específica
//Pré-condição: arq deve estar aberto para leitura e pos é uma posição válida onde um nó está armazenado.
//Pós-condição: Retorna um ponteiro para um nó lido da posição pos no arquivo.
no* le_no(FILE* arq, int pos) {
    no* x = malloc(sizeof(no));
    fseek(arq, sizeof(cabecalho) + pos * sizeof(no), SEEK_SET);
    fread(x, sizeof(no), 1, arq);
    return x;
}

// Insere um novo nó na árvore binária
//Pré-condição: arq deve estar aberto para leitura e escrita; info deve conter as informações do livro a serem inseridas.
//Pós-condição: Um novo nó contendo info é inserido na árvore binária no arquivo.
void insere_arvore(FILE* arq, LIVRO info) {
    cabecalho* cab = le_cabecalho(arq);
    no* novo_no = (no*) malloc(sizeof(no));
    novo_no->livro = info;
    novo_no->esq = -1;
    novo_no->dir = -1;

    int pos_atual = cab->pos_cabeca;
    int pos_anterior = -1;
    int direcao = 0; // 0 -> root, -1 -> esq, 1 -> dir

    while (pos_atual != -1) {
        pos_anterior = pos_atual;
        //printf("pos anterior: %d pos_atual %d\n", pos_anterior, pos_atual);
        no* atual = le_no(arq, pos_atual);

        if (info.codigo < atual->livro.codigo) {
            pos_atual = atual->esq;
            direcao = -1;
        } else {
            pos_atual = atual->dir;
            direcao = 1;
        }
        free(atual);
    }

    if (cab->pos_livre == -1) {
        escreve_no(arq, novo_no, cab->pos_topo);
        if (pos_anterior == -1) {
            cab->pos_cabeca = cab->pos_topo;
        } else {
            no* pai = le_no(arq, pos_anterior);
            if (direcao == -1) pai->esq = cab->pos_topo;
            else pai->dir = cab->pos_topo;
            escreve_no(arq, pai, pos_anterior);
            free(pai);
        }
        cab->pos_topo++;
    } else {
        int pos_livre = cab->pos_livre;
        no* livre = le_no(arq, pos_livre);
        cab->pos_livre = livre->dir;
        escreve_no(arq, novo_no, pos_livre);
        if (pos_anterior == -1) {
            cab->pos_cabeca = pos_livre;
        } else {
            no* pai = le_no(arq, pos_anterior);
            if (direcao == -1) pai->esq = pos_livre;
            else pai->dir = pos_livre;
            escreve_no(arq, pai, pos_anterior);
            free(pai);
        }
        free(livre);
    }

    escreve_cabecalho(arq, cab);
    free(cab);
    free(novo_no);
}

// Função auxiliar para encontrar o maior nó na subárvore esquerda
//Pré-condição: arq deve estar aberto para leitura, e posicao é a posição do nó inicial para busca.
//Pós-condição: Retorna a posição do maior nó encontrado na subárvore; ajusta as ligações na árvore caso o maior nó tenha um filho esquerdo.
int busca_maior(FILE* arq, int posicao) {
    no* atual = le_no(arq, posicao);
    int pos_pai = posicao; // Armazena a posição do pai do maior nó

    // Encontra o maior elemento na subárvore (mais à direita)
    while (atual->dir != -1) {
        pos_pai = posicao;
        posicao = atual->dir;
        free(atual);
        atual = le_no(arq, posicao);
    }

    int codigo_maior = atual->livro.codigo;

    // Se o maior nó tiver um filho à esquerda, ele substitui o maior nó
    if(atual->esq == -1 && atual->dir == -1){
        no* pai_maior = le_no(arq, pos_pai);
        pai_maior->dir = -1;
        escreve_no(arq, pai_maior, pos_pai);
        free(pai_maior);
    }
    else if (atual->esq != -1) {
        no* pai_maior = le_no(arq, pos_pai);
            pai_maior->dir = atual->esq;
        escreve_no(arq, pai_maior, pos_pai);
        free(pai_maior);
    }
    free(atual);
    return posicao;
}

// Função principal de remoção
//Pré-condição: arq deve estar aberto para leitura e escrita.
//Pós-condição: Remove um nó com um código específico da árvore binária e atualiza o cabeçalho e as ligações na árvore para manter a estrutura.
void remove_arvore(FILE* arq) {
    int codigo;
    printf("\nDigite o código do livro a ser removido\n");
    scanf("%d", &codigo);
    cabecalho* cab = le_cabecalho(arq);
    if (cab->pos_cabeca == -1) {
        printf("Árvore vazia.\n");
        free(cab);
        return;
    }
    int pos_atual = cab->pos_cabeca, pos_pai = -1;
    int direcao = 0; // Direção: -1 para esquerda, 1 para direita

    while (pos_atual != -1) {
        no* atual = le_no(arq, pos_atual);
        if (codigo == atual->livro.codigo) {
            int pos_remocao = pos_atual;

            // Caso 1: Nó folha
            if (atual->esq == -1 && atual->dir == -1) {
                if (pos_pai == -1) {  // É a raiz
                    cab->pos_cabeca = -1;
                    //vazando memoria, se der algo errado talvez seja isso?
                } else {
                    no* pai = le_no(arq, pos_pai);
                    if (direcao == -1) pai->esq = -1;
                    else pai->dir = -1;
                    escreve_no(arq, pai, pos_pai);
                    free(pai);
                }
            }
            // Caso 2: Nó com um único filho
            else if (atual->esq == -1 || atual->dir == -1) {
                int filho = (atual->esq != -1) ? atual->esq : atual->dir;

                if (pos_pai == -1) {  // É a raiz
                    cab->pos_cabeca = filho;
                } else {
                    no* pai = le_no(arq, pos_pai);
                    if (direcao == -1) pai->esq = filho;
                    else pai->dir = filho;
                    escreve_no(arq, pai, pos_pai);
                    free(pai);
                }
            }
            // Caso 3: Nó com dois filhos
            else {
                // Substituir pelo maior elemento da subárvore esquerda
                int posicao = busca_maior(arq, atual->esq);
                no *novaraiz = le_no(arq, posicao);
                
                if(atual->esq != posicao) novaraiz->esq = atual->esq;
                if(atual->dir != posicao) novaraiz->dir = atual->dir;

                escreve_no(arq, novaraiz, posicao);
                //se for raiz, setar nova raiz
                if (pos_pai == -1) {
                    cab->pos_cabeca = posicao;
                }else{
                    no* pai = le_no(arq, pos_pai);
                    if (direcao == -1) pai->esq = posicao;
                    else pai->dir = posicao;
                    escreve_no(arq, pai, pos_pai);
                    free(pai);
                }
                //atual->livro.codigo = -1; 
                //printf("cod: %d esq: %d dir: %d", novaraiz)

                //reescrevendo o atual para setar ele como -1 
                //escreve_no(arq, atual, pos_atual);
                //printf("%d %d\n", pos_atual, pos_pai);
                // Agora, o maior nó precisa ser removido da subárvore esquerda
                // pos_pai = pos_atual;
                // pos_atual = atual->esq;
                // codigo = posicao;
            }


            // Atualiza a lista de posições livres
            atual->dir = cab->pos_livre;
            atual->esq = -1;
            cab->pos_livre = pos_remocao;
            //falando q atual se conecta com o primeiro da lista de removidos
            escreve_no(arq, atual, pos_remocao);
            escreve_cabecalho(arq, cab);
            free(atual);
            printf("Livro excluído com sucesso!\n");
            break;
        }

        // Atualiza para o próximo nó
        pos_pai = pos_atual;
        direcao = (codigo < atual->livro.codigo) ? -1 : 1;
        pos_atual = (codigo < atual->livro.codigo) ? atual->esq : atual->dir;
        free(atual);
    }

    if (pos_atual == -1) {
        printf("Livro não encontrado.\n");
    }

    free(cab);
}


//Função para remover os espaços para tornar a string válida.
//Pré-condição: str deve ser uma string válida.
//Pós-condição: Retorna str sem espaços no início e no final.
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

void replace_comma_with_dot(char *str) {
    while (*str) {
        if (*str == ',') {
            *str = '.';
        }
        str++;
    }
}


//Lê as informações na estrutura Livro.
//Pré-condição: l deve ser um ponteiro válido para uma estrutura de livro.
//Pós-condição: Os dados do livro são lidos do usuário e armazenados em l.
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
    replace_comma_with_dot(preco_str);    
    l->preco = atof(preco_str); 
    printf("%s\n", preco_str);
}



//Imprime as informações do livro selecionado. 
//Pré-condição: file deve estar aberto para leitura.
//Pós-condição: Exibe as informações de um livro com o código especificado pelo usuário, caso encontrado.
void imprimir_livro(FILE* file) {
    cabecalho* cab = le_cabecalho(file);
    int codigo;

    printf("\nDigite o código do livro a ser impresso\n");
    scanf("%d", &codigo);

    int pos_aux = cab->pos_cabeca; // Em uma árvore, começamos pela raiz
    no* aux = NULL;

    // Realiza a busca binária na árvore pelos nós da estrutura
    while (pos_aux != -1) {
        aux = le_no(file, pos_aux);

        if (aux->livro.codigo == codigo) {
            // Imprime os detalhes do livro se encontrado
            printf("\n Título: %s;", aux->livro.titulo);
            printf("\n Autor: %s", aux->livro.autor);
            printf("\n Editora: %s", aux->livro.editora);
            printf("\n Edição: %d", aux->livro.edicao);
            printf("\n Ano: %d", aux->livro.ano);
            printf("\n Preço: R$ %.2lf", aux->livro.preco);
            printf("\n Estoque: %d\n\n", aux->livro.estoque);
            break;
        } else if (codigo < aux->livro.codigo) {
            pos_aux = aux->esq;  // Vai para o filho à esquerda
        } else {
            pos_aux = aux->dir;  // Vai para o filho à direita
        }

        free(aux); // Libera o nó após leitura para evitar vazamento de memória
    }

    if (pos_aux == -1) {
        printf("\nLivro com código %d não encontrado.\n", codigo);
    }
    free(cab);  // Libera a memória alocada para o cabeçalho
}

//Percorre a lista em inorder.
//Pré-condição: file deve estar aberto para leitura.
//Pós-condição: Exibe os livros cadastrados na árvore, em ordem.
void listar_em_ordem(FILE* file, int pos_atual) {
    if (pos_atual == -1) {
        return;  // Base da recursão, retorna quando o nó é inválido
    }

    no* aux = le_no(file, pos_atual);

    // Percorre o filho esquerdo
    listar_em_ordem(file, aux->esq);

    // Imprime apenas o código e o título do livro no nó atual
    printf("Código: %d | Título: %s\n", aux->livro.codigo, aux->livro.titulo);

    // Percorre o filho direito
    listar_em_ordem(file, aux->dir);

    free(aux);  // Libera a memória do nó atual após o uso
}

//Chama a funçãu auxiliar para printar inorder.
//Pré-condição: file deve estar aberto para leitura.
//Pós-condição: Exibe os livros cadastrados na árvore, em ordem.
void listar(FILE* file) {
    cabecalho* cab = le_cabecalho(file);

    if (cab->pos_cabeca == -1) {
        printf("Ainda não há livros cadastrados!\n");
        free(cab);
        return;
    }

    printf("---------------LIVROS CADASTRADOS--------------\n");
    listar_em_ordem(file, cab->pos_cabeca);  // Chama a função auxiliar para percorrer a árvore

    free(cab);  // Libera a memória do cabeçalho após o uso
}

//Função recursiva para achar e printar o livro
//Pré-condição: file deve estar aberto para leitura, pos_atual é uma posição válida de um nó ou -1, e nome é uma string válida.
//Pós-condição: Exibe títulos dos livros do autor especificado por nome.
void busca_por_autor_aux(FILE* file, int pos_atual, const char* nome, int* encontrou) {
    if (pos_atual == -1) {
        return;  // Base da recursão: nó inválido
    }

    no* aux = le_no(file, pos_atual);

    // Percorre o filho esquerdo
    busca_por_autor_aux(file, aux->esq, nome, encontrou);

    // Verifica se o autor do livro no nó atual corresponde ao nome buscado
    if (strcmp(aux->livro.autor, nome) == 0) {
        printf("- %s\n", aux->livro.titulo);
        *encontrou = 1;
    }

    // Percorre o filho direito
    busca_por_autor_aux(file, aux->dir, nome, encontrou);

    free(aux);  // Libera a memória do nó após o uso
}

//Busca para printar os livros do autor.
//Pré-condição: file deve estar aberto para leitura.
//Pós-condição: Exibe todos os títulos dos livros de um autor especificado pelo usuário.
void busca_por_autor(FILE* file) {
    char nome[201];
    cabecalho* cab = le_cabecalho(file);
    int encontrou = 0;

    printf("Digite o nome do autor a ser buscado\n");
    scanf("%[^\n]%*c", nome);
    nome[strcspn(nome, "\n")] = '\0';
    printf("\nLivros do Autor: %s\n", nome);

    busca_por_autor_aux(file, cab->pos_cabeca, nome, &encontrou);

    if (!encontrou) {
        printf("Nenhum livro encontrado para o autor: %s\n", nome);
    }

    free(cab);  // Libera o cabeçalho após o uso
}
//Função auxiliar para buscar livro por título.
//Pré-condição: file deve estar aberto para leitura, pos_atual é uma posição válida de um nó ou -1, e titulo é uma string válida.
//Pós-condição: Exibe as informações do livro com o título especificado, caso encontrado.
void busca_por_titulo_aux(FILE* file, int pos_atual, const char* titulo, int* encontrado) {
    if (pos_atual == -1) {
        return;
    }

    no* aux = le_no(file, pos_atual);
    busca_por_titulo_aux(file, aux->esq, titulo, encontrado);
    if (strcmp(aux->livro.titulo, titulo) == 0) {
        printf("\nInformações do livro %s\n", titulo);
        printf("%s\n", aux->livro.titulo);
        printf("Código: %d\n", aux->livro.codigo);
        printf("Edicao: %d\n", aux->livro.edicao);
        printf("Autor: %s\n", aux->livro.autor);
        printf("Editora: %s\n", aux->livro.editora);
        printf("Ano: %d\n", aux->livro.ano);
        printf("Preço: R$ %.2lf\n", aux->livro.preco);
        printf("Estoque: %d\n", aux->livro.estoque);
        *encontrado = 1;
    }
    busca_por_titulo_aux(file, aux->dir, titulo, encontrado);

    free(aux);
}

//busca um livro por títutlo.
//Pré-condição: file deve estar aberto para leitura.
//Pós-condição: Exibe as informações do livro com o título especificado pelo usuário.
void busca_por_titulo(FILE* file) {
    char titulo[201];
    cabecalho* cab = le_cabecalho(file);
    int encontrado = 0;

    printf("Digite o título do livro a ser buscado\n");
    scanf("%[^\n]%*c", titulo);
    titulo[strcspn(titulo, "\n")] = '\0';

    busca_por_titulo_aux(file, cab->pos_cabeca, titulo, &encontrado);

    if (!encontrado) {
        printf("Nenhum livro com esse título encontrado\n");
    }

    free(cab);  // Libera o cabeçalho após o uso
}

//Função auxiliar para calcular o total de livros cadastrados.
//Pré-condição: file deve estar aberto para leitura; pos_atual é uma posição válida de um nó ou -1.
//Pós-condição: Retorna o total de nós a partir de pos_atual.
int calcular_total_aux(FILE* file, int pos_atual) {
    if (pos_atual == -1) {
        return 0;  // Base da recursão
    }

    no* aux = le_no(file, pos_atual);

    // Conta o nó atual e soma o total dos filhos esquerdo e direito
    int total = 1 + calcular_total_aux(file, aux->esq) + calcular_total_aux(file, aux->dir);

    free(aux);  // Libera a memória do nó após o uso
    return total;
}

//Calcula o total de livros cadastrados.
//Pré-condição: file deve estar aberto para leitura.
//Pós-condição: Exibe o total de livros cadastrados na árvore.
void calcular_total(FILE* file) {
    cabecalho* cab = le_cabecalho(file);

    int total = calcular_total_aux(file, cab->pos_cabeca);

    printf("\n O número total de livros cadastrados é: %d\n", total);

    free(cab);  // Libera o cabeçalho após o uso
}

//Carrega os arquivos do lote.
//Pré-condição: file_write deve estar aberto para escrita.
//Pós-condição: Lê um arquivo de texto e insere cada livro lido na árvore binária no arquivo file_write.
void carregar_arquivo(FILE* file_write) {
    FILE *file_read = fopen("livros.txt", "r");
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
        replace_comma_with_dot(field);
        livro.preco = (field ? atof(trim(field)) : 0.0);

        field = strtok(NULL, ";");
        livro.estoque = (field ? atoi(trim(field)) : 0);

        insere_arvore(file_write, livro); // Adiciona o livro na árvore binária
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

    printf("Posições de registros livres para reúso:\n");
    while (pos_aux != -1) {
        no *livre = le_no(file, pos_aux);

        printf("Posição livre: %d\n", pos_aux);
        pos_aux = (livre->esq != -1) ? livre->esq : livre->dir;

        free(livre);
    }

    free(cab);
}

//Pré-condição: q deve ser um ponteiro válido para uma estrutura de fila.
//Pós-condição: Inicializa a fila vazia.
void initQueue(Fila* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Função para verificar se a fila está vazia
//Pré-condição: q deve ser um ponteiro válido para uma estrutura de fila inicializada.
//Pós-condição: Retorna 1 se a fila estiver vazia, 0 caso contrário.
int isEmpty(Fila* q) {
    return (q->front == NULL);
}

// Função para adicionar um elemento à fila
//Pré-condição: q deve ser um ponteiro válido para uma estrutura de fila inicializada.
//Pós-condição: Insere um novo elemento com pos na fila q.
void enqueue(Fila* q, int pos) {
    noFila* temp = (noFila*)malloc(sizeof(noFila));
    temp->pos = pos;
    temp->next = NULL;
    if (isEmpty(q)) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Função para remover um elemento da fila
//Pré-condição: q deve ser um ponteiro válido para uma estrutura de fila inicializada e não vazia.
//Pós-condição: Remove e retorna o primeiro elemento da fila q.
int dequeue(Fila* q) {
    if (isEmpty(q)) {
        return -1;
    }
    int pos = q->front->pos;
    noFila* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return pos;
}

// Função para imprimir a árvore binária por níveis
void imprimir_arvore_por_niveis(FILE* arq) {
    cabecalho* cab = le_cabecalho(arq);
    if (cab->pos_cabeca == -1) {
        printf("Árvore vazia.\n");
        free(cab);
        return;
    }

    Fila q;
    initQueue(&q);
    enqueue(&q, cab->pos_cabeca);

    while (!isEmpty(&q)) {
        int nivelCount = 0;
        int queueSize = 0;

        noFila* temp = q.front;
        while (temp != NULL) {
            queueSize++;
            temp = temp->next;
        }

        for (int i = 0; i < queueSize; i++) {
            int pos = dequeue(&q);
            no* atual = le_no(arq, pos);

            printf("%d ", atual->livro.codigo);
            if (atual->esq != -1) enqueue(&q, atual->esq);
            if (atual->dir != -1) enqueue(&q, atual->dir);

            free(atual);
            nivelCount++;
        }
        printf("\n");
    }

    free(cab);
}

// Função auxiliar para imprimir a árvore formatada como lista
//Pré-condição: arq deve estar aberto e ser um arquivo binário contendo a estrutura de uma árvore binária.
//Pós-condição: A árvore é exibida em formato de lista no console, onde cada nó é representado com seu código.
void imprimir_arvore_como_lista(FILE* arq, int pos) {
    if (pos == -1) {
        printf("[ ]");
        return;
    }

    no* atual = le_no(arq, pos);
    printf("[%d, ", atual->livro.codigo);

    // Imprime a subárvore esquerda
    imprimir_arvore_como_lista(arq, atual->esq);
    printf(", ");

    // Imprime a subárvore direita
    imprimir_arvore_como_lista(arq, atual->dir);
    printf("]");

    free(atual);
}

// Função principal para imprimir a árvore
//Pré-condição: arq deve estar aberto e ser um arquivo binário contendo a estrutura de uma árvore binária.
//Pós-condição: A árvore é impressa no console no formato de lista. Se a árvore estiver vazia, exibe uma mensagem indicando isso.
void imprimir_arvore_formatada(FILE* arq) {
    cabecalho* cab = le_cabecalho(arq);
    if (cab->pos_cabeca == -1) {
        printf("Árvore vazia.\n");
    } else {
        imprimir_arvore_como_lista(arq, cab->pos_cabeca);
    }
    free(cab);
    printf("\n");
}
//Pré-condição: Nenhuma pré-condição, pois a função apenas imprime um texto de menu no console.
//Pós-condição: O menu de opções é exibido no console, permitindo ao usuário escolher entre diversas funcionalidades da árvore.
void menu(){
    printf("\n-----------MENU--------------\n");
    printf("Digite 1 para cadastrar um livro.\n");
    printf("Digite 2 para remover as informações de um livro.\n");
    printf("Digite 3 para imprimir dados de um livro.\n");
    printf("Digite 4 para listar todos os livros.\n");
    printf("Digite 5 para buscar livros de algum autor.\n");
    printf("Digite 6 para buscar por algum livro.\n");
    printf("Digite 7 para calcular o total de livros cadastrados.\n");
    printf("Digite 8 para carregar livros.\n");
    printf("Digite 9 para imprimir lista de registros livres.\n");
    printf("Digite 10 para listar por niveis.\n");
    printf("Digite 11 para imprimir arvore formatada como lista.\n");
    printf("Digite 0 para sair do menu.\n");
    printf("----------------------------\n");
}


