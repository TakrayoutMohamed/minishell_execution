#ifndef LIBTREE_H_
#define LIBTREE_H_

typedef struct s_tree {
    char *commande;
    char *option;
    struct tree *left;
    struct tree *right;
}   t_tree;

#endif
