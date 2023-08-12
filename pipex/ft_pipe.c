
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:27:44 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/08 19:12:51 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

void	print_matrix(char **matrix)
{
	int	i = 0;
	int j;

	ft_putchar_fd('{', 1);
	while (matrix[i])
	{
		j = 0;
		ft_putchar_fd('[', 1);
		while (matrix[i][j])
		{
			ft_putchar_fd(matrix[i][j], 1);
			j++;
		}
		ft_putchar_fd(']', 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putchar_fd('}', 1);
}

void	print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	fprintf(stderr,"\n{\n");
	while (lst != NULL)
	{
		fprintf(stderr,"\n[\n");
		fprintf(stderr,"**%s = %s** \n",lst->key, lst->value);
		fprintf(stderr,"**commnd = %s %s %s** \n",lst->cmd->command, lst->cmd->options,lst->cmd->message);
		fprintf(stderr,"**pipe[0] = %d , pipe[1] = %d** \n",lst->pipe[0], lst->pipe[1]);
		fprintf(stderr,"\n]\n");
		lst = lst->next;
	}
	fprintf(stderr,"\n}\n");
	lst = tmp;
	fprintf(stderr,"\n");
}

void	close_pipe(int pipe_fd[2])
{
	if (close(pipe_fd[0]) == -1)
	{
		print_error(errno);
		exit(errno);
	}
	if (close(pipe_fd[1]) == -1)
	{
		print_error(errno);
		exit(errno);
	}
}

void	ft_pipe_middle(t_list *lst)
{
	pid_t	pid;
	char	*cmd[4];

	cmd[0] = lst->cmd->command;
	cmd[1] = lst->cmd->options;
	cmd[2] = lst->cmd->message;
	cmd[3] = NULL;

	pid = fork();
	if (pid == -1)
	{
		print_error(errno);
		exit(errno);
	}
	else if (pid == 0) // this is child
	{
		if (lst->previous != NULL)
		{
			close_pipe(lst->previous->pipe);
		}
		dup2(lst->pipe[0], 0);
		if (lst->next != NULL)
		{
			dup2(lst->next->pipe[1], 1);
			close_pipe(lst->next->pipe);
		}
		close_pipe(lst->pipe);
		execve(cmd[0], cmd, NULL);
	}
	else //this is parent
	{
		if (lst->previous != NULL)
		{
			close_pipe(lst->previous->pipe);
		}
		close(lst->pipe[1]);
		if (lst->next != NULL)
		{
			dup2(lst->pipe[0], 0);
			dup2(lst->next->pipe[1], 1);
			close_pipe(lst->pipe);
			close_pipe(lst->next->pipe);
		}
		waitpid(pid, &status, WUNTRACED);

	}
}

void	ft_pipe_begain(t_list *lst)
{
	pid_t	pid;
	char	*cmd[4];

	cmd[0] = lst->cmd->command;
	cmd[1] = lst->cmd->options;
	cmd[2] = lst->cmd->message;
	cmd[3] = NULL;

	pid = fork();
	if (pid == -1)
	{
		print_error(errno);
		exit(errno);
	}
	else if (pid == 0) // this is child
	{
		dup2(lst->pipe[1], 1);
		dup2(lst->pipe[1], 0);
		close_pipe(lst->pipe);
		execve(cmd[0], cmd, NULL);
	}
	else //this is parent
	{
		close(lst->pipe[1]);
		waitpid(pid, &status, WUNTRACED);
		if (lst->next != NULL)
		{
			dup2(lst->next->pipe[1], 1);
			dup2(lst->pipe[0], 0);
			close(lst->pipe[0]);
			close(lst->next->pipe[1]);
			for(;;)
            {
				int numRead;
			    char buf[20];
                numRead = read(0, buf, 20);
                if (numRead == -1)
                {
                    printf("error in read from pfd[0]");
                    exit(4);
                }
                if (numRead == 0)
                {
                    fprintf(stderr,"EOFs!\n");
                    break ;
                }
                if (write (1, buf, numRead) != numRead)
                {
                    printf("child - partial/failed write \n");
                    exit (5);
                }
            }
		}
	}
}

void	ft_pipe_end(t_list *lst)
{
	pid_t	pid;
	char	*cmd[4];
	int numRead;
	char buf[20];
	cmd[0] = lst->cmd->command;
	cmd[1] = lst->cmd->options;
	cmd[2] = lst->cmd->message;
	cmd[3] = NULL;

	pid = fork();
	if (pid == -1)
	{
		print_error(errno);
		exit(errno);
	}
	else if (pid == 0) // this is child
	{
		dup2(lst->previous->pipe[0], 0);
		dup2(lst->pipe[1], 1);
		close(lst->previous->pipe[0]);
		close(lst->previous->pipe[1]);
		close(lst->pipe[0]);
		close(lst->pipe[1]);
		// fprintf(stderr,"jjjjjjj\n");
		execve(cmd[0], cmd, NULL);
	}
	else //this is parent
	{
		close(lst->previous->pipe[0]);
		close(lst->previous->pipe[1]);
		close(lst->pipe[1]);
		waitpid(pid, &status, WUNTRACED);
		ft_putstr_fd("here",2);
		for(;;)
		{
			numRead = read(lst->pipe[0], buf, 20);
			if (numRead == -1)
			{
				fprintf(stderr,"error in read from pfd[0] end");
				exit(4);
			}
			if (numRead == 0)
			{
				// close(p_fd[0]);
				fprintf(stderr,"EOFend!\n");
				break ;
			}
			if (write (1, buf, numRead) != numRead)
			{
				printf("child - partial/failed write \n");
				exit (5);
			}
		}

	}
}

int	main(void)
{
	t_list	*cmds;
	t_list	*tmp;
	t_cmd	*cmd;
	cmd = malloc(sizeof(t_cmd));
	// int		pipe_fd[2];
	// pid_t	pid;
	char *cmd1[] = {"/bin/ls", "-la",NULL};
    char *cmd2[] = {"/bin/ls", NULL,NULL};
    char *cmd3[] = {"/usr/bin/sort", "-r" , NULL};
    char *cmd4[] = {"/usr/bin/sort", NULL, NULL};
	cmd->command = cmd1[0];
	cmd->options = cmd1[1];
	cmd->message = NULL;
	cmds = ft_lstnew("NULL","NULL",cmd);
	cmd = NULL;
	cmd = malloc(sizeof(t_cmd));
	cmd->command = cmd2[0];
	cmd->options = cmd2[1];
	cmd->message = NULL;
	ft_lstadd_back(&cmds, ft_lstnew(NULL,NULL,cmd));
	// ft_putstr_fd("here is the sigfault\n", 2);

	tmp = cmds;
	
	ft_pipe_begain(cmds);
	cmds = cmds->next;
	ft_pipe_end(cmds);
	// cmds = cmds->next;
	print_lst(cmds->previous);
	exit(45);

		// else
		// {
		// 	fd_pipe_middle(cmd, &pipe_fd[0], &pipe_fd[1]);
		// }
	// 	tmp = tmp->next;
	// }
}