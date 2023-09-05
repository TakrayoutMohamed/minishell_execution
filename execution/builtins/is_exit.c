/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:47:52 by takra             #+#    #+#             */
/*   Updated: 2023/09/05 03:13:43 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

bool	is_exit(char *command)
{
	if (!command)
		return (false);
	if (!ft_strcmp(command, "exit"))
		return (true);
	return (false);
}
