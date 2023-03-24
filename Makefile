all: main.c
	gcc -c main.c stack.c -I.
	gcc main.o stack.o -o main.exe
	main.exe