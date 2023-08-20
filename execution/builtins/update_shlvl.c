#include "./../../libminishell.h"

/*increment envirement variable "SHLVL" if exits else create it with value 1*/
void	update_shlvl(t_list *env)
{
	t_list	*tmp;
	char	*itoa; 

	tmp = env;
	if (!env)
		return ;
	if (is_variable_exists("SHLVL", env))
	{
		if (ft_atoi(get_variable_value("SHLVL", env)) >= 999 \
		|| ft_atoi(get_variable_value("SHLVL", env)) < 0)
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
	}
	else
	{
		ft_lstadd_back(&env, ft_lstnew(ft_strdup("SHLVL"), ft_strdup("1")));
	}
}
