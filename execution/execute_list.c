/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:08 by takra             #+#    #+#             */
/*   Updated: 2023/09/03 04:23:42 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

static bool	is_output_builtins(t_list *lst_cmd, char *str)
{
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
	int	i;

	i = 1;
	while (waitpid(-1, &st, 0) != -1)
	{
		fprintf(stderr, "here is the process %d\n", i);
		i++;
	}
	return (st);
}

void	close_all_pipes(t_list *lst)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = lst;
	while (tmp->previous != NULL)
		tmp = tmp->previous;
	while (tmp)
	{
		fprintf(stderr, "==================\n");
		fprintf(stderr, "the lst value = %d\n", i);
		fprintf(stderr, "input\n");
		if (close(tmp->pipe[0]) == -1)
		{
			print_error(errno);
			fprintf(stderr, " \n");
		}
		fprintf(stderr, "output\n");
		if (close(tmp->pipe[1]) == -1)
		{
			print_error(errno);
			fprintf(stderr, " \n");
		}
		fprintf(stderr, "==================\n");
		i++;
		tmp = tmp->next;
	}
}

/*
* in position variable we store three value 
* 1 : the bigening of the list 
* 2 : the middle of the list 
* 3 : the end of the list 
*/
void	execute_list(t_list *lst, t_list *env)
{
	t_list	*tmp;
	int		position;

	tmp = lst;
	while (tmp)
	{
		if (tmp == ft_lstlast(lst))
			position = 3;
		else if (tmp == lst)
			position = 1;
		else
			position = 2;
		if (is_builtins(tmp->cmd))
		{
			if (is_output_builtins(tmp->cmd, tmp->cmd->value))
				pipe_builtins(tmp, env);
			else
				t_stats.status = builtins_no_output(tmp, env);
		}
		else
			execution(tmp, env, position);
		tmp = tmp->next;
	}
	close_all_pipes(lst);
	t_stats.status = wait_allchilds();
}
