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