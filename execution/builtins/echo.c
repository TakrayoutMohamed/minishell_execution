#include "./../../libminishell.h"

int	echo(t_tree *tree)
{
	if (tree == NULL)
		return (printf("the tree passed to echo is not allocated\n"),-12);
	if (tree->message != NULL)
		printf("%s",tree->message);
	if (strcmp(tree->option, "-n") != 0)
	{
		printf("\n");
	}
	return (0);
}
