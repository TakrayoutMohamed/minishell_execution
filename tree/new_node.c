#include "./libtree.h"

t_tree	*new_node(char *command, char *option, char *message)
{
	t_tree *tree;

	tree = malloc (sizeof(t_tree));
	if (!tree)
		return (NULL);
	else
	{
		tree->command = command;
		tree->message = message;
		tree->option = option;
		tree->left = NULL;
		tree->right = NULL;
	}
	return (tree);
}