/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list_to_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:48:57 by takra             #+#    #+#             */
/*   Updated: 2023/09/02 18:48:58 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

/*return a double pointer created from the list pointer entered (lst)*/
char	**convert_list_to_matrix(t_list *lst)
{
	char	**matrix;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	if (lst == NULL)
		return (NULL);
	matrix = (char **)malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	if (!matrix)
		return (NULL);
	while (tmp != NULL)
	{
		matrix[i] = ft_strdup(tmp->value);
		i++;
		tmp = tmp->next;
	}
	matrix[i] = NULL;
	return (matrix);
}
