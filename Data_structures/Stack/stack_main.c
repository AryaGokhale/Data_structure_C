#include <stdio.h>
#include "stack_header.h"

int main()
{
    Stack* stack = createStack();

    push(7,stack);
    push(10,stack);
    pop(stack);
    push(17,stack);
    push(53,stack);
    
    display(stack);

    return 0;

}