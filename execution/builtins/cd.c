#include "./../../libminishell.h"

void	cd(t_tree *tree)
{
	if (tree != NULL)
	{
		printf("the tree passed to the cd()\n");
		exit(-1);
	}
	if (tree->message != NULL)
		chdir(tree->message);
	else
		chdir("~");
}
