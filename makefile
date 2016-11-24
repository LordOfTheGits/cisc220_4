
copier: main.o mystring.o
	gcc -Wall -o copier main.o mystring.o

main.o: main.c
	gcc -Wall -c main.c

mystring.o: mystring.c mystring.h
	gcc -Wall -c mystring.c