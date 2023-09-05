/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:47:41 by takra             #+#    #+#             */
/*   Updated: 2023/09/05 03:10:54 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

bool	is_echo(char *command)
{
	if (!command)
		return (false);
	if (!ft_strcmp(command, "echo"))
		return (true);
	return (false);
}
