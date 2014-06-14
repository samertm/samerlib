#include <stdio.h>
#include <samerlib/stack.h>
#include <samerlib/queue.h>
#include <samerlib/map.h>

#define TEST_MAP

int main() {
#ifdef TEST_STACK
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
#endif /* TEST_STACK */
#ifdef TEST_QUEUE
        int x, y, z, *a, i;
        queue *q = new_queue();
        x = 1;
        y = 3;
        z = 5;
        for (i = 0; i < 4; i++) {
                queue_push_right(q, &y);
        }
        queue_push_left(q, &x);
        queue_push_right(q, &z);
        printf("%d %d\n", q->start, q->end);
        while ((a = (int *) queue_pop_right(q)) != NULL) {
                printf("%d", *a);
        }
        printf("\n");
#endif /* TEST_QUEUE */
#ifdef TEST_MAP
        map *m = new_map();
        map_add(m, "bro", 1);
        fprintf(stderr, "%p", map_get(m, "bro"));
        free_map(m);
        fprintf(stderr, "donezo\n");
#endif /* TEST_MAP */
        return 0;
}
