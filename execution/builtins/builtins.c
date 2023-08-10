#include "./../../libminishell.h"

void	builtins(t_tree *tree ,t_list *env)
{
	if (tree == NULL)
	{
		printf("the tree passed to builtins() is not allocated\n");
		exit(-1);
	}
	if (is_echo(tree->command))
		echo(tree, env);
	// else if (is_env(tree->command))
	env_(env);
	// else if (is_cd(tree->command))
	cd(tree, env);
	env_(env);
}
