$(CC) = gcc
final: linked_list_test.o linked_list.o 
		$(CC) -g3 linked_list_test.o linked_list.o -o final

linked_list_test.o: linked_list_test.c linked_list.h
		$(CC) -g3 -c linked_list_test.c 

linked_list.o: linked_list.c linked_list.h
		$(CC) -g3 -c linked_list.c 


