#include "./../libminishell.h"

void	print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
		printf("**%s = %s** ",lst->key, lst->value);
		lst = lst->next;
	}
	lst = tmp;
	printf("\n");
}

void	execute_list(t_list *lst, t_list *env)
{
	// print_lst(lst->cmd);
	// exit(20);
	if (is_builtins(lst->cmd))
		builtins(lst->cmd ,env);
	else
	{
		exit(1);
		execution(lst, env);
	}
}
