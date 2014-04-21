#include "btree.h"

btree *new_btree() {
        btree * t = (btree *) malloc(sizeof(btree));
        t->root = NULL;
        return t;
}

static void free_btree_node(btree_node *n) {
        if (n == NULL) {
                return;
        }
        free_btree_node(n->left);
        free_btree_node(n->right);
        free(n);
}

void free_btree(btree *t) {
        if (t == NULL) {
                return;
        }
        free_btree_node(t->root);
        free(t);
}
