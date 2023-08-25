#include "./../../libminishell.h"

/*execute one of the builtind depending on the first lst node's value*/
void	builtins_no_output(t_list *lst ,t_list *env, int position)
{
	char	**matrix;
	char	*path;
	t_list	*cmd_lst;

	cmd_lst = lst->cmd;
	if (is_unset(cmd_lst->value))
	{
		cmd_lst = cmd_lst->next;
		unset(env, cmd_lst->value);
	}
	else if (is_cd(cmd_lst->value))
	{
		cd(cmd_lst, env);
	}
	else if (is_exit(cmd_lst->value))
	{
		ft_putstr_fd("here is exit function\n", 1);
	}
	else if (is_export(cmd_lst->value) && ft_lstsize(cmd_lst) > 1)
	{
		export(cmd_lst, env);
	}
}
