/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 01:11:20 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/19 15:40:57 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_neededmem(int nbr, int	*negative)
{
	int	neededmem;

	neededmem = 0;
	if (nbr < 0)
		*negative = 1;
	if (nbr <= 0)
	{
		neededmem++;
		nbr *= -1;
	}
	while (nbr)
	{
		nbr /= 10;
		neededmem++;
	}
	return (neededmem);
}

static char	*get_result_of_itoa(long nbr, int neededmem, int is_negative)
{
	char	*str;

	if (nbr < 0)
		nbr *= -1;
	str = (char *)malloc(sizeof(char) * neededmem + 1);
	if (!str)
		return (NULL);
	str[neededmem] = '\0';
	while (neededmem > 0)
	{
		str[--neededmem] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int nbr)
{
	int		is_negative;
	int		neededmem;
	char	*str;

	is_negative = 0;
	neededmem = ft_neededmem(nbr, &is_negative);
	str = get_result_of_itoa(nbr, neededmem, is_negative);
	if (!str)
		return (NULL);
	return (str);
}
