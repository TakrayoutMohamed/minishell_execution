/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libminishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:54:42 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/21 18:03:26 by takra            ###   ########.fr       */
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
#include "./libft/libft.h" //this header is for libft files
#endif
#ifndef LIBPARSE_H_
#include "./parsing/libparse.h" //this header is for the parsing
#endif
#ifndef LIBERROR_H_
#include "./error_handler/liberror.h" //this header is for error handling
#endif

int status;

t_list  *convert_env_to_list(char **env);
char    **convert_list_to_matrix(t_list *lst);
int		prompt(int argc, char **argv, t_list *env);
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
void	builtins(t_list *command, t_list *env);
bool	is_variable_exists(char *key, t_list *env);
char	*get_variable_value(char *key, t_list *env);
char	*get_variable_name(char *str);
int		get_variable_len(char *str);
char	*get_path_of_cmd(t_list *env, char *cmd);
bool	update_env_value(char *key, char *new_key, t_list *env);
// void	expend_data(char *str, t_list *env);
// int		echo(t_list *lst, t_list *env);
void	env_(t_list *env);
void	cd(t_list *lst, t_list *env);
void	export(t_list *lst, t_list *env);
void    pwd(void);
void	unset(t_list *env, char *variable_name);
void	update_shlvl(t_list *env);


#endif