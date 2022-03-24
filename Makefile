#Antes de executar o progama entre na pasta onde 
#o programa esta localizado.
echo = echo

#para executar compile digite no terminal "make compile"
compile:
	gcc -o trab1 *.c	

#para executar run digite no terminal "make run opt=comando top=qtdTop arq=diretoriodo_arquivo"	
run:
	./trab1 $(opt) $(top) $(arq)
	
#para executar compile-run digite no terminal "make compile-run opt=comando top=qtdTop arq=diretoriodo_arquivo"
compile-run: 
	make compile
	make run
	
#para executar valgrind digite no terminal "make valgrind opt=comando top=qtdTop arq=diretoriodo_arquivo"
valgrind:
	make compile
	valgrind ./trab1 $(opt) $(top) $(arq)
#para executar clear digite no terminal "make clear"
clean:
	rm trab1
	rm ED2_Trab1_results.txt
	clear
#Finalizado
