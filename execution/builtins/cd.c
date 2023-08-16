#include "./../../libminishell.h"

/*redirect to the home directory and update oldpwd and pwd*/
void	cd_no_parametre(t_list	*env)
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

/*redirect to some path with value and update the oldpwd and pwd*/
void	cd_with_paramitre(t_list *lst, t_list *env)
{
	char	*path;
	char	*home;

	if (ft_strncmp((lst->value), "~", 1) == 0)
	{
		home = get_variable_value("HOME", env);
		path = ft_strjoin(home, ++(lst->value));
	}
	else
		path = lst->value;
	if (chdir(path) != 0)
	{
		print_error(errno);
		exit(errno);
	}
	else
	{
		update_env_value("OLDPWD", "PWD", env);
		update_env_value("PWD", path, env);
		free(path);
	}
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
	if (lst == NULL)
	{
		printf("the lst passed to the cd()\n");
		exit(-1);
	}
	if (ft_lstsize(lst) == 1)
	{
		cd_no_parametre(env);
	}
	else
	{
		lst = lst->next;
		cd_with_paramitre(lst, env);
		// chdir(directory);
	}
}
