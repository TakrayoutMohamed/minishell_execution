/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libminishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:54:42 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/30 13:20:00 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMINISHELL_H_
#define LIBMINISHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>

#ifndef LIBFT_H
#include "./libft/libft.h"
#endif
#ifndef LIBERROR_H_
#include "./error_handler/liberror.h"
#endif

int status;

t_list	*convert_env_to_list(char **env);
t_list	*convert_matrix_to_list(char **matrix);
char	**convert_list_to_matrix(t_list *lst);
void	execution(t_list *command, t_list *env, int position);
void	execute_list(t_list *lst, t_list *env);
int		is_builtins(t_list *lst);
bool	is_echo(char *command);
bool	is_cd(char *command);
bool	is_pwd(char *command);
bool	is_export(char *command);
bool	is_unset(char *command);
bool	is_env(char *command);
bool	is_exit(char *command);
int	    pipe_builtins(t_list *lst, t_list *env);
void	builtins_no_output(t_list *lst ,t_list *env);
bool	is_variable_exists(char *key, t_list *env);
char	*get_variable_value(char *key, t_list *env);
char	*get_variable_name(char *str);
int		get_variable_len(char *str);
char	*get_path_of_cmd(t_list *env, char *cmd);
bool	update_env_value(char *key, char *new_key, t_list *env);
int     echo(t_list *cmd_lst);
void	env_(t_list *env);
void	cd(t_list *cmd_lst, t_list *env);
void	export(t_list *cmd_lst, t_list *env);
void	pwd(void);
void	unset(t_list *env, char *variable_name);
void	exit_(t_list *cmd_lst);
void	update_shlvl(t_list *env);
int		pipe_end(t_list *lst, char **argv, char **envp);
int		pipe_middle(t_list *lst, char **argv, char **envp);
int		pipe_beginning(t_list *lst, char **argv, char **envp);
void	close_pipe(int pipe_fd[2]);
int     read_from_fd(int fd);

#endif