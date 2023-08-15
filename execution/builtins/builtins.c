#include "./../../libminishell.h"

void	builtins(t_list *lst ,t_list *env)
{
	if (lst == NULL)
	{
		printf("the lst passed to builtins() is not allocated\n");
		exit(-1);
	}
	if (is_echo(lst->cmd->value))
		echo(lst, env);
	else if (is_env(lst->cmd->value))
		env_(env);
	else if (is_cd(lst->cmd->value))
		cd(lst, env);
	env_(env);
}
