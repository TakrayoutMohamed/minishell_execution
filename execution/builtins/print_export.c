#include "./../../libminishell.h"

/*print the data in the envirement with export apearence*/
void	print_export(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	if (env == NULL)
		return ;
	while (tmp->previous != NULL)
		tmp = tmp->previous;
	while (tmp)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(tmp->key, 1);
		if (tmp->value != NULL)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(tmp->value, 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
}
