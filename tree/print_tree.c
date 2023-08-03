/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:44:28 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/03 21:01:47 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libtree.h"

void    printtabs(int nbrtabs)
{
	int i;

	i = 0;
	while (i < nbrtabs)
	{
		printf("\t");
		i++;
	}
}

void    print_tree_rec(t_tree *tree, int level)
{
	if (tree == NULL)
	{
		printtabs(level);
		// printf("\nthe end of tree\n");
	}
	else
	{
		printtabs(level);
		printf("command = \"%s\"", tree->command);
		if (tree->option)
			printf(", options = \"%s\"", tree->option);
		if (tree->message)
			printf(", message = \"%s\"", tree->message);
		printf("\n");		
		printtabs(level);
		printf("left\n");
		print_tree_rec(tree->left, level + 1);

		printtabs(level);
		printf("right\n");
		print_tree_rec(tree->right, level + 1);

		// printtabs(level);
		printf("done!!\n");
	}
}

void    print_tree(t_tree *tree)
{
	print_tree_rec(tree, 0);
}
