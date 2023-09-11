/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_beginning.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:33 by takra             #+#    #+#             */
/*   Updated: 2023/09/11 22:49:46 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

static void	pipe_beginning_infile(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (lst->infile > 0)
	{
		dup2(lst->infile, 0);
		close(lst->infile);
	}
	close(lst->pipe[0]);
}

static void	pipe_beginning_outfile(t_list *lst)
{
	if (lst->outfile > 0)
	{
		dup2(lst->outfile, 1);
		close(lst->outfile);
	}
	else
	{
		dup2(lst->pipe[1], 1);
	}
	close(lst->pipe[1]);
}

int	pipe_beginning(t_list *lst, char **argv, char **envp, t_list **p_ids)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (close_pipe(lst->pipe), ft_putstr_fd("minishell : fork", 2), print_error(errno), EXIT_FAILURE);
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		pipe_beginning_infile(lst);
		pipe_beginning_outfile(lst);
		execve(argv[0], argv, envp);
		exit(127);
	}
	close(lst->pipe[1]);
	ft_lstadd_back(p_ids, ft_lstnew(NULL, ft_itoa((int)pid)));
	return (EXIT_SUCCESS);
}
