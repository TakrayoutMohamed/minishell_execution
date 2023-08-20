/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:43:00 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/20 19:22:07 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

bool	is_echo(char *command)
{
	if (!ft_strcmp(command, "echo"))
		return (true);
	return (false);
}
bool	is_cd(char *command)
{
	if (!ft_strcmp(command, "cd"))
		return (true);
	return (false);
}
bool	is_pwd(char *command)
{
	if (!ft_strcmp(command, "pwd"))
		return (true);
	return (false);
}
bool	is_export(char *command)
{
	if (!ft_strcmp(command, "export"))
		return (true);
	return (false);
}
bool	is_unset(char *command)
{
	if (!ft_strcmp(command, "unset"))
		return (true);
	return (false);
}
bool	is_env(char *command)
{
	if (!ft_strcmp(command, "env"))
		return (true);
	return (false);
}
bool	is_exit(char *command)
{
	if (!ft_strcmp(command, "exit"))
		return (true);
	return (false);
}

/*edit all chars to lower case*/
void	ft_strtolower(char *str)
{
	if (!str)
		return ;
	while (str && *str)
	{
		*str = ft_tolower(*str);
		str++;
	}
}

/*return true if the first node's value is a builtins programe*/
int	is_builtins(t_list *lst)
{
	char *value_to_lower;

	value_to_lower = ft_strdup(lst->value);
	ft_strtolower(value_to_lower);
	if (is_echo(value_to_lower))
		return (free(value_to_lower), 1);
	if (is_cd(value_to_lower))
		return (free(value_to_lower), 1);
	if (is_pwd(value_to_lower))
		return (free(value_to_lower), 1);
	if (is_export(value_to_lower))
		return (free(value_to_lower), 1);
	if (is_unset(value_to_lower))
		return (free(value_to_lower), 1);
	if (is_env(value_to_lower))
		return (free(value_to_lower), 1);
	if (is_exit(value_to_lower))
		return (free(value_to_lower), 1);
	return (free(value_to_lower), 0);
}
