/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:39:11 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/15 16:43:31 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

int	prompt(int argc, char **argv, t_list *env)
{
	char	*command;
	t_list	*lst;

	int i = 0;
	while (i < 5)
	{
		command = readline("ⵜⴰⵎⴰⵣⵖⴰ> ");
		lst = parse_data(command);
		if (lst == NULL)
			return (printf("the list is empty"), exit(-1), 0);
		else
		{
			execute_list(lst, env);
		}
		add_history(command);
		free(command);
		
	}
	// rl_clear_history();
	// command = readline("done> ");
	return (0);
}
