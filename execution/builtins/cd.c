/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:47:18 by takra             #+#    #+#             */
/*   Updated: 2023/09/02 18:47:19 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

/*redirect to the home directory and update oldpwd and pwd*/
void	cd_no_parametre(t_list	*env)
{
	char	*oldpath;

	oldpath = NULL;
	if (!is_variable_exists("HOME", env))
	{
		t_stats.status = 1;
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return ;
	}
	oldpath = getcwd(NULL, 0);
	if (chdir(get_variable_value("HOME", env)) != 0)
	{
		print_error(errno);
		t_stats.status = errno;
	}
	else
	{
		if (is_variable_exists("OLDPWD", env))
			update_env_value("OLDPWD", oldpath, env);
		if (is_variable_exists("PWD", env))
			update_env_value("PWD", "HOME", env);
	}
	free(oldpath);
}

void	update_pwd_oldpwd(t_list *env, char *path, char *oldpath)
{
	if (is_variable_exists("OLDPWD", env))
	{
		free(get_variable_value("OLDPWD", env));
		update_env_value("OLDPWD", oldpath, env);
	}
	if (is_variable_exists("PWD", env))
	{
		free(get_variable_value("PWD", env));
		update_env_value("PWD", path, env);
	}
}

/*redirect to some path with value and update the oldpwd and pwd*/
void	cd_with_paramitre(t_list *lst, t_list *env)
{
	char	*path;
	char	*oldpath;

	if (ft_strcmp((lst->value), "-") == 0)
	{
		if (is_variable_exists("OLDPWD", env))
			path = ft_strdup(get_variable_value("OLDPWD", env));
		else
		{
			print_strerror_set_status("minishell: cd: OLDPWD not set\n", 1);
			return ;
		}
	}
	else
		path = ft_strdup(lst->value);
	oldpath = getcwd(NULL, 0);
	if (chdir(path) != 0)
	{
		print_error(errno);
		t_stats.status = errno;
	}
	else
		update_pwd_oldpwd(env, path, oldpath);
	free(oldpath);
	free(path);
}

/*
*the first variable takes the list that have all the command data
*the sicond is a list that have the envirement values and keys
*/
void	cd(t_list *cmd_lst, t_list *env)
{
	t_list	*tmp;

	tmp = cmd_lst;
	if (tmp == NULL)
		return ;
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
	}
}
