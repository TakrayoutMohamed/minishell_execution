#include "./../../libminishell.h"

bool	is_echo(char *command)
{
	if (!strcmp(command, "echo"))
		return (true);
	return (false);
}
bool	is_cd(char *command)
{
	if (!strcmp(command, "cd"))
		return (true);
	return (false);
}
bool	is_pwd(char *command)
{
	if (!strcmp(command, "pwd"))
		return (true);
	return (false);
}
bool	is_export(char *command)
{
	if (!strcmp(command, "export"))
		return (true);
	return (false);
}
bool	is_unset(char *command)
{
	if (!strcmp(command, "unset"))
		return (true);
	return (false);
}
bool	is_env(char *command)
{
	if (!strcmp(command, "env"))
		return (true);
	return (false);
}
bool	is_exit(char *command)
{
	if (!strcmp(command, "exit"))
		return (true);
	return (false);
}

int	is_builtins(t_tree *tree)
{
	if (is_echo(tree->command))
		return (1);
	if (is_cd(tree->command))
		return (1);
	if (is_pwd(tree->command))
		return (1);
	if (is_export(tree->command))
		return (1);
	if (is_unset(tree->command))
		return (1);
	if (is_env(tree->command))
		return (1);
	if (is_exit(tree->command))
		return (1);
	return (0);
}
