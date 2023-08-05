/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:39:11 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/06 00:13:51 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

int	prompt(int argc, char **argv, t_list *env)
{
	char	*command;
	t_tree	*tree;

	int i = 0;
	while (i < 5)
	{
		command = readline("ⵜⴰⵎⴰⵣⵖⴰ> ");
		tree = parse_data(command);
		if (tree == NULL)
			return (printf("the tree is empty"), exit(-1), 0);
		else
		{
			execute_tree(tree, env);
		}
		add_history(command);
		free(command);
		
	}
	// rl_clear_history();
	// command = readline("done> ");
	return (0);
}
