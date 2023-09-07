/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:47:18 by takra             #+#    #+#             */
/*   Updated: 2023/09/07 23:15:05 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

void	update_pwd_oldpwd(t_list **env, char *path, char *oldpath)
{
	if (!is_variable_exists("OLDPWD", *env))
		ft_lstadd_back(env, ft_lstnew(ft_strdup("OLDPWD"), NULL));
	if (get_variable_value("OLDPWD", *env))
		free(get_variable_value("OLDPWD", *env));
	update_env_value("OLDPWD", ft_strdup(oldpath), *env);
	if (!is_variable_exists("PWD", *env))
		ft_lstadd_back(env, ft_lstnew(ft_strdup("PWD"), NULL));
	if (get_variable_value("PWD", *env))
		free(get_variable_value("PWD", *env));
	update_env_value("PWD", ft_strdup(path), *env);
}

/*redirect to the home directory and update oldpwd and pwd*/
void	cd_no_parametre(t_list	**env)
{
	char	oldpath[MAXPATHLEN];

	if (!is_variable_exists("HOME", *env))
	{
		t_stats.status = 256;
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return ;
	}
	getcwd(oldpath, MAXPATHLEN);
	if (chdir(get_variable_value("HOME", *env)) != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(get_variable_value("HOME", *env), 2);
		print_error(errno);
		t_stats.status = 256;
	}
	else
	{
		update_pwd_oldpwd(env, get_variable_value("HOME", *env), oldpath);
	}
}

int	change_dir(char *path)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		if (chdir(path) == 0)
		{
			ft_putstr_fd("minishell: cd: ", 2);
			ft_putstr_fd("error retrieving current directory: ", 2);
			ft_putstr_fd("getcwd: cannot access parent directories: ", 2);
			ft_putstr_fd("No such file or directory\n", 2);
			return (free(cwd), 1);
		}
	}
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		print_error(errno);
		t_stats.status = 256;
		return (free(cwd), 0);
	}
	return (free(cwd), 1);
}

/*redirect to some path with value and update the oldpwd and pwd*/
void	cd_with_paramitre(t_list *lst, t_list **env)
{
	char	*path;
	char	oldpath[MAXPATHLEN];
	char	newpath[MAXPATHLEN];

	t_stats.status = 0;
	if (ft_strcmp((lst->value), "-") == 0)
	{
		if (is_variable_exists("OLDPWD", *env))
			path = ft_strdup(get_variable_value("OLDPWD", *env));
		else
		{
			print_strerror_set_status("minishell: cd: OLDPWD not set\n", 256);
			return ;
		}
	}
	else
		path = ft_strdup(lst->value);
	getcwd(oldpath, MAXPATHLEN);
	if (change_dir(path))
		update_pwd_oldpwd(env, getcwd(newpath, MAXPATHLEN), oldpath);
	free(path);
}

/*
*the first variable takes the list that have all the command data
*the sicond is a list that have the envirement values and keys
*/
void	cd(t_list *cmd_lst, t_list **env)
{
	t_list	*tmp;

	tmp = cmd_lst;
	if (tmp == NULL)
		return ;
	if (ft_lstsize(tmp) == 1)
	{
		t_stats.status = 0;
		cd_no_parametre(env);
	}
	else if (ft_lstsize(cmd_lst) == 2)
	{
		tmp = tmp->next;
		t_stats.status = 0;
		cd_with_paramitre(tmp, env);
	}
	else
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		t_stats.status = 256;
		return ;
	}
}
