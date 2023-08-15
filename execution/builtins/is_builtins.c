/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:43:00 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/15 22:34:00 by mohtakra         ###   ########.fr       */
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

int	is_builtins(t_list *lst)
{
	if (is_echo(lst->cmd->value))
		return (1);
	if (is_cd(lst->cmd->value))
		return (1);
	if (is_pwd(lst->cmd->value))
		return (1);
	if (is_export(lst->cmd->value))
		return (1);
	if (is_unset(lst->cmd->value))
		return (1);
	if (is_env(lst->cmd->value))
		return (1);
	if (is_exit(lst->cmd->value))
		return (1);
	return (0);
}
