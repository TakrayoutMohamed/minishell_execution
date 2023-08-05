#include "./../libminishell.h"

void	execute_tree(t_tree *tree, t_list *env)
{
	if (is_builtins(tree))
		builtins(tree ,env);
	else
	{
		print_tree(tree);
		exit(1);
		execution(tree, env);
	}
}
