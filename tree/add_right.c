/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:40:08 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/02 23:42:16 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libtree.h"

/*add to the right of a root if it is NULL other wise it print an error
 message*/
void	add_right(t_tree **tree, t_tree *node)
{
	t_tree *tmp;

	tmp = *tree;
	if (tmp->right != NULL)
	{
		printf("this address is already in use in add_right()\n ");
		return ;
	}
	tmp->right = node;
}
