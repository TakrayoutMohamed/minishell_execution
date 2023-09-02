/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:48:34 by takra             #+#    #+#             */
/*   Updated: 2023/09/02 18:48:35 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

/*update the value of key in envirement with allocation for the new value*/
bool	update_env_value(char *key, char *new_key, t_list *env)
{
	t_list	*tmp;
	char	*variable_value;

	tmp = env;
	if (key == NULL || env == NULL)
	{
		return (false);
	}
	while (tmp)
	{
		if (ft_strcmp(key, tmp->key) == 0)
		{
			variable_value = ft_strdup(get_variable_value(new_key, env));
			if (variable_value == NULL)
			{
				variable_value = ft_strdup(new_key);
			}
			else
				free(tmp->value);
			tmp->value = variable_value;
			return (true);
		}
		tmp = tmp->next;
	}
	return (false);
}
