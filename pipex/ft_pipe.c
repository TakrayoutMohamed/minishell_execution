
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
void	close_pipe(int pipe_fd[2])
{
	if (close(pipe_fd[0]) == -1)
	{
		print_error(errno);
		// exit(errno);
	}
	if (close(pipe_fd[1]) == -1)
	{
		print_error(errno);
		// exit(errno);
	}
}

/*this function read from a file descriptor in list struct */
void	read_from_fd(t_list *lst)
{
	char	buff[20];
	size_t	readedbuf;
	pid_t	pid;
	int		fd_in;


	pid = fork();
	if (pid == -1)
	{
		print_error(errno);
		exit(errno);
	}
	else if (pid == 0) // this is child
	{
		fd_in = open(lst->file->file_in, O_RDONLY, 0644);
		if (fd_in == -1)
		{
			print_error(errno);
			print_error(errno);
			exit(errno);
		}
		dup2(fd_in, 0);
		dup2(lst->pipe[1], 1);
		close(fd_in);
		close(lst->pipe[1]);
		while (1)
		{
			readedbuf = read(0, buff, 20);
			if (readedbuf == -1)
			{
				fprintf(stderr,"error in read from pfd[0] end");
				exit(4);
			}
			if (readedbuf == 0)
			{
				fprintf(stderr,"EOFend!\n");
				break ;
			}
			if (write(1, buff, readedbuf) != readedbuf)
			{
				printf("child - partial/failed write \n");
				exit (5);
			}
		}
		exit(0);
	}
	else //this is parent
	{
		close(lst->pipe[1]);
		waitpid(pid, &status, WUNTRACED);
	}
}

/*this function read from a fd_in's content and write it to fd_out*/
void	write_to_fd(t_list *lst)
{
	int		fd_out;
	int		numRead;
	char	buf[20];

	fd_out = open(lst->file->file_out, O_CREAT | O_WRONLY, 0644);
	if (fd_out == -1)
	{
		print_error(errno);
		exit(errno);
	}
	dup2(lst->pipe[0], 0);
	dup2(fd_out, 1);
	close_pipe(lst->pipe);
	close(fd_out);
	while (1)
	{
		numRead = read(0, buf, 20);
		if (numRead == -1)
		{
			fprintf(stderr,"error in read from pfd[0] end");
			exit(4);
		}
		if (numRead == 0)
		{
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

void	ft_pipe_middle(t_list *lst)
{
	pid_t	pid;
	char	**cmd;

	pid = fork();
	if (pid == -1)
	{
		print_error(errno);
		exit(errno);
	}
	else if (pid == 0) // this is child
	{
		cmd = convert_lst_to_matrix(lst);
		dup2(lst->previous->pipe[0], 0);
		dup2(lst->pipe[1], 1);
		close_pipe(lst->pipe);
		execve(cmd[0], cmd, NULL);
	}
	else //this is parent
	{
		close(lst->pipe[1]);
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
		dup2(lst->pipe[0], 0);
		dup2(lst->pipe[1], 1);
		close_pipe(lst->pipe);
		execve(cmd[0], cmd, NULL);
	}
	else //this is parent
	{
		close(lst->pipe[1]);
		waitpid(pid, &status, WUNTRACED);
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
		close(lst->pipe[1]);
		close(lst->previous->pipe[0]);
		execve(cmd[0], cmd, NULL);
	}
	else //this is parent
	{
		close(lst->pipe[1]);
		waitpid(pid, &status, WUNTRACED);
		if (lst->next != NULL)
		{
			dup2(lst->next->pipe[1], 1);
			close_pipe(lst->next->pipe);
		}	
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
    char *cmd2[] = {"/usr/bin/grep", "li",NULL};
    char *cmd3[] = {"/usr/bin/grep", "lib", NULL};
    char *cmd4[] = {"/usr/bin/wc", NULL, NULL};

	cmd->command = cmd1[0];
	cmd->options = cmd1[1];
	cmd->message = NULL;
	cmds = ft_lstnew("NULL","NULL",cmd);
	char file_in[] = "Makefile";
	cmds->file = malloc (sizeof(t_file));
	cmds->file->file_in = file_in;

	cmds->file->file_in = NULL;
	cmd = NULL;
	cmd = malloc(sizeof(t_cmd));
	cmd->command = cmd2[0];
	cmd->options = cmd2[1];
	cmd->message = NULL;
	// ft_putstr_fd(file_in, 2);
	ft_lstadd_back(&cmds, ft_lstnew(NULL,NULL,cmd));
	cmd = NULL;
	cmd = malloc(sizeof(t_cmd));
	cmd->command = cmd4[0];
	cmd->options = cmd4[1];
	cmd->message = NULL;
	ft_lstadd_back(&cmds, ft_lstnew(NULL,NULL,cmd));

	cmd = NULL;
	cmd = malloc(sizeof(t_cmd));
	cmd->command = cmd4[0];
	cmd->options = cmd4[1];
	cmd->message = NULL;
	ft_lstadd_back(&cmds, ft_lstnew(NULL,NULL,cmd));
	char file_out[] = "test_file.txt";
	cmds->file = malloc (sizeof(t_file));
	cmds->file->file_out = file_out;

	tmp = cmds;
	read_from_fd(cmds);
	// exit(44);
	// ft_pipe_begain(cmds);
	// cmds = cmds->next;
	// ft_pipe_middle(cmds);
	ft_putstr_fd("here is the sigfault\n", 2);
	// exit(99);
	cmds = cmds->next;
	ft_pipe_middle(cmds);
	cmds = cmds->next;
	// ft_pipe_end(cmds);
	ft_pipe_middle(cmds);
	cmds = cmds->next;
	write_to_fd(cmds);
	// cmds = cmds->next;
	// print_lst(cmds->previous);
	// exit(45);

		// else
		// {
		// 	fd_pipe_middle(cmd, &pipe_fd[0], &pipe_fd[1]);
		// }
	// 	tmp = tmp->next;
	// }
}