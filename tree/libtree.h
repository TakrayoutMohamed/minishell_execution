#ifndef LIBTREE_H_
#define LIBTREE_H_
#include <stdlib.h>
#include <stdio.h>
typedef struct s_tree {
	char *command;
	char *option;
	char *message;
	struct s_tree *left;
	struct s_tree *right;
} t_tree;

t_tree	*new_node(char *command, char *option, char *message);
void	add_left(t_tree **tree, t_tree *node);
void	add_right(t_tree **tree, t_tree *node);
void    print_tree(t_tree *tree);//this is for testing porpuse 

#endif
