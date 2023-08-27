/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 03:24:16 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/27 00:29:32 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *key, char *value)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	if (!key && !value )
	{
		if (pipe(p->pipe) == -1)
		{
			ft_putstr_fd(strerror(errno), 2);
			exit(errno);
		}
	}
	p->cmd = NULL;
	p->key = key;
	p->value = value;
	p->next = NULL;
	p->previous = NULL;
	return (p);
}
