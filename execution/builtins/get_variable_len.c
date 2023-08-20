/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:52:16 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/20 19:18:17 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

/*return the len of a variable in the form of bash variables*/
int	get_variable_len(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (i);
	while (str && *str)
	{
		if (ft_isalpha(*str) || *str == '_' || ft_isdigit(*str))
		{
			i++;
			str++;
		}
		else
		{
			break ;
		}
	}
	return (i);
}
