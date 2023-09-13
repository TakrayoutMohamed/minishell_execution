/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 03:24:16 by mohtakra          #+#    #+#             */
/*   Updated: 2023/09/13 01:50:55 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *key, char *value)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	p->cmd = NULL;
	if (key)
		p->key = key;
	else
		p->key = NULL;
	if (value)
		p->value = value;
	else
		p->value = NULL;
	p->next = NULL;
	p->previous = NULL;
	return (p);
}
