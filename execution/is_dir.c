/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 06:29:20 by takra             #+#    #+#             */
/*   Updated: 2023/09/14 06:29:28 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

bool	is_dir(char *str)
{
	struct stat	detail;

	if (stat(str, &detail) != -1)
	{
		if (S_ISDIR(detail.st_mode))
			return (true);
	}
	return (false);
}
