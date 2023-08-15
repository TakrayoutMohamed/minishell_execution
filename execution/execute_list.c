#include "./../libminishell.h"

void	execute_list(t_list *lst, t_list *env)
{
	if (is_builtins(lst))
		builtins(lst ,env);
	else
	{
		// print_lst(lst);
		exit(1);
		execution(lst, env);
	}
}
