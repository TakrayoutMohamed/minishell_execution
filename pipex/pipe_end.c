/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:44 by takra             #+#    #+#             */
/*   Updated: 2023/09/14 02:54:06 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

static void	pipe_end_infile(t_list *lst)
{
	if (lst->infile > 0)
	{
		dup2(lst->infile, 0);
		close(lst->infile);
	}
	else if (lst->previous != NULL)
	{
		dup2(lst->previous->pipe[0], 0);
		close(lst->previous->pipe[0]);
	}
	close(lst->pipe[0]);
}

static void	pipe_end_outfile(t_list *lst)
{
	if (lst->outfile > 0)
	{
		dup2(lst->outfile, 1);
		close(lst->outfile);
	}
	else
	{
		if (lst->outfile == -1)
		{
			dup2(lst->pipe[1], 1);
		}
	}
	close(lst->pipe[1]);
}

int	pipe_end(t_list *lst, char **argv, char **envp, t_list **p_ids)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		close_pipe(lst->pipe);
		if (lst->previous != NULL)
			close(lst->previous->pipe[0]);
		ft_putstr_fd("minishell : fork", 2);
		print_error(errno);
		return (EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		pipe_end_infile(lst);
		pipe_end_outfile(lst);
		execve(argv[0], argv, envp);
		exit(127);
	}
	ft_lstadd_back(p_ids, ft_lstnew(NULL, ft_itoa((int)pid)));
	close_pipe(lst->pipe);
	if (lst->previous != NULL)
		close(lst->previous->pipe[0]);
	return (EXIT_SUCCESS);
}
