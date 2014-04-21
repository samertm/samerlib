#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
        /* An array of (void *) */
        void **data;
        int length;
        int capacity;
} stack;

stack *new_stack();
void stack_push(stack *s, void *d);
void *stack_pop(stack *s);
void stack_clear(stack *s);
static void stack_double_capacity(stack *s);

#endif /* __STACK_H */
