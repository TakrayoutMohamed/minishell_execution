/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:42:26 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/18 18:42:06 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void    del(char *str)
{
    if (str)
        free(str);
}
