#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

int main()
{
    LinkedList* queue = createQueue();
    add(2,queue);
    add(5,queue);
    add(15,queue);
    add(145,queue);
    add(85,queue);
    display(queue);
    del(queue);
    display(queue);
    return 0;
}
