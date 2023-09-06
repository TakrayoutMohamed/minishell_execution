/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:05:09 by mohtakra          #+#    #+#             */
/*   Updated: 2023/09/06 20:17:33 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

/*prints the envirement pears key=value from the entered linked list env*/
void	env_(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	if (env == NULL)
		return ;
	while (tmp->previous != NULL)
		tmp = tmp->previous;
	while (tmp)
	{
		if (tmp->value != NULL)
		{
			ft_putstr_fd(tmp->key, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(tmp->value, 1);
			ft_putstr_fd("\n", 1);
		}
		tmp = tmp->next;
	}
	t_stats.status = 0;
}
