/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_matrix_to_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:02 by takra             #+#    #+#             */
/*   Updated: 2023/09/02 18:49:03 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

t_list	*convert_matrix_to_list(char **matrix)
{
	t_list	*lst;

	lst = NULL;
	if (!matrix)
		return (NULL);
	while (*matrix)
	{
		ft_lstadd_back(&lst, ft_lstnew(NULL, ft_strdup(*matrix)));
		matrix++;
	}
	return (lst);
}
