#include "./../../libminishell.h"

int	echo(t_tree *tree)
{
	if (tree == NULL)
		return (printf("the tree passed to echo is not allocated\n"),-12);
	if (tree->message != NULL)
		ft_putstr(tree->message);
	if (strcmp(tree->option, "-n") != 0)
	{
		ft_putstr("\n");
	}
	return (0);
}
