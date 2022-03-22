#ifndef ALGORITMO_H
#define ALGORITMO_H

//struct com os dados da ordenação utilizada
struct ordenacao {
    char *algoritmo;
    unsigned long int comp;
    unsigned long int trocas;
    double tempo;
    struct ordenacao *prox;
} ;

typedef struct ordenacao ordenacao;

/*
* Função cria:
* Inputs: Nome do algoritmo.
* Outputs: Ponteiro para um algoritmo de ordenação.
* Pre-Condicao: Nome diferente de null.
* Pos-Condicao: Nenhum.
*/
ordenacao* cria(char *nome);

/*
* Função selectionSort:
* Inputs: Quantidade de dados e base de dados.
* Outputs: Ponteiro para um algoritmo de ordenação.
* Pre-Condicao: Nenhuma.
* Pos-Condicao: Retornar um ponteiro de ordenação alocado dinamicamente.
*/
ordenacao* selectionSort(int qtd, long int *dados, int top);
/*
* Função insertionSort:
* Inputs: Quantidade de dados e base de dados.
* Outputs: Ponteiro para um algoritmo de ordenação.
* Pre-Condicao: Nenhuma.
* Pos-Condicao: Retornar um ponteiro de ordenação alocado dinamicamente.
*/
ordenacao* insertionSort(int qtd, long int *dados, int top);
/*
* Função shellSort:
* Inputs: Quantidade de dados e base de dados.
* Outputs: Ponteiro para um algoritmo de ordenação.
* Pre-Condicao: Nenhuma.
* Pos-Condicao: Retornar um ponteiro de ordenação alocado dinamicamente.
*/
ordenacao* shellSort(int qtd, long int *dados, int top);
/*
* Função quickSort:
* Inputs: /------/.
* Outputs: Ponteiro para um algoritmo de ordenação.
* Pre-Condicao: Nenhuma.
* Pos-Condicao: Retornar um ponteiro de ordenação alocado dinamicamente.
*/
ordenacao* quickSort(long int *dados, long int esq, long int dir, ordenacao* quick, int top);
/*
* Função heapSort:
* Inputs: Quantidade de dados e base de dados.
* Outputs: Ponteiro para um algoritmo de ordenação.
* Pre-Condicao: Nenhuma.
* Pos-Condicao: Retornar um ponteiro de ordenação alocado dinamicamente.
*/
ordenacao* heapSort(int qtd, long int *dados, int top);

/*
* Função insereProx:
* Inputs: Algoritmo de ordenação principal, algoritmo de ordenação para proximo da lista.
* Outputs: Nenhum.
* Pre-Condicao: Algoritmo principal e próximo existentes e já alocados.
* Pos-Condicao: Nenhum
*/
void insereProx(ordenacao *x, ordenacao *novo);
/*
* Função insereTempo:
* Inputs: Algoritmo de ordenação principal, tempo gasto no algoritmo.
* Outputs: Nenhum.
* Pre-Condicao: Algoritmo principal existente e já alocado.
* Pos-Condicao: Nenhum
*/
void insereTempo(ordenacao *x, double tempo);
/*
* Função insereTroca:
* Inputs: Algoritmo de ordenação principal, numero de trocas feitas no algoritmo.
* Outputs: Nenhum.
* Pre-Condicao: Algoritmo principal existente e já alocado.
* Pos-Condicao: Nenhum
*/
void insereTroca(ordenacao *x, unsigned long int trocas);
/*
* Função insereComp:
* Inputs: Algoritmo de ordenação principal, numero de comparações feitas no algoritmo.
* Outputs: Nenhum.
* Pre-Condicao: Algoritmo principal existente e já alocado.
* Pos-Condicao: Nenhum
*/
void insereComp(ordenacao *x, unsigned long int comparacao);

/*
* Função retornaTempo:
* Inputs: Algoritmo de ordenação principal.
* Outputs: tempo utilizado no algoritimo.
* Pre-Condicao: Algoritmo principal existente e já alocado.
* Pos-Condicao: Nenhum
*/
double retornaTempo(ordenacao *x);
/*
* Função retornaTroca:
* Inputs: Algoritmo de ordenação principal.
* Outputs: numero de trocas feitos no algoritimo.
* Pre-Condicao: Algoritmo principal existente e já alocado.
* Pos-Condicao: Nenhum
*/
unsigned long int retornaTroca(ordenacao *x);
/*
* Função retornaComp:
* Inputs: Algoritmo de ordenação principal.
* Outputs: numero de comparaçoes feitas no algoritimo.
* Pre-Condicao: Algoritmo principal existente e já alocado.
* Pos-Condicao: Nenhum
*/
unsigned long int retornaComp(ordenacao *x);
/*
* Função retornaNome:
* Inputs: Algoritmo de ordenação principal.
* Outputs: Nome do algoritimo.
* Pre-Condicao: Algoritmo principal existente e já alocado.
* Pos-Condicao: Nenhum
*/
char* retornaNome(ordenacao *x);
/*
* Função retornaProx:
* Inputs: Algoritmo de ordenação principal.
* Outputs: Proximo algoritmo de ordenação.
* Pre-Condicao: Algoritmo principal existente e já alocado.
* Pos-Condicao: Nenhum
*/
ordenacao* retornaProx(ordenacao *x);

/*
* Função libera:
* Inputs: Algoritmo de ordenação principal.
* Outputs: Nenhum.
* Pre-Condicao: Algoritmo principal existente e já alocado.
* Pos-Condicao: Algoritmo é liberado
*/
void libera(ordenacao* x);

#endif /* ALGORITMO_H */
