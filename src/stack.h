#ifndef STACK__H
#define STACK__H

#include <stdint.h>

#define STACK_DEFAULT_SIZE (u32)1
#define STACK_CREATE(st) st = malloc(sizeof(stack)); stack_create(st);

typedef int32_t  s32;
typedef uint32_t u32;
typedef struct{
    s32 *bottom,
        *top;
    u32  size;
} stack;

//  0 : success
// -2 : failed to allocate array
int stack_create(stack *st);
//  0 : success
// -1 : failed to allocate new array
int stack_resize(stack *st);
void stack_free(stack *st);
void stack_push(stack *st, s32 v);
s32 stack_peek(stack *st);
// returns 0 on empty stack
s32 stack_pop(stack *st);

#endif
