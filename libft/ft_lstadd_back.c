/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:00:05 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/12 20:49:30 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new != NULL)
	{
		if (*lst)
		{
			temp = ft_lstlast(*lst);
			temp->next = new;
			new->previous = temp;
			new->next = NULL;
		}
		else
		{
			ft_lstadd_front(lst, new);
		}
	}
}
