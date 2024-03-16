#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack *data, *return_stack;

int main(int argc, char **argv){
    // create stacks
    STACK_CREATE(data)

    // cleanm and return
    stack_free(data);
    return 0;
}
