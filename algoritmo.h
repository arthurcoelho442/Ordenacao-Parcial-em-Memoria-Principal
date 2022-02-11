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

ordenacao*          cria(char *nome);

ordenacao*          selectionSort(int qtd, int *dados);
ordenacao*          insertionSort(int qtd, int *dados);
ordenacao*          shellSort(int qtd, int *dados);
ordenacao*          quickSort(int *dados, int esq, int dir, ordenacao* quick);
ordenacao*          heapSort(int qtd, int *dados);

void                insereProx(ordenacao *x, ordenacao *novo);     //INSERE NO FINAL
void                insereTempo(ordenacao *x, double tempo);
void                insereTroca(ordenacao *x, unsigned long int trocas);
void                insereComp(ordenacao *x, unsigned long int comparacao);

double              retornaTempo(ordenacao *x);
unsigned long int   retornaTroca(ordenacao *x);
unsigned long int   retornaComp(ordenacao *x);
char*               retornaNome(ordenacao *x);
ordenacao*          retornaProx(ordenacao *x);

void                libera(ordenacao* x);

#endif /* ALGORITMO_H */
