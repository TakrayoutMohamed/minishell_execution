/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:49:23 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/15 22:49:04 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

/*return the value of a key in env with no allocation here*/
char	*get_variable_value(char *key, t_list *env)
{
	t_list	*tmp;

	tmp = env;
	if (key != NULL && tmp != NULL)
	{
		while (tmp != NULL)
		{
			if (ft_strcmp(key, tmp->key) == 0)
			{
				return (tmp->value);
			}
			tmp = tmp->next;
		}
	}
	return (NULL);
}
