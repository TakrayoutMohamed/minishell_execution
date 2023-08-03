#include "./../libminishell.h"

void	execute_tree(t_tree *tree, char **env)
{
	if (is_builtins(tree))
		builtins(tree);
	else
	{
		print_tree(tree);
		exit(1);
		execution(tree, env);
	}
}
