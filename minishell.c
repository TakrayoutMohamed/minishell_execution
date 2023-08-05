/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:37:37 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/05 22:40:06 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminishell.h"

void	print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
		printf("**%s = %s** \n",lst->key, lst->value);
		lst = lst->next;
	}
	lst = tmp;
}

int main(int argc, char **argv, char **env)
{
    t_list  *lst;

    lst = convert_env_to_list(env);
    // print_lst(lst);
    // exit(44);
    prompt(argc, argv, lst);
    return (0);
}