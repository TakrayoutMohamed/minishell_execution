/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:08 by takra             #+#    #+#             */
/*   Updated: 2023/09/14 06:38:43 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

int	check_lstsize(t_list *lst)
{
	while (lst->previous != NULL)
		lst = lst->previous;
	return (ft_lstsize(lst));
}

static bool	is_output_builtins(t_list *lst, t_list *lst_cmd, char *str)
{
	if (!str)
		return (false);
	if (is_exit(str) && check_lstsize(lst) > 1 && \
	(ft_lstsize(lst_cmd) == 2 || ft_lstsize(lst_cmd) == 1))
		return (true);
	if (is_echo(str))
		return (true);
	if (is_env(str))
		return (true);
	if (is_export(str) && ft_lstsize(lst_cmd) == 1)
		return (true);
	if (is_pwd(str))
		return (true);
	return (false);
}

int	wait_allchilds(void)
{
	int	st;
	int	st1;

	st1 = t_stats.status;
	t_stats.flag_sigint = 1;
	while (waitpid(-1, &st, 0) != -1)
	{
		t_stats.flag_sigint = 0;
		if (WIFSIGNALED(st))
		{
			if (WTERMSIG(st) == SIGINT || WTERMSIG(st) == SIGINT)
				st1 = st;
		}
		else
			st1 = st;
		t_stats.flag_sigint = 1;
	}
	t_stats.flag_sigint = 0;
	return (st1);
}

void	pipe_fork_failure(t_list *p_ids)
{
	kill_child_proccs(p_ids);
	wait_allchilds();
	ft_lstclear(&p_ids, del);
}

/*
* in position variable we store three value 
* 1 : the bigening of the list 
* 2 : the middle of the list 
* 3 : the end of the list 
*/
int	execute_list(t_list *lst, t_list **env)
{
	t_list	*tmp;
	t_list	*p_ids;

	tmp = lst;
	p_ids = NULL;
	while (tmp)
	{
		if (is_builtins(tmp->cmd))
		{
			if (pipe(tmp->pipe) == -1)
				return (print_error(errno), t_stats.status = 1, EXIT_FAILURE);
			t_stats.status = 0;
			if (is_output_builtins(tmp, tmp->cmd, tmp->cmd->value))
			{
				if (pipe_builtins(tmp, *env, &p_ids) == EXIT_FAILURE)
					return (pipe_fork_failure(p_ids), EXIT_FAILURE);
			}
			else
				t_stats.status = builtins_no_output(tmp, env);
		}
		else if (execution(tmp, *env, &p_ids) == EXIT_FAILURE)
			return (pipe_fork_failure(p_ids), EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (set_status(wait_allchilds()), ft_lstclear(&p_ids, del), 0);
}
