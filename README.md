# minishell
this repo is made to start coding the execution part of the minishell


cases to handle :
there is a case in exit builtins i should handle to not making leaks


t_tokenize	*token;
	int			fd_pipe[2];
	int			st;
	pid_t		pid;
	char		*hdoc;

	buf = NULL;
	pipe(fd_pipe);
	token = (t_tokenize *)(*iterator)->content;
	pid = fork();
	if (pid == 0) // here child
	{
		close(fd_pipe[0]);
		dup2(fd_pipe[1], 1);
		close(fd_pipe[1]);
		while (1)
		{
			hdoc = readline("->");
			if (!hdoc || ft_strcmp(hdoc, token->value) == 0)
			{
				if (hdoc)
					free(hdoc);
				exit(33);
			}
			printf("%s\n", hdoc);
			free(hdoc);
		}
	}
	close(fd_pipe[1]);
	waitpid(pid, &st, 0);
	if (st == 33)
	{
		arg->infile = fd_pipe[0];
	}