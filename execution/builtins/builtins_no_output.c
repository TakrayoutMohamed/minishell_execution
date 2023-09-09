/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_no_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:47:13 by takra             #+#    #+#             */
/*   Updated: 2023/09/09 05:56:17 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

void	close_previous_pipes(t_list *lst)
{
	if (lst->previous != NULL)
		close(lst->previous->pipe[0]);
	close(lst->pipe[1]);
}

/*execute one of the builtind depending on the first lst node's value*/
int	builtins_no_output(t_list *lst, t_list **env)
{
	t_list	*cmd_lst;

	cmd_lst = lst->cmd;
	t_stats.status = 0;
	if (cmd_lst->value && is_unset(cmd_lst->value))
	{
		cmd_lst = cmd_lst->next;
		if (cmd_lst && cmd_lst->value)
			unset(env, cmd_lst);
	}
	else if (is_cd(cmd_lst->value))
		cd(cmd_lst, env);
	else if (is_exit(cmd_lst->value))
	{
		if (ft_lstsize(cmd_lst) > 2)
			t_stats.status = 256;
		exit_(cmd_lst);
	}
	else if (is_export(cmd_lst->value) && ft_lstsize(cmd_lst) > 1)
		t_stats.status = export(cmd_lst, env);
	close_previous_pipes(lst);
	return (t_stats.status);
}
