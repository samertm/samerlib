#ifndef __BTREE_H_
#define __BTREE_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct n {
        int val;
        struct n *left;
        struct n *right;
} btree_node;

typedef struct {
        btree_node *root;
} btree;

btree *new_btree(void);
btree *btree_from_file(char *filename);
void free_btree(btree *t);
static void free_btree_node(btree_node *n);
#endif /* __BTREE_H_ */
