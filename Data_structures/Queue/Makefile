$(CC) = gcc
final: queue.o linked_list.o
		$(CC) -g3 queue.o linked_list.o -o final

queue.o: queue.h
		$(CC) -g3 -c queue.c 

linked_list.o: linked_list.c linked_list.h
		$(CC) -g3 -c linked_list.c 
