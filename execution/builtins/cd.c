#include "./../../libminishell.h"

bool	update_env_value(char *key, char *new_value, t_list *env)
{
	t_list	*tmp;

	tmp = env;
	if (key == NULL || env == NULL)
	{
		return (false);
	}
	while (tmp)
	{
		if (strcmp(key, tmp->key) == 0) // need to add implimentation of ft_strcmp()
		{
			free(tmp->value);
			tmp->value = (char *)malloc(ft_strlen(new_value) * sizeof(char) + 1);
			if (!tmp->value)
				return (printf("error while allocating at update_env_value()"), exit(-2), 0);
			ft_strlcpy(tmp->value, new_value, ft_strlen(new_value) + 1);
			return (true);
		}
		tmp = tmp->next;
	}
	return (false);
}

void	cd(t_list *lst, t_list *env)
{
	char	*directory;
	char	*str;

	if (lst == NULL)
	{
		printf("the lst passed to the cd()\n");
		exit(-1);
	}
	if (ft_strncmp(lst->cmd->message, "~", ft_strlen("~")))
	{
		directory = get_variable_value("HOME", env);
		// directory = ft_strjoin(directory, ++(lst->message));
	}
	else if (!ft_strncmp(lst->cmd->options, "-", 1) && ft_strlen(lst->cmd->message) == 1)
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
