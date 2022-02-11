#ifndef ALGORITMO_H_
#define ALGORITMO_H_


typedef struct ordenacao ordenacao;

ordenacao* cria(char *nome);

ordenacao* selectionSort(int qtd, int *dados);

ordenacao* insertionSort(int qtd, int *dados);

ordenacao* shellSort(int qtd, int *dados);

ordenacao* quickSort(int *dados, int esq, int dir, ordenacao *quick);

ordenacao* heapSort(int qtd, int *dados);

void insereProx(ordenacao *x, ordenacao *novo);     //INSERE NO FINAL

void excluiOrdenacao(ordenacao *inicio);

void insereTempo(ordenacao *x, double tempo);

double retornaTempo(ordenacao *x);

void insereTroca(ordenacao *x, unsigned long int trocas);

unsigned long int retornaTroca(ordenacao *x);

void insereComp(ordenacao *x, unsigned long int comparacao);

unsigned long int retornaComp(ordenacao *x);

char* retornaNome(ordenacao *x);

ordenacao* retornaProx(ordenacao *x);

#endif