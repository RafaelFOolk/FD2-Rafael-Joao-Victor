
main: main.o limpatela.o functions.o
	@echo "Gerando arquivo executável."
	gcc *.o -o main

main.o: menuu.c
	@echo "Compilando objetos"
	gcc -c main.c

limpatela.o: limpatela.c
	@echo "Compilando objetos"
	gcc -c limpatela.c

functions.o: functions.c
	@echo "Compilando objetos"
	gcc -c functions.c



clean:
 @echo "Apagando objetos antigos"
 rm -f *.o main

 run:
 ./main