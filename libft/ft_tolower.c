/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:32:34 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/16 15:44:37 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_tolower(int c)
{
	if (!ft_isalpha(c) || (c <= 'z' && c >= 'a'))
		return (c);
	// else (c <= 'Z' && c >= 'A')
	return ('a' - 'A' + c);
}
