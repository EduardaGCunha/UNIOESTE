# Sistema de Cadastro de Livros - Trabalho de Algoritmos e Estrutura de Dados

## Informações do Grupo
- Nome dos componentes do grupo: Eduarda Cunha, Carlos Penteado
- Curso: Ciência da Computação
- Campus: Foz do Iguaçu
- Data: Setembro de 2024
- Professor: Rômulo Silva

## Descrição do Projeto
Este projeto consiste na implementação de um sistema de cadastro de livros para uma livraria, utilizando uma lista encadeada armazenada em um arquivo binário. O programa foi desenvolvido na linguagem C e opera totalmente em modo texto, sendo executado no prompt do shell do sistema operacional.

O objetivo do sistema é permitir o gerenciamento eficiente de um acervo de livros, oferecendo funcionalidades para cadastrar, remover, buscar e listar livros, além de outras operações associadas à gestão de registros livres e carregamento de dados em lote.

## Funcionalidades Implementadas

### 1. **Cadastrar Livro**
   - Permite inserir um novo livro no sistema. O usuário deve fornecer o código, título, autor, editora, número da edição, ano de publicação, preço e quantidade em estoque do livro. O sistema adiciona o livro na lista encadeada armazenada no arquivo binário.

### 2. **Remover Livro**
   - Remove um livro do cadastro com base no código fornecido pelo usuário. O registro correspondente é encadeado à lista de registros livres, possibilitando o reaproveitamento em futuras inserções.

### 3. **Imprimir Dados de um Livro**
   - Exibe todas as informações de um livro específico, dado o seu código.

### 4. **Listar Todos os Livros**
   - Lista todos os livros cadastrados no sistema, exibindo apenas o código, título, autor, e a quantidade em estoque de cada livro.

### 5. **Busca por Autor**
   - Realiza uma busca por todos os livros de um autor específico e imprime os títulos dos livros encontrados.

### 6. **Busca por Título**
   - Busca e exibe todas as informações de um livro específico com base em seu título.

### 7. **Calcular Total de Livros**
   - Calcula e imprime o número total de livros cadastrados no sistema.

### 8. **Carregar Arquivo**
   - Realiza inclusões em lote, carregando informações de livros a partir de um arquivo texto. Os livros lidos são inseridos no arquivo binário do cadastro.

### 9. **Imprimir Lista de Registros Livres**
   - Imprime as posições de registros livres no arquivo binário, correspondentes aos livros removidos do cadastro, possibilitando o reaproveitamento de espaço.

## Como Executar o Programa

1. Compile o programa digitando "gcc main.c funcoes.c" no terminal.
2. Siga as instruções do menu exibido para utilizar as funcionalidades disponíveis.

## Estrutura do Código
O programa é dividido em múltiplas funções, cada uma responsável por uma funcionalidade específica do sistema. A documentação detalhada das funções está presente nos arquivos fonte (`.c` e `.h`), explicando o propósito de cada função, suas pré-condições e pós-condições.

## Considerações Finais
Este trabalho foi desenvolvido como parte da disciplina de Algoritmos e Estrutura de Dados e tem como objetivo demonstrar o uso de estruturas de dados, como listas encadeadas, em um contexto prático de gerenciamento de informações utilizando arquivos binários. A avaliação do trabalho inclui tanto a implementação correta das funcionalidades quanto a apresentação oral do projeto.