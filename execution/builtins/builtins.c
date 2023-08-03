#include "./../../libminishell.h"

void	builtins(t_tree *tree)
{
	if (tree == NULL)
	{
		printf("the tree passed to builtins() is not allocated\n");
		exit(-1);
	}
	if (is_echo(tree->command))
	{
		echo(tree);
	}
}
