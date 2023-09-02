/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:48:14 by takra             #+#    #+#             */
/*   Updated: 2023/09/02 18:48:14 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

/*check if the str entered has a form of an acceptable variable*/
bool	is_valid_identifier(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
	{
		return (false);
	}
	if (!ft_isalpha(*str) && *str != '_')
		return (false);
	while (*str && *str != '=' && *str != '+')
	{
		if (ft_isalpha(*str) || *str == '_' || ft_isdigit(*str))
		{
			i++;
			str++;
		}
		else
			return (false);
	}
	if (*str == '+' && ft_strncmp(str, "+=", 2) != 0)
		return (false);
	return (true);
}
