/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_no_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:47:13 by takra             #+#    #+#             */
/*   Updated: 2023/09/06 01:48:33 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

/*execute one of the builtind depending on the first lst node's value*/
int	builtins_no_output(t_list *lst, t_list **env)
{
	t_list	*cmd_lst;

	cmd_lst = lst->cmd;
	t_stats.status = 0;
	if (is_unset(cmd_lst->value) && cmd_lst->value)
	{
		cmd_lst = cmd_lst->next;
		if (cmd_lst && cmd_lst->value)
			unset(env, cmd_lst->value);
	}
	else if (is_cd(cmd_lst->value))
		cd(cmd_lst, *env);
	else if (is_exit(cmd_lst->value))
	{
		if (ft_lstsize(cmd_lst) > 2)
			t_stats.status = 1;
		exit_(cmd_lst);
	}
	else if (is_export(cmd_lst->value) && ft_lstsize(cmd_lst) > 1)
		t_stats.status = export(cmd_lst, *env);
	return (t_stats.status);
}
