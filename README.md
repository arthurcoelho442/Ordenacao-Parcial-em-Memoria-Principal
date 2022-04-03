# Trabalho-ED-II
Este trabalho trata de Ordenação Parcial em Memória Principal, com o desenvolvimento de um programa em C capaz de ler arquivos de números inteiros e ordená-los de forma a obter os T maiores elementos usando algum dos seguintes algoritmos: ordenação por seleção, ordenação por inserção, shellsort, quicksort e heapsort.

seguindo o modelo de entrada ./a.out [-123iseqha] top_T caminho_arquivo

para [-123iseqha] temos as seguintes parâmetros:

- (a) Executa todos os métodos de ordenação;
- (s) Executa método de ordenação por seleção
-	(i) Executa método de ordenação por inserção
-	(e) Executa método de ordenação por shellsort
-	(q) Executa método de ordenação por quicksort
-	(h) Executa método de ordenação por heapsort 
-	(1) imprime em tela os T maiores elementos:
	
	Exemplo: Top 5 para entrada [100,300,400,200,500,50,1,10]
	
	500
	
	400
	
	300
	
	200
	
	100

- (2) imprime estatísticas: 
	Tempo de CPU: 	0.0001 segundos.
  Comparações:		300         	
  Trocas:		200

- (3) imprime dados/estatísticas separados por tab: 
	[algoritmo	arquivo	tam.	T(top)	comp. 	trocas	tempo(s)]
	seleção	./in/5.txt	5	5	x	y	0.00001
