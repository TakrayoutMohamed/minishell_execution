/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:08 by takra             #+#    #+#             */
/*   Updated: 2023/09/11 20:29:34 by mohtakra         ###   ########.fr       */
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
		st1 = st;
		if (WIFSIGNALED(st))
		{
			st1 = t_stats.status;
		}
		t_stats.flag_sigint = 1;
	}
	t_stats.flag_sigint = 0;
	return (st1);
}

int	get_position(t_list *lst, t_list *tmp)
{
	int	position;

	position = 0;
	if (tmp == ft_lstlast(lst))
		position = 3;
	else if (tmp == lst)
		position = 1;
	else
		position = 2;
	return (position);
}

void	close_previous_input(t_list *lst)
{
	while (lst->previous != NULL)
	{
		close(lst->pipe[0]);
		lst = lst->previous;
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
	int		position;

	tmp = lst;
	while (tmp)
	{
		position = get_position(lst, tmp);
		if (is_builtins(tmp->cmd))
		{
			t_stats.status = 0;
			if (is_output_builtins(tmp, tmp->cmd, tmp->cmd->value))
				pipe_builtins(tmp, *env);
			else
				t_stats.status = builtins_no_output(tmp, env);
		}
		else if (!execution(tmp, *env, position))
			return (close_previous_input(tmp), EXIT_FAILURE);
		tmp = tmp->next;
	}
	set_status(wait_allchilds());
	return (EXIT_SUCCESS);
}
