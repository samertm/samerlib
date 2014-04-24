#include "queue.h"

queue *new_queue() {
        int queue_initial_size = 10;
        queue *q = malloc(sizeof(queue));
        q->data = malloc(queue_initial_size * sizeof(void *));
        q->capacity = queue_initial_size;
        q->start = 0;
        q->end = 0;
        return q;
}

void queue_double_capacity(queue *q) {
        q->data = realloc(q->data, q->capacity * 2 * sizeof(void *));
        q->capacity *= 2;
}

void free_queue(queue *q) {
        free(q->data);
        free(q);
}

void queue_shift_right(queue *q) {
        int i;
        while (q->end >= q->capacity) {
                queue_double_capacity(q);
        }
        for (i = q->end; i > q->start; i--) {
                q->data[i] = q->data[i-1];
        }
        q->end++;
        q->start++;
}

void queue_push_left(queue *q, void *d) {
        if (q->start == 0) {
                queue_shift_right(q);
        }
        q->data[q->start-1] = d;
        q->start--;
}

void queue_push_right(queue *q, void *d) {
        while (q->end >= q->capacity) {
                queue_double_capacity(q);
        }
        q->data[q->end] = d;
        q->end++;
}

void *queue_pop_left(queue *q) {
        if (q->start == q->end) {
                return NULL;
        }
        return q->data[q->start++];
}

void *queue_pop_right(queue *q) {
        if (q->start == q->end) {
                return NULL;
        }
        return q->data[q->end-- - 1];
}

void *queue_peek_left(queue *q) {
        if (q->start == q->end) {
                return NULL;
        }
        return q->data[q->start];
}

void *queue_peek_right(queue *q) {
        if (q->start == q->end) {
                return NULL;
        }
        return q->data[q->end - 1];
}

void queue_clear(queue *q) {
        q->start = 0;
        q->end = 0;
}
