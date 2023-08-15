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
			free(tmp->value);
			tmp->value = (char *)malloc(ft_strlen(variable_value) + 1);
			if (!tmp->value)
				return (printf("error while allocating at update_env_value()"), exit(-2), 0);
			ft_strlcpy(tmp->value, variable_value, ft_strlen(variable_value) + 1);
			return (true);
		}
		tmp = tmp->next;
	}
	return (false);
}

/*
*the first variable takes the list that have all the command data
*
*the sicond is a list that have the envirement values and keys
*
*
*/
void	cd(t_list *lst, t_list *env)
{
	char	*old_dir;
	char	*current_dir;

	if (lst == NULL)
	{
		printf("the lst passed to the cd()\n");
		exit(-1);
	}
	if (ft_lstsize(lst) == 1)
	{
		update_env_value("OLDPWD", "PWD", env);
		update_env_value("PWD", "HOME", env);
		if (chdir(get_variable_value("HOME", env)) != 0)
		{
			print_error(errno);
			exit(errno);
		}
	}
	if (ft_strcmp(lst->value, "~"))
	{
		directory = get_variable_value("HOME", env);
		// directory = ft_strjoin(directory, ++(lst->value));
	}
	else if (!ft_strncmp(lst->options, "-", 1) && ft_strlen(lst->value) == 1)
	{
		directory = get_variable_value("OLDPWD", env);
	}

	if (chdir(directory) != 0)
	{
		print_error(errno);
		ft_putstr_fd(directory, 1);
	}
	else
	{
		printf("\ndirectory = %s\n",directory);
		update_env_value("OLDPWD", get_variable_value("PWD", env), env);
		printf("\ndirectory = %s\n",directory);
		update_env_value("PWD", directory, env);
		// exit(7);
	}
	// chdir(directory);
}
