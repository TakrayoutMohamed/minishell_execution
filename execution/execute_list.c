/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:08 by takra             #+#    #+#             */
/*   Updated: 2023/09/12 06:31:07 by takra            ###   ########.fr       */
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

	t_stats.flag_sigint = 1;
	while (waitpid(-1, &st, WUNTRACED) != -1)
	{
		t_stats.flag_sigint = 0;
		st1 = st;
		t_stats.flag_sigint = 1;
	}
	t_stats.flag_sigint = 0;
	return (st1);
}

// int	get_position(t_list *lst, t_list *tmp)
// {
// 	int	position;

// 	position = 0;
// 	if (tmp == ft_lstlast(lst))
// 		position = 3;
// 	else if (tmp == lst)
// 		position = 1;
// 	else
// 		position = 2;
// 	return (position);
// }

void	close_previous_input(t_list *lst)
{
	while (lst->previous != NULL)
	{
		close(lst->previous->pipe[0]);
		lst = lst->previous;
	}
}

void	kill_child_procs(t_list *p_ids)
{
	if (!p_ids)
		return ;
	while (p_ids)
	{
		signal(SIGINT, SIG_DFL);
		kill(ft_atoi(p_ids->value), SIGINT);
		p_ids = p_ids->next;
	}
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
			t_stats.status = 0;
			if (is_output_builtins(tmp, tmp->cmd, tmp->cmd->value))
			{
				if (pipe_builtins(tmp, *env, &p_ids) == EXIT_FAILURE)
				{
					return (kill_child_procs(p_ids), ft_lstclear(&p_ids, del), close_previous_input(tmp), EXIT_FAILURE);
				}
			}
			else
				t_stats.status = builtins_no_output(tmp, env);
		}
		else if (execution(tmp, *env, &p_ids) == EXIT_FAILURE)
		{
			return (kill_child_procs(p_ids), ft_lstclear(&p_ids, del), close_previous_input(tmp), EXIT_FAILURE);
		}
		tmp = tmp->next;
	}
	ft_lstclear(&p_ids, del);
	set_status(wait_allchilds());
	return (EXIT_SUCCESS);
}
