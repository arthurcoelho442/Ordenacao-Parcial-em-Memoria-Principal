#include "algoritmo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

ordenacao* cria(char *nome){
    ordenacao* x = (ordenacao*) malloc(sizeof (ordenacao)); //FAZER UMA FUNCAO PARA UTILIZAR EM TODOS OS ALGORITMOS
    x->algoritmo = (char*) malloc(sizeof (char)*100); //mudar
    strcpy(x->algoritmo, nome);
    x->comp = 0;
    x->trocas = 0;
    x->tempo = 0;
    x->prox = NULL;
    return x;
}

ordenacao* selectionSort(int qtd, int *dados) {
    ordenacao* selec = cria("selecao");
    clock_t init = clock(); //pega o tempo atual 

    for (int i = 0; i < qtd; i++) {
        int max_id = i; //armazena o indice do valor minimo
        for (int j = i; j < qtd; j++) {//Anda pela sublista
            selec->comp++;
            if (dados[j] > dados[max_id])//Verifica se um dos dados da sublista e menor do que o dado do indice min_id
                max_id = j; //troca o indice do valor minimo
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

ordenacao* insertionSort(int qtd, int *dados) {
    ordenacao* insert = cria("insercao");
    clock_t init = clock(); //pega o tempo atual 

    for (int i = 1, j; i < qtd; i++) {
        int c = dados[i]; //5
        for (j = i - 1; j >= 0; j--) {
            insert->comp++;
            if (dados[j] < c) {//Compara se um elemento da direita e maior que o da sublista a esquerda
                insert->trocas++;
                dados[j + 1] = dados[j];
            } else
                break;
        }
        dados[j + 1] = c;
    }
    
    clock_t fim = clock(); //pega o tempo no final da execução do algoritmo
    insert->tempo = (double) (fim - init) / CLOCKS_PER_SEC; //calcula o tempo gasto para a execução do algoritmo
    return insert;
}
ordenacao* shellSort(int qtd, int *dados) {
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
                if (aux < dados[j])break; //compara dois valores com distancia h

                dados[j + h] = dados[j]; //Troca os valores
                shell->trocas++;

                j -= h;
                if (j < 0) break;
            }
            dados[j + h] = aux;
        }
    }

    clock_t fim = clock(); //pega o tempo no final da execução do algoritmo
    shell->tempo = (double) (fim - init) / CLOCKS_PER_SEC; //calcula o tempo gasto para a execução do algoritmo
    return shell;
}

ordenacao* quickSort(int *dados, int esq, int dir, ordenacao* quick) {
    int aux_esq = esq;
    int aux_dir = dir;
    int central = dados[(esq + dir) / 2];
    
    while (aux_esq <= aux_dir) {
        while (dados[aux_esq] < central && aux_esq < dir) {
            aux_esq++;
            quick->comp++;
        }
        while (dados[aux_dir] > central && aux_dir > esq) {
            aux_dir--;
            quick->comp++;
        }
        if (aux_esq <= aux_dir) {
            //TROCA DE POSIÇÃO
            int aux_troca = dados[aux_esq];
            dados[aux_esq] = dados[aux_dir];
            dados[aux_dir] = aux_troca;
            aux_esq++;
            aux_dir--;
            quick->trocas++;
        }
        quick->comp++;
    }
    if (aux_dir > esq)
        quickSort(dados, esq, aux_dir, quick);
    if (aux_esq < dir)
        quickSort(dados, aux_esq, dir, quick);
    return quick;
}

void criaHeap(int *dados, int inicio, int fim, ordenacao *heap) {
    int aux = dados[inicio]; //pai
    int filho = 2 * inicio + 1; //filho

    while (filho <= fim) {
        if (filho < fim && (filho + 1) < fim) {
            if (dados[filho] < dados[filho + 1]) { //pai tem 2 filhos ? se sim, qual o maior
                filho++;
                heap->comp++;
            }
        }
        if (aux < dados[filho]) { //troca o filho com o pai se o filho for maior
            dados[inicio] = dados[filho];
            inicio = filho;
            filho = 2 * inicio + 1;
            heap->trocas++;
            heap->comp++;
        } else {
            filho = fim + 1;
        }
    }
    dados[inicio] = aux; //pai troca com filho mais profundo mais a direita
    heap->trocas++;
}

ordenacao* heapSort(int qtd, int *dados) {
    ordenacao* heap = cria("heap");
    clock_t init = clock();//pega o tempo atual 

    for (int i = (qtd - 1) / 2; i >= 0; i--) {
        criaHeap(dados, i, qtd - 1, heap);
    }
    for (int i = qtd - 1; i >= 1; i--) {
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

void libera(ordenacao* x){
    free(x->algoritmo); //Libera o nome do algoritmo utilizado
    free(x); //Libera os dados do algoritmo
}