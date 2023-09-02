/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:43:00 by mohtakra          #+#    #+#             */
/*   Updated: 2023/09/02 17:31:59 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

/*return true if the first node's value is a builtins programe*/
int	is_builtins(t_list *lst)
{
	if (is_echo(lst->value))
		return (1);
	if (is_cd(lst->value))
		return (1);
	if (is_pwd(lst->value))
		return (1);
	if (is_export(lst->value))
		return (1);
	if (is_unset(lst->value))
		return (1);
	if (is_env(lst->value))
		return (1);
	if (is_exit(lst->value))
		return (1);
	return (0);
}
