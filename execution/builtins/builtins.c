#include "./../../libminishell.h"

/*execute one of the builtind depending on the first lst node's value*/
void	builtins(t_list *lst ,t_list *env)
{
	if (lst == NULL)
	{
		printf("the lst passed to builtins() is not allocated\n");
		exit(-1);
	}
	// if (is_echo(lst->cmd->value))
	// 	echo(lst, env);
	else if (is_env(lst->value))
		env_(env);
	else if (is_cd(lst->value))
	{
		cd(lst, env);
		env_(env);

	}
	else if (is_export(lst->value))
	{
		printf("th lst->key = |%s|\n",lst->key);
		printf("th lst->value = |%s|\n",lst->value);
		// printf("th lst->cmd->value = |%s|\n",lst->cmd->value);
		export(lst, env);
	}
}
