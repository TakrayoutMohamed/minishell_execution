#include "./../../libminishell.h"

/*execute one of the builtind depending on the first lst node's value*/
void	builtins_no_output(t_list *lst ,t_list *env, int position)
{
	char	**matrix;
	char	*path;
	t_list	*lst_cmd;

	lst_cmd = lst->cmd;
	if (is_unset(lst_cmd->value))
	{
		lst_cmd = lst_cmd->next;
		unset(env, lst_cmd->value);
	}
	else if (is_cd(lst_cmd->value))
	{
		cd(lst_cmd, env);
	}
	else if (is_exit(lst_cmd->value))
	{
		ft_putstr_fd("here is exit function\n", 1);
	}
	else if (is_export(lst_cmd->value) && ft_lstsize(lst_cmd) > 1)
	{
		export(lst_cmd, env);
	}
}
