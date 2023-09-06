/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:48:29 by takra             #+#    #+#             */
/*   Updated: 2023/09/06 01:42:02 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

void	link_data(t_list **env, t_list **tmp)
{
	if ((*tmp)->previous != NULL && (*tmp)->next != NULL)
	{
		((*tmp)->previous)->next = (*tmp)->next;
		((*tmp)->next)->previous = (*tmp)->previous;
	}
	else if ((*tmp)->next == NULL && (*tmp)->previous != NULL)
		(*tmp)->previous->next = NULL;
	else if ((*tmp)->previous == NULL && (*tmp)->next != NULL)
	{
		*env = (*env)->next;
		(*tmp)->next->previous = NULL;
	}
}

/*remove a variable from the envirement's data*/
void	unset(t_list **env, char *variable_name)
{
	t_list	*tmp;
	t_list	*to_delete;

	tmp = *env;
	while (env && *env && variable_name && tmp)
	{
		if (ft_strcmp(tmp->key, variable_name) == 0)
		{
			to_delete = tmp;
			link_data(env, &tmp);
			ft_lstdelone(to_delete, del);
			return ;
		}
		tmp = tmp->next;
	}
	return ;
}
