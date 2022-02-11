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

ordenacao* cria(char *nome);

ordenacao* selectionSort(int qtd, int *dados);
ordenacao* insertionSort(int qtd, int *dados);
ordenacao*     shellSort(int qtd, int *dados);
ordenacao*     quickSort(int *dados, int esq, int dir, ordenacao* quick);
ordenacao*      heapSort(int qtd, int *dados);

void            criaHeap(int *dados, int inicio, int fim, ordenacao *heap);
void       libera(ordenacao* x);

#endif /* ALGORITMO_H */