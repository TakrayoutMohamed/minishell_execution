#include "./../../libminishell.h"

/*remove a variable from the envirement's data*/
void	unset(t_list *env, char *variable_name)
{
	t_list	*tmp;
	t_list	*to_delete;

	tmp = env;
	if (!env || !variable_name)
		return ;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, variable_name) == 0)
		{
			to_delete = tmp;
			if (tmp->previous != NULL && tmp->next != NULL)
			{
				(tmp->previous)->next = tmp->next;
				(tmp->next)->previous = tmp->previous;
			}
			else if (tmp->next == NULL && tmp->previous != NULL)
				tmp->previous->next = NULL;
			else if (tmp->previous == NULL && tmp->next != NULL)
				tmp->next->previous = NULL;
			ft_lstdelone(to_delete, del);
			return ;
		}
		tmp = tmp->next;
	}
	t_stats.status = 0;
}
