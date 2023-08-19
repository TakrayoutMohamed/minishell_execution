#include "./../../libminishell.h"

void	update_shlvl(t_list *env)
{
	t_list	*tmp;
	char	*itoa; 

	tmp = env;
	if (!env)
		return ;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, "SHLVL") == 0)
		{
			if (ft_atoi(get_variable_value("SHLVL", env)) >= 999)
			{
				free(get_variable_value("SHLVL", env));
				update_env_value("SHLVL", "1", env);
			}
			else
			{
				itoa = ft_itoa(ft_atoi(get_variable_value("SHLVL", env)) + 1);
				free(get_variable_value("SHLVL", env));
				update_env_value("SHLVL", itoa, env);
				free(itoa);
			}
			return ;
		}
		tmp = tmp->next;
	}
}
