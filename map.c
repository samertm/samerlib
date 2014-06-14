#include "map.h"

static int map_hash(char *key);

map *new_map() {
        map *m = malloc(sizeof(map));
        m->keys = new_queue();
        return m;
}

void free_map(map *m) {
        free_queue(m->keys);
        free(m);
}

void map_add(map *m, char *key, void *item) {
        m->store[map_hash(key)%50] = item;
        if (!map_contains(m, key)) {
                queue_push_right(m->keys, key);
        }
}

void *map_get(map *m, char *key) {
        if (!map_contains(m, key)) {
                return NULL;
        }
        return m->store[map_hash(key)%50];
}

int map_contains(map *m, char *key) {
        int i;
        queue *keys = m->keys;
        int end = keys->end;
        for (i = keys->start; i < end; i++) {
                if (strcmp(key, keys->data[i]) == 0) {
                        return 1;
                }
        }
        return 0;
}

static int map_hash(char *key) {
        int i;
        int sum = 0;
        for (i = 0; key[i] != '\0'; sum += key[i++]); /* heh... */
        return sum;
}        

/* void *map_delete(map *m, char *key) { */
/*         if (!map_contains(m, key)) { */
/*                 return NULL; */
                
