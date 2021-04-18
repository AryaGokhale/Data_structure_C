$(CC)=gcc

final:stack_main.o stack_func.o
		$(CC) -g3 stack_main.o stack_func.o -o final

stack_main.o: stack_main.c stack_header.h
		$(CC) -g3 -c stack_main.c

stack_func.o: stack_func.c stack_header.h 
		$(CC) -g3 -c stack_func.c 