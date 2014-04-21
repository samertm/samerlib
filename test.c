#include <stdio.h>
#include <samerlib/stack.h>

int main() {
        int x, y, z, *a, i;
        stack *s = new_stack();
        x = 1;
        y = 2;
        z = 4;
        for (i = 0; i < 8; i++) {
                stack_push(s, &x);
        }
        stack_push(s, &x);
        stack_push(s, &y);
        stack_push(s, &z);
        while ((a = (int *) stack_pop(s)) != NULL) {
                printf("%d", *a);
        }
        printf("\n");
        return 0;
}

