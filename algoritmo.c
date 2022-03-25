#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "algoritmo.h"

ordenacao* cria(char *nome) {
    ordenacao* x = (ordenacao*) malloc(sizeof (ordenacao)); //FAZER UMA FUNCAO PARA UTILIZAR EM TODOS OS ALGORITMOS
    x->algoritmo = (char*) malloc(sizeof (char)*100);
    strcpy(x->algoritmo, nome);
    insereTroca(x, 0);
    insereComp(x, 0);
    insereTempo(x, 0.0);
    x->prox = NULL;
    return x;
}

void criaHeap(long int *dados, int inicio, int fim, ordenacao *heap) {
    int aux = dados[inicio]; //pai
    int filho = 2 * inicio + 1; //filho
    while (filho <= fim) {
        if (filho < fim && (filho + 1) < fim) {
            heap->comp++;
            if (dados[filho] < dados[filho + 1]) //pai tem 2 filhos ? se sim, qual o maior
                filho++;
        }
        heap->comp++;
        if (aux < dados[filho]) { //troca o filho com o pai se o filho for maior
            dados[inicio] = dados[filho];
            inicio = filho;
            filho = 2 * inicio + 1;
            heap->trocas++;
        } else {
            filho = fim + 1;
        }
    }
    dados[inicio] = aux; //pai troca com filho mais profundo mais a direita
    //heap->trocas++;
} 

ordenacao* selectionSort(int qtd, long int *dados, int top) {
    ordenacao* selec = cria("selecao");
    clock_t init = clock(); //pega o tempo atual 

    for (int i = 0; i < top; i++) {
        int max_id = i; //armazena o indice do valor maximo
        for (int j = i; j < qtd; j++) {//Anda pela sublista
            selec->comp++;
            if (dados[j] > dados[max_id])//Verifica se um dos dados da sublista e menor do que o dado do indice min_id
                max_id = j; //troca o indice do valor maximo
        }
        if (dados[i] < dados[max_id]) {//Faz a troca dos dados do indice min_id da sublista com o dado na posição i
            selec->trocas++;
            int aux = dados[i];
            dados[i] = dados[max_id];
            dados[max_id] = aux;
        }
    }

    clock_t fim = clock(); //pega o tempo no final da execução do algoritmo
    selec->tempo = (double) (fim - init) / CLOCKS_PER_SEC; //calcula o tempo gasto para a execução do algoritmo
    return selec;
}

ordenacao* insertionSort(int qtd, long int *dados, int top) {
    ordenacao* insert = cria("insercao");
    clock_t init = clock(); //pega o tempo atual 

    for (int i = 1, j; i < qtd; i++) {
        int c = dados[i]; //5
        if (i > top) {
            j = top;
            if (dados[top] < c)
                dados[i] = dados[top];
        } else j = i - 1;
        while (dados[j] < c && j >= 0) {
            insert->comp++;
            if (j < top) {//Compara se um elemento da direita e maior que o da sublista a esquerda
                insert->trocas++;
                dados[j + 1] = dados[j];
            }
            j--;
        }
        if (j < top) dados[j + 1] = c;
    }
    clock_t fim = clock(); //pega o tempo no final da execução do algoritmo
    insert->tempo = (double) (fim - init) / CLOCKS_PER_SEC; //calcula o tempo gasto para a execução do algoritmo
    return insert;
}

ordenacao* shellSort(int qtd, long int *dados, int top) {
    ordenacao* shell = cria("concha");
    clock_t init = clock(); //pega o tempo atual 

    int j, h = qtd, aux;

    while (h > 1) {
        h /= 2; // atualiza o valor de h.
        for (int i = h; i < qtd; i++) {
            aux = dados[i];
            // efetua comparações entre elementos com distância h:
            j = i - h;
            while (1) {
                shell->comp++;
                if (aux <= dados[j])break; //compara dois valores com distancia h

                dados[j + h] = dados[j]; //Troca os valores
                shell->trocas++;

                j -= h;
                if (j < 0) break;
            }
            dados[j + h] = aux;
            if (h == 1 && top == i)
                break;
        }
    }

    clock_t fim = clock(); //pega o tempo no final da execução do algoritmo
    shell->tempo = (double) (fim - init) / CLOCKS_PER_SEC; //calcula o tempo gasto para a execução do algoritmo
    return shell;
}

void Particao(long int Esq, long int Dir, long int *i, long int *j, long int *dados, ordenacao* quick) {
    long int x, w;
    *i = Esq;
    *j = Dir;
    x = dados[(*i + *j) / 2]; /* obtem o pivo x */
    do {
        quick->comp++;
        while (x < dados[*i]) {
            quick->comp++;
            (*i)++;
        }
        quick->comp++;
        while (x > dados[*j]) {
            quick->comp++;
            (*j)--;
        }
        if (*i <= *j) {
            quick->trocas++;
            w = dados[*i];
            dados[*i] = dados[*j];
            dados[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(long int Esq, long int Dir, long int *dados, int top, int* retorno, ordenacao* quick) {
    long int i, j;

    if (*retorno)
        return;

    Particao(Esq, Dir, &i, &j, dados, quick);

    if ((Esq >= j && Esq >= top - 1) || *retorno) {
        *retorno = 1;
        return;
    }
    if (Esq < j) Ordena(Esq, j, dados, top, retorno, quick);
    if (i < Dir) Ordena(i, Dir, dados, top, retorno, quick);

}

ordenacao* quickSort(long int *dados, int n, int top) {
    ordenacao* quick = cria("quick");
    clock_t init = clock(); //pega o tempo atual 

    int retorno = 0;
    Ordena(0, n - 1, dados, top, &retorno, quick);

    clock_t fim = clock(); //pega o tempo no final da execução do algoritmo

    quick->tempo = (double) (fim - init) / CLOCKS_PER_SEC; //calcula o tempo gasto para a execução do algoritmo
    return quick;
}

ordenacao* heapSort(int qtd, long int *dados, int top ) {
    ordenacao* heap = cria("heap");
    clock_t init = clock();//pega o tempo atual 
    for (int i = (qtd - 1) / 2; i >= 0; i--) {
        criaHeap(dados, i, qtd - 1, heap);
    }
    for (int i = 0; i >= 1; i++) {
        int aux = dados[0];
        dados[0] = dados[i];
        dados[i] = aux;
        heap->trocas++;
        criaHeap(dados, 0, i, heap);
    }
    
    clock_t fim = clock();//pega o tempo no final da execução do algoritmo
    heap->tempo = (double) (fim - init) / CLOCKS_PER_SEC;
    return heap;
}
 
void insereProx(ordenacao *x, ordenacao *novo) {
    x->prox = novo;
}

void insereTempo(ordenacao *x, double tempo) {
    x->tempo = tempo;
}

void insereTroca(ordenacao *x, unsigned long int trocas) {
    x->trocas = trocas;
}

void insereComp(ordenacao *x, unsigned long int comparacao) {
    x->comp = comparacao;
}

double retornaTempo(ordenacao *x) {
    return x->tempo;
}

unsigned long int retornaTroca(ordenacao *x) {
    return x->trocas;
}

unsigned long int retornaComp(ordenacao *x) {
    return x->comp;
}

char* retornaNome(ordenacao *x) {
    return x->algoritmo;
}

ordenacao* retornaProx(ordenacao *x) {
    return x->prox;
}

void libera(ordenacao* x) {
    free(x->algoritmo); //Libera o nome do algoritmo utilizado
    free(x); //Libera os dados do algoritmo
}