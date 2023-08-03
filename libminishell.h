/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libminishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:54:42 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/04 00:12:32 by mohtakra         ###   ########.fr       */
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

#ifndef LIBTREE_H_
#include "./tree/libtree.h" // this header is for tree struct
#endif
#ifndef LIBPARSE_H_
#include "./parsing/libparse.h" //this header is for the parsing
#endif
#ifndef LIBERROR_H_
#include "./error_handler/liberror.h" //this header is for the parsing
#endif


int		prompt(int argc, char **argv, char **env);
void	execution(t_tree *command, char **env);
void	execute_tree(t_tree *tree, char **env);
int		is_builtins(t_tree *tree);
bool	is_echo(char *command);
bool	is_cd(char *command);
bool	is_pwd(char *command);
bool	is_export(char *command);
bool	is_unset(char *command);
bool	is_env(char *command);
bool	is_exit(char *command);
void	builtins(t_tree *command);
int		echo(t_tree *tree);


#endif