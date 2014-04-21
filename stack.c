#include "stack.h"

void stack_push(stack *s, void *d) {
        while (s->length >= s->capacity) {
                stack_double_capacity(s);
        }
        s->data[s->length] = d;
        s->length++;
}

stack *new_stack() {
        int stack_initial_size = 10;
        stack *s = malloc(sizeof(stack));
        s->data = malloc(stack_initial_size * sizeof(void *));
        s->length = 0;
        s->capacity = stack_initial_size;
        return s;
}

void stack_double_capacity(stack *s) {
        s->data = realloc(s->data, s->capacity * 2 * sizeof(void *));
        s->capacity *= 2;
}

void *stack_pop(stack *s) {
        if (s->length == 0) {
                return NULL;
        }
        void *r = s->data[s->length-1];
        s->length--;
        return r;
}

void stack_clear(stack *s) {
        s->length = 0;
}
