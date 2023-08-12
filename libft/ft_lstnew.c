/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 03:24:16 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/12 13:13:19 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *key, char *value, t_cmd *cmd1)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	if (pipe(p->pipe) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(errno);
	}
	// ft_putstr_fd("here is the sigfault00000000\n", 2);
	p->cmd = cmd1;
	p->key = key;
	p->value = value;
	p->next = NULL;
	p->previous = NULL;
	return (p);
}
