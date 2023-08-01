#include "./../../libminishell.h"

int	is_builtins(char *command)
{
	if (is_echo(command))
		return (1);
	if (is_cd(command))
		return (1);
	if (is_pwd(command))
		return (1);
	if (is_export(command))
		return (1);
	if (is_unset(command))
		return (1);
	if (is_env(command))
		return (1);
	if (is_exit(command))
		return (1);
	return (0);
}
