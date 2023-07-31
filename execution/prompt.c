#include "./../libminishell.h"

int	prompt(int argc, char *argv, char *env)
{
	char	*command;
	t_tree	*tree;

	int i = 0;
	while (i++ < 5)
	{
		command = readline("ⵜⴰⵎⴰⵣⵖⴰ> ");
		tree = parse_data(command);
		add_history(command);
		free(command);
	}
		rl_clear_history();
		command = readline("done> ");
	return (0);
}