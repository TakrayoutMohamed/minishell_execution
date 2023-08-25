/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:05:09 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/25 13:53:12 by mohtakra         ###   ########.fr       */
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
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	status = 0;
}
