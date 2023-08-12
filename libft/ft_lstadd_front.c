/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 04:51:47 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/12 20:47:10 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL && new != NULL)
	{
		*lst = new;
	}
	else if (new)
	{
		new->next = *lst;
		(*lst)->previous = new;
		*lst = new;
		(*lst)->next = NULL;
	}
}
