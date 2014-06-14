#include <stdio.h>
#include <string.h>
#include "queue.h"

typedef struct {
        /* TODO make hash resize */
        void* store[50];
        queue *keys;
} map;

map *new_map(void);
void free_map(map *m);
void map_add(map *m, char *key, void *item);
void *map_get(map *m, char *key);
int map_contains(map *m, char *key);

