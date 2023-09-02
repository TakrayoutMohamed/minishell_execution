/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:48:45 by takra             #+#    #+#             */
/*   Updated: 2023/09/02 18:48:46 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

/*swap the data of the entered nodes lsta and lstb*/
void	ft_lstswap(t_list *lsta, t_list *lstb)
{
	char	*tmpkey;
	char	*tmpvalue;

	if (lsta != NULL && lstb != NULL)
	{
		tmpkey = lsta->key;
		tmpvalue = lsta->value;
		lsta->key = lstb->key;
		lsta->value = lstb->value;
		lstb->key = tmpkey;
		lstb->value = tmpvalue;
	}
}
