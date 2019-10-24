all: CEnigma

CEnigma: main.o func.o menu.o title.o
	gcc -Wall main.o func.o menu.o title.o -o CEnigma

main.o: main.c
	gcc -c main.c

func.o: func.c
	gcc -c func.c

menu.o: menu.c
	gcc -c menu.c

title.o: title.c
	gcc -c title.c
clear:
	rm -rf *o