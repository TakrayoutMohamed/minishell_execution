/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:40:08 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/02 23:43:20 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libtree.h"

/*add to the left of a root if it is NULL other wise it print an error
 message*/
void	add_left(t_tree **tree, t_tree *node)
{
	t_tree *tmp;

	tmp = *tree;
	if (tmp->left != NULL)
	{
		printf("this address is already in use in add_left()\n ");
		return ;
	}
	tmp->left = node;
}
