#ifndef _SAMERLIB_QUEUE_H_
#define _SAMERLIB_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct {
        void **data;
        int start;
        int end;
        int capacity;
} queue;

queue *new_queue();
void free_queue(queue *q);
void queue_push_left(queue *q, void *d);
void queue_push_right(queue *q, void *d);
void *queue_pop_left(queue *q);
void *queue_pop_right(queue *q);
void *queue_peek_left(queue *q);
void *queue_peek_right(queue *q);
void queue_clear(queue *q);

#endif /* _SAMERLIB_QUEUE_H_ */
