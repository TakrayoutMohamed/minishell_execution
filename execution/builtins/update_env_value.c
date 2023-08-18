#include "./../../libminishell.h"

bool	update_env_value(char *key, char *new_key, t_list *env)
{
	t_list	*tmp;
	char	*variable_value;

	tmp = env;
	if (key == NULL || env == NULL)
	{
		return (false);
	}
	while (tmp)
	{
		if (ft_strcmp(key, tmp->key) == 0)
		{
			variable_value =  get_variable_value(new_key, env);
			if (variable_value == NULL)
				variable_value = ft_strdup(new_key);
			free(tmp->value);
			// tmp->value = (char *)malloc(ft_strlen(variable_value) + 1);
			// if (!tmp->value)
			// 	return (printf("error while allocating at update_env_value()"), exit(-2), 0);
			// ft_strlcpy(tmp->value, variable_value, ft_strlen(variable_value) + 1);
			tmp->value = variable_value;
			return (true);
		}
		tmp = tmp->next;
	}
	return (false);
}
