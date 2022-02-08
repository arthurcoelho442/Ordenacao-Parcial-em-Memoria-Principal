#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define Maiores 1
#define Estatisticas 2
#define Dados 3

//struct com os dados da ordenação utilizada
typedef struct ordenacao {
    char *algoritmo;
    int comp;
    int trocas;
    double tempo;
    struct ordenacao *prox;
}ordenacao;

typedef struct lista{
    ordenacao *ini, *fim;
    int tam;
}Lista;

ordenacao* selectionSort(int qtd, int *dados){
    ordenacao* selec = (ordenacao*) malloc(sizeof(ordenacao));
    int comp = 0;
    int trocas = 0;
    clock_t init = clock();
    
    for(int i=0; i<qtd; i++){
        int min_id = i;
        for(int j=i; j<qtd; j++)
            if(dados[j] < dados[min_id])
                min_id = j;
        comp++;
        if(dados[i] > dados[min_id]){
            trocas++;
            int aux = dados[i];
            dados[i] = dados[min_id];
            dados[min_id] = aux;
        }
    }
    
    clock_t fim = clock();
    double tempo = (double)(fim - init)/CLOCKS_PER_SEC;
 
    selec->algoritmo = (char*) malloc(sizeof(char)*100);
    strcpy(selec->algoritmo, "selecao");
    selec->comp = comp;
    selec->trocas = trocas;
    selec->tempo = tempo;
    selec->prox = NULL;
    
    return selec;
}
ordenacao* insertionSort(int qtd, int *dados){
    ordenacao* insert = (ordenacao*) malloc(sizeof(ordenacao));
    int comp = 0;
    int trocas = 0;
    clock_t init = clock();
    for(int i=1, j; i<qtd; i++){
        int c = dados[i];
        for(j= i-1; j>= 0; j--){
            comp++;
            if(dados[j] > c){
                trocas++;
                dados[j+1] = dados[j];
            }else
                break;
        }
        dados[j+1] = c;
    }
    
    clock_t fim = clock();
    double tempo = (double)(fim - init)/CLOCKS_PER_SEC;
 
    insert->algoritmo = (char*) malloc(sizeof(char)*100);
    strcpy(insert->algoritmo, "insercao");
    
    insert->comp = comp;
    insert->trocas = trocas;
    insert->tempo = tempo;
    insert->prox = NULL;
    
    return insert;
}
ordenacao* shellSort(){
    return NULL;//alterar depois
}
ordenacao* quickSort(){
    return NULL;//alterar depois
}
ordenacao* heapSort(){
    return NULL;//alterar depois
}

void insereNaLista(Lista *l, ordenacao *e){
    if(l->ini == NULL){
        l->ini = e;
        l->fim = e;
    }else{
        l->fim->prox = e; 
        l->fim = e; 
    }
    l->tam++;
}
void excluiLista(Lista *l){
    for(ordenacao *p = l->ini; p != NULL; p = p->prox){
        free(p->algoritmo);
        free(p);
    }
    free(l);     
}

int main(int argc, char** argv) {
    Lista *lista = (Lista*) malloc(sizeof(lista));//Lista com todas as ordenações executadas
    //Manipulação do arquivo
    FILE* entrada;//Arquivo de entrada para o sistema
    FILE* saida;//Arquivo de saida
    
    //Abre o arquivo de Entrada e o de Saida
    entrada = fopen(argv[3], "r+");
    saida = fopen("saida.txt", "a+");
    
    //Verifica se o arquivo de Entrada é existente
    if (entrada == NULL){
        printf ("\n\tErro Arquivo de entrada não encontrado\n\n");
        return 0;
    }
    ///////////////////////////////////////
    
    
    //Tratamento do dados do arquivo 
    int qtd;//quantidade de itens
    fscanf(entrada, "%d", &qtd);
    int dados[qtd];//todos os dados do arquivo
    for(int i=0; i<qtd; i++)
        fscanf(entrada, "%d", &dados[i]);
    ///////////////////////////////
    
    //Analise do [-123iseqha] para definir a execução do programa
    int opt;
    int impressao[3] = {0,0,0};
    int dadosAux[qtd];
    ordenacao *alg; //algoritimo de ordenação
    while ((opt = getopt(argc, argv, "asieqh123")) != -1) {
        switch (opt) {
        case '1': //Adiciona a lista para imprimir em tela os T maiores elementos
            for(int i=0; i<3; i++)
                if(impressao[i] == 0){
                    impressao[i] = Maiores;
                    break;
                }
            break;
        case '2': //Adiciona a lista para imprimir as estatísticas
            for(int i=0; i<3; i++)
                if(impressao[i] == 0){
                    impressao[i] = Estatisticas;
                    break;
                }
            break;
        case '3': //Adiciona em lista para imprimir os dados/estatísticas separados por tab
            for(int i=0; i<3; i++)
                if(impressao[i] == 0){
                    impressao[i] = Dados;
                    break;
                }
            break;
        case 'a': //Executa todos os métodos de ordenação
            break;
        case 's': //Executa método de ordenação por seleção
            for(int i=0; i<qtd; i++)
                dadosAux[i] = dados[i];
            alg = selectionSort(qtd, dadosAux);
            insereNaLista(lista, alg); //insere na lista
            break;
        case 'i': //Executa método de ordenação por inserção
            for(int i=0; i<qtd; i++)
                dadosAux[i] = dados[i];
            alg = insertionSort(qtd, dadosAux);
            insereNaLista(lista, alg); //insere na lista
            break;
        case 'e': //Executa método de ordenação por shellsort
            for(int i=0; i<qtd; i++)
                dadosAux[i] = dados[i];
            alg = shellSort();
            insereNaLista(lista, alg); //insere na lista
            break;
        case 'q': //Executa método de ordenação por quicksort
            for(int i=0; i<qtd; i++)
                dadosAux[i] = dados[i];
            alg = quickSort();
            insereNaLista(lista, alg); //insere na lista
            break;
        case 'h': //Executa método de ordenação por heapsort
            for(int i=0; i<qtd; i++)
                dadosAux[i] = dados[i];
            alg = heapSort();
            insereNaLista(lista, alg); //insere na lista
            break;
        default: //Imprime o codigo de erro do opt
            printf ("getopt retornou com character de codigo 0%o\n", opt);
        }
    }
    //////////////////////////////////////////////////////////
    
    //Impressão////////////
    for(int i=0; i<3; i++){
        if(impressao[i] == Maiores){//Imprime em tela os T maiores elementos
            for(int i=(qtd-1);i>=(qtd - atoi(argv[2])); i--)
                printf("%d\n", dadosAux[i]);
        }else if(impressao[i] == Estatisticas){//Imprime as estatísticas
            for(ordenacao* p = lista->ini; p!=NULL; p = p->prox){
                printf("\nTempo de CPU:\t%lf", p->tempo);
                printf("\nComparações:\t%d", p->comp);
                printf("\nTrocas:\t%d\n", p->trocas);
            }
        }else if(impressao[i] == Dados){//Imprime dados/estatísticas po tab
            for(ordenacao* p = lista->ini; p!=NULL; p = p->prox)
                fprintf(saida, "%s\t%s\t%d\t%s\t%d\t%d\t%lf\n", p->algoritmo, argv[3], qtd, argv[2],  p->comp, p->trocas, p->tempo);
        }
    }
    //////////////////////
    
    fclose(entrada);
    fclose(saida);
    
    excluiLista(lista);
    
    return (EXIT_SUCCESS);
}
