#include "./../../libminishell.h"

/*redirect to the home directory and update oldpwd and pwd*/
void	cd_no_parametre(t_list	*env)
{
	char	*path;
	path = NULL;
	if (get_variable_value("HOME", env) == NULL)
		path = ft_strdup("/../.../../");
	else
		path = ft_strdup(get_variable_value("HOME", env));
	if (chdir(path) != 0)
	{
		print_error(errno);
		free(path);
		t_stats.status = errno;
		return ;
		// exit(EXIT_FAILURE);
	}
	else
	{
		if (!is_variable_exists("OLDPWD", env))
		{
			ft_lstadd_back(&env, ft_lstnew(ft_strdup("OLDPWD"), ft_strdup("NULL")));
		}
		if (!is_variable_exists("PWD", env))
			ft_lstadd_back(&env, ft_lstnew(ft_strdup("PWD"), getcwd(NULL, 0)));
		update_env_value("OLDPWD", "PWD", env);
		update_env_value("PWD", "HOME", env);
	}
	free(path);
}

/*redirect to some path with value and update the oldpwd and pwd*/
void	cd_with_paramitre(t_list *lst, t_list *env)
{
	char	*path;
	char	*home;
	char	*value;

	value = lst->value;
	home = NULL;
	path = NULL;
	t_stats.status = 1;
	if (ft_strncmp(value, "~", 1) == 0)
	{
		value++;
		home = ft_strdup(get_variable_value("HOME", env));
		path = ft_strjoin(home, value);
	}
	else if (ft_strcmp((lst->value), "-") == 0)
	{
		value++;
		if (is_variable_exists("OLDPWD", env))
			home = ft_strdup(get_variable_value("OLDPWD", env));
		path = ft_strjoin(home, value);
	}
	else
		path = ft_strdup(lst->value);
	if (chdir(path) != 0)
	{
		print_error(errno);
		free(home);
		free(path);
		t_stats.status = errno;
		return ;
		// exit(EXIT_FAILURE);
	}
	else
	{
		if (!is_variable_exists("OLDPWD", env))
		{
			if (ft_strcmp((lst->value), "-") == 0)
			{
				ft_putstr_fd("cd: OLDPWD not set\n", 2);
			}
			else
				ft_lstadd_back(&env, ft_lstnew(ft_strdup("OLDPWD"), NULL));
		}
		if (!is_variable_exists("PWD", env))
		{
			ft_lstadd_back(&env, ft_lstnew(ft_strdup("PWD"), getcwd(NULL, 0)));
		}
		update_env_value("OLDPWD", "PWD", env);
		free(get_variable_value("PWD", env));
		update_env_value("PWD", path, env);
	}
	free(home);
	free(path);
	t_stats.status = 0;
	// exit(EXIT_SUCCESS);
}

/*
*the first variable takes the list that have all the command data
*
*the sicond is a list that have the envirement values and keys
*
*
*/
void	cd(t_list *cmd_lst, t_list *env)
{
	t_list	*tmp;

	tmp = cmd_lst;
	if (tmp == NULL)
	{
		printf("the cmd_lst passed to the cd()\n");
		exit(-1);
	}
	if (ft_lstsize(tmp) == 1)
	{
		cd_no_parametre(env);
	}
	else if (ft_lstsize(cmd_lst) == 2)
	{
		tmp = tmp->next;
		cd_with_paramitre(tmp, env);
	}
	else
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		t_stats.status = 1;
		return ;
		// exit(EXIT_FAILURE);
	}
}
