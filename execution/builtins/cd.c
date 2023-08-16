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
				variable_value = new_key;
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
	char	*path;
	char	*home;
	char	*current_dir;

	if (lst == NULL)
	{
		printf("the lst passed to the cd()\n");
		exit(-1);
	}
	if (ft_lstsize(lst) == 1)
	{
		if (chdir(get_variable_value("HOME", env)) != 0)
		{
			print_error(errno);
			exit(errno);
		}
		else
		{
			update_env_value("OLDPWD", "PWD", env);
			update_env_value("PWD", "HOME", env);
		}
	}
	else
	{
		lst = lst->next;
		if (ft_strncmp((lst->value), "~", 1) == 0)
		{
			home = get_variable_value("HOME", env);
			path = ft_strjoin(home, ++(lst->value));
			// free(home);
		}
		else
		{
			path = lst->value;
		}

			ft_putstr_fd("the path is:", 1);
			ft_putstr_fd(path, 1);
			ft_putstr_fd(":", 1);
			// exit(33);
		if (chdir(path) != 0)
		{
			print_error(errno);
			// exit(33);
		}
		else
		{
			update_env_value("OLDPWD", "PWD", env);
			update_env_value("PWD", path, env);
		}
		// chdir(directory);
	}
}
