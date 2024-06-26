/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:24:22 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/07 17:12:55 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_size;

	if (!src)
		return (0);
	src_size = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (*src && i < dstsize - 1)
		{
			*dst = *src;
			dst++;
			src++;
			i++;
		}
		*dst = '\0';
	}
	return (src_size);
}
