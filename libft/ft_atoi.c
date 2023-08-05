/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:55:03 by mohtakra          #+#    #+#             */
/*   Updated: 2022/11/01 08:44:15 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long long	resulti;
	int					resultf;
	int					negative;
	int					i;

	resulti = 0;
	negative = 1;
	i = 0;
	while (str[i] && (is_space(str[i])))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			negative *= -1;
	while (str[i] && ft_isdigit(str[i]))
	{
		resulti = resulti * 10 + (str[i++] - '0');
		if ((resulti >= 9223372036854775807) && negative == 1)
			return (-1);
		else
			if ((resulti >= 9223372036854775807) && negative == -1)
				return (0);
	}
	resultf = resulti * negative;
	return (resultf);
}
