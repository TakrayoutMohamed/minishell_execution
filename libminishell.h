/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libminishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:54:42 by mohtakra          #+#    #+#             */
/*   Updated: 2023/07/30 19:52:06 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMINISHELL_H_
#define LIBMINISHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./libtree.h" // this header is for tree struct
#include "./parsing/libparse.h" //this header is for the parsing

int	prompt(int argc, char *argv, char *env);

#endif