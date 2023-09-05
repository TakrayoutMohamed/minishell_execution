/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:48:03 by takra             #+#    #+#             */
/*   Updated: 2023/09/05 03:11:56 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

bool	is_pwd(char *command)
{
	if (!command)
		return (false);
	if (!ft_strcmp(command, "pwd"))
		return (true);
	return (false);
}
