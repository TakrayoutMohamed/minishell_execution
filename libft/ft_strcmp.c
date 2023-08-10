/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:23:55 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/08 16:20:22 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*((unsigned char *)s1) - (*(unsigned char *)s2));
		s1++;
		s2++;
	}
	if (!*s1 || !*s2)
		return (ft_strlen(s1) - ft_strlen(s2));
	return (0);
}
