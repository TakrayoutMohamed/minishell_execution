/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_variable_exists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 04:09:38 by takra             #+#    #+#             */
/*   Updated: 2023/08/18 04:09:40 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

/*check if a variable exists in envirement and return true else return false*/
bool	is_variable_exists(char *key, t_list *env)
{
	t_list	*tmp;

	tmp = env;
	if (key != NULL && tmp != NULL)
	{
		while (tmp != NULL)
		{
			if (ft_strcmp(key, tmp->key) == 0)
			{
				return (true);
			}
			tmp = tmp->next;
		}
	}
	return (false);
}