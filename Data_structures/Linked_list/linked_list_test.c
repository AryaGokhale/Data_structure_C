#include <stdio.h>
#include "linked_list.h"

int main()
{
    
    LinkedList* list = createLinkedList();

    add(10, list);
    add(20, list);
    insert(15,7,list);
    //del(1,list);
    display(list);

    return 0;
}
