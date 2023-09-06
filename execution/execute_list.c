/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:08 by takra             #+#    #+#             */
/*   Updated: 2023/09/06 17:55:19 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

static bool	is_output_builtins(t_list *lst_cmd, char *str)
{
	if (!str)
		return (false);
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
	while (waitpid(-1, &st, 0) != -1)
	{
		st1 = st;
		if (WIFSIGNALED(st))
		{
			st1 = t_stats.status;
		}
	}
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

void	set_status(int status)
{
	if (WIFEXITED(status))
		t_stats.status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		t_stats.status = WTERMSIG(status) + 128;
		if (status == -2)
			t_stats.status = 126;
	}
}

/*
* in position variable we store three value 
* 1 : the bigening of the list 
* 2 : the middle of the list 
* 3 : the end of the list 
*/
void	execute_list(t_list *lst, t_list **env)
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
			if (is_output_builtins(tmp->cmd, tmp->cmd->value))
				pipe_builtins(tmp, *env);
			else
				t_stats.status = builtins_no_output(tmp, env);
		}
		else
			execution(tmp, *env, position);
		tmp = tmp->next;
	}
	set_status(wait_allchilds());
}
