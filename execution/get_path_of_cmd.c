/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_of_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:20 by takra             #+#    #+#             */
/*   Updated: 2023/09/14 05:59:54 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

bool	is_with_path(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '/')
				return (true);
			str++;
		}
	}
	return (false);
}

/*return true if the program in the path is exist and its executable*/
static bool	is_cmd_in_dir(char *path, char *program)
{
	char			*pseudo_path;
	char			*full_path;

	full_path = NULL;
	if (!is_with_path(program))
	{
		pseudo_path = ft_strjoin("/", program);
		full_path = ft_strjoin(path, pseudo_path);
		free(pseudo_path);
	}
	else
		full_path = ft_strdup(program);
	// printf("full path = %s existance %d\n", full_path, access(full_path, F_OK));
	if (access(full_path, F_OK) == 0)
	{
		return (free(full_path), true);
	}
	free(full_path);
	return (false);
}

static char	*path_of_cmd(t_list *env, char *cmd)
{
	char	*path;
	char	*pseudo_path;
	char	**matrix;
	int		i;

	i = -1;
	path = NULL;
	matrix = NULL;
	matrix = ft_split(get_variable_value("PATH", env), ':');
	if (!matrix)
		return (ft_freematrix(matrix), NULL);
	while (matrix[++i])
	{
		if (is_cmd_in_dir(matrix[i], cmd))
		{
			pseudo_path = ft_strjoin("/", cmd);
			path = ft_strjoin(matrix[i], pseudo_path);
			free(pseudo_path);
			break ;
		}
	}
	// if (path == NULL)
	// 	t_stats.status = 127;
	return (ft_freematrix(matrix), path);
}

/*this function returns the executable of the command "cmd" with
* within its absolute path depending on the env variable $PATH
* exemple : if the cmd is "ls" than the  return will be like "/bin/ls" (in linux)
*/
char	*get_path_of_cmd(t_list *env, char *cmd)
{
	char	*path;

	path = NULL;
	if (is_with_path(cmd))
	{
		if (is_cmd_in_dir("", cmd) && access(cmd, X_OK) == -1)
			return (print_error_permission(cmd), NULL);
		else if (is_cmd_in_dir("", cmd) && access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
	}
	else if (is_variable_exists("PATH", env))
	{
		path = path_of_cmd(env, cmd);
		if (path == NULL)
		{
			if (is_cmd_in_dir("./", cmd) && access(cmd, X_OK) == 0)
				return (ft_strdup(cmd));
			print_error_notfound(cmd);
		}
		else if (access(path, X_OK) == -1)
			print_error_permission(path);
		return (path);
	}
	print_error_nofiledir(cmd);
	return (path);
}
