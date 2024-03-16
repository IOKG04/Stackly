#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "stack.h"

int stack_create(stack *st){
    st->size = STACK_DEFAULT_SIZE;
    st->bottom = malloc(STACK_DEFAULT_SIZE * sizeof(s32));
    st->top = st->bottom;
    if(st->bottom == NULL) return -2;

    return 0;
}

int stack_resize(stack *st){
    intptr_t tb_difference = st->top - st->bottom;
    s32 *previous_bottom = st->bottom;

    st->bottom = malloc(st->size * sizeof(s32) * 2);
    if(st->bottom == NULL) return -1;
    st->top = st->bottom + tb_difference;
    st->size *= 2;

    memcpy(st->bottom, previous_bottom, tb_difference * sizeof(s32));
    free(previous_bottom);
    return 0;
}

void stack_free(stack *st){
    free(st->bottom);
    free(st);
}

void stack_push(stack *st, s32 v){
    if((++(st->top)) - st->bottom >= st->size){
	stack_resize(st);
    }
    *(st->top) = v;
}

s32 stack_peek(stack *st){
    return *(st->top);
}

s32 stack_pop(stack *st){
    if(st->top == st->bottom) return 0;
    return *((st->top)--);
}
