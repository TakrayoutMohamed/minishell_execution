/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:48:24 by takra             #+#    #+#             */
/*   Updated: 2023/09/06 18:09:58 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

/*print the current directory to the stdout*/
void	pwd(void)
{
	char	pwd[MAXPATHLEN];

	getcwd(pwd, MAXPATHLEN);
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd("\n", 1);
	t_stats.status = 0;
}
