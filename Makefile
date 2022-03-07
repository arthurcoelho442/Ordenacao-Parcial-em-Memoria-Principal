#Antes de executar o progama entre na pasta onde 
#o programa esta localizado.


compile:
	gcc *.c	
	
run:
	./a.out entrada_teste.txt
	
compile-run:
	make compile
	make run
	
valgrind:
	make compile
	valgrind ./a.out entrada_teste.txt

#Finalizado