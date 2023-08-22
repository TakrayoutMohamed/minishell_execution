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
		if (tmp == lst)
			position = 1;
		else if (tmp == ft_lstlast(lst))
			position = 3;
		else
			position = 2;
		if (is_builtins(lst->cmd))
			builtins(tmp ,env, position);
		else
		{
			// exit(1);
			execution(tmp, env, position);
		}
		tmp = tmp->next;
	}
}
