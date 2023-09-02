#include "./../libminishell.h"

static bool	is_output_builtins(t_list *lst_cmd, char *str)
{
	if (is_echo(str))
		return (true);
	if (is_env(str))
		return (true);
	if (is_export(str) && ft_lstsize(lst_cmd) == 1)
		return (true);
	if (is_pwd(str))
		return (true);
	return (false);
}

/*
* in position variable we store three value 
* 1 : the bigening of the list 
* 2 : the middle of the list 
* 3 : the end of the list 
*/
void	execute_list(t_list *lst, t_list *env)
{
	t_list	*tmp;
	int		position;

	tmp = lst;
	while (tmp)
	{
		if (tmp == ft_lstlast(lst))
			position = 3;
		else if (tmp == lst)
			position = 1;
		else
			position = 2;
		if (is_builtins(tmp->cmd))
		{
			if (is_output_builtins(tmp->cmd, tmp->cmd->value))
				pipe_builtins(tmp, env);
			else
				builtins_no_output(tmp, env);
		}
		else
		{
			execution(tmp, env, position);
		}
		tmp = tmp->next;
	}
}
