#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "algoritmo.h"
#include <time.h>

#include "algoritmo.h"

#define Maiores 1
#define Estatisticas 2
#define Dados 3

typedef struct lista {
    ordenacao *ini, *fim;
} Lista;

void insereNaLista(Lista *l, ordenacao *e);
void excluiLista(Lista *l);

int main(int argc, char** argv) {
    Lista *lista = (Lista*) malloc(sizeof (lista));         //Lista com todas as ordenações executadas
    FILE* entrada;                                          //Arquivo de entrada para o sistema
    FILE* saida;                                            //Arquivo de saida
    int opt;
    int impressao[3] = {0, 0, 0};
    ordenacao *alg;                                         //algoritimo de ordenação
    
    //Abre o arquivo de Entrada e o de Saida
    entrada = fopen(argv[3], "r+");
    saida = fopen("saida.txt", "a+");

    //Verifica se o arquivo de Entrada é existente
    if (entrada == NULL) {
        printf("\n\tErro Arquivo de entrada não encontrado\n\n");
        return 0;
    }
    ///////////////////////////////////////

    //Tratamento do dados do arquivo //////////
    int qtd;                                                //quantidade de itens
    fscanf(entrada, "%d", &qtd);
    long int *dados = (long int*)malloc(sizeof(long int)*qtd);
    long int *dadosAux = (long int*)malloc(sizeof(long int)*qtd);
    //todos os dados do arquivo
    for(int i = 0; i < qtd; i++)
        fscanf(entrada, "%ld", &dados[i]);
    ///////////////////////////////////////////

    //Analise do [-123iseqha] para definir a execução do programa
    while ((opt = getopt(argc, argv, "asieqh123")) != -1)
        switch (opt) {
            case '1':                                       //Adiciona a lista para imprimir em tela os T maiores elementos
                for(int i = 0; i < 3; i++)
                    if(impressao[i] == 0){
                        impressao[i] = Maiores;
                        break;
                    }
                break;
            case '2':                                       //Adiciona a lista para imprimir as estatísticas
                for(int i = 0; i < 3; i++)
                    if(impressao[i] == 0){
                        impressao[i] = Estatisticas;
                        break;
                    }
                break;
            case '3':                                       //Adiciona em lista para imprimir os dados/estatísticas separados por tab
                for(int i = 0; i < 3; i++)
                    if(impressao[i] == 0){
                        impressao[i] = Dados;
                        break;
                    }
                break;
            case 'a':                                       //Executa todos os métodos de ordenação
                for(int i = 0; i < 5; i++){
                    for(int i = 0; i < qtd; i++)
                        dadosAux[i] = dados[i];
                    switch(i){
                        case 0:
                            alg = selectionSort(qtd, dadosAux);
                            break;
                        case 1:
                            alg = insertionSort(qtd, dadosAux);
                            break;
                        case 2:
                            alg = shellSort(qtd, dadosAux);
                            break;
                        case 3:
                            alg = cria("quick");
                            clock_t init = clock();                             //pega o tempo atual                                        
                            alg = quickSort(dadosAux, 0, qtd-1, alg);
                            clock_t fim = clock();                              //pega tempo final da eecução do algoritmo
                            double tempo = (double)(fim - init)/CLOCKS_PER_SEC; //calcula o tempo gasto para a execução do algoritmo
                            insereTempo(alg, tempo);
                            break;
                        case 4:
                            alg = heapSort(qtd, dadosAux);
                            break;
                    }
                    insereNaLista(lista, alg);
                }
                break;
            case 's':                                       //Executa método de ordenação por seleção
                for(int i = 0; i < qtd; i++)
                    dadosAux[i] = dados[i];
                alg = selectionSort(qtd, dadosAux);
                insereNaLista(lista, alg);                  //insere na lista
                break;
            case 'i':                                       //Executa método de ordenação por inserção
                for(int i=0; i<qtd; i++)
                    dadosAux[i] = dados[i];
                alg = insertionSort(qtd, dadosAux);
                insereNaLista(lista, alg);                  //insere na lista
                break;
            case 'e':                                       //Executa método de ordenação por shellsort
                for(int i=0; i<qtd; i++)
                    dadosAux[i] = dados[i];
                alg = shellSort(qtd, dadosAux);
                insereNaLista(lista, alg);                  //insere na lista
                break;
            case 'q':                                       //Executa método de ordenação por quicksort
                for(int i=0; i<qtd; i++)
                    dadosAux[i] = dados[i];
                alg = cria("quick");
                clock_t init = clock();                     //pega o tempo atual 
                alg = quickSort(dadosAux, 0, qtd - 1, alg);
                clock_t fim = clock();                      //pega o tempo no final da execução do algoritmo
                insereTempo(alg, (double) (fim - init) / CLOCKS_PER_SEC);
                insereNaLista(lista, alg);                  //insere na lista
                break;
            case 'h':                                       //Executa método de ordenação por heapsort
                for(int i=0; i<qtd; i++)
                    dadosAux[i] = dados[i];
                alg = heapSort(qtd, dadosAux);
                insereNaLista(lista, alg);                  //insere na lista
                break;
            default:                                        //Imprime o codigo de erro do opt
                printf("getopt retornou com character de codigo 0%o\n", opt);
        }
    //////////////////////////////////////////////////////////
    //Impressão////////////
    for(int i = 0; i < 3; i++){
        if(impressao[i] == Maiores){//Imprime em tela os T maiores elementos
            for(int j = 0; j < atoi(argv[2]); j++)
                printf("%ld\n", dadosAux[j]);
        }else if(impressao[i] == Estatisticas){//Imprime as estatísticas
            for(ordenacao *p = lista->ini; p!=NULL; p = retornaProx(p)){
                printf("\nTempo de CPU:\t%lf", retornaTempo(p));
                printf("\nComparações:\t%ld", retornaComp(p));
                printf("\nTrocas:\t%ld\n", retornaTroca(p));
            }
        }else if(impressao[i] == Dados){//Imprime dados/estatísticas po tab
            for(ordenacao *p = lista->ini; p!=NULL; p = retornaProx(p))
                fprintf(saida, "%s\t%s\t%d\t%s\t%ld\t%ld\t%lf\n", retornaNome(p), argv[3], qtd, argv[2],  retornaComp(p),
                                                                 retornaTroca(p), retornaTempo(p));
        }
    }
    //////////////////////
    
    fclose(entrada);
    fclose(saida);

    excluiLista(lista);

    return (EXIT_SUCCESS);
}

//Insere os dados de uma ordenação na lista
void insereNaLista(Lista *l, ordenacao *e) {
    //Entra se a lista esta vazia e adiciona os dados
    if (l->ini == NULL) {
        l->ini = e;
        l->fim = e;
    } else {//Entra se a lista já possui elementos e adiciona na ultima posição
        l->fim->prox = e;
        l->fim = e;
    }
}

//Libera o espaço da alocação dinamica 
void excluiLista(Lista *l) {
    //Anda pela fila leberando algoritmo por algoritmo
    for (ordenacao *p = l->ini; p != NULL;){
        ordenacao* t = p->prox;
        libera(p);
        p = t;
    }
    
    free(l); //Libera a lista
}