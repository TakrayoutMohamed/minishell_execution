/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:47:23 by takra             #+#    #+#             */
/*   Updated: 2023/09/13 00:52:53 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

static int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static long long	ft_atoll(char *str)
{
	unsigned long long	resulti;
	long long			resultf;
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
		if ((resulti > 9223372036854775807) && negative == 1)
			return (255);
		else
			if ((resulti - 1 > 9223372036854775807) && negative == -1)
				return (255);
	}
	resultf = resulti * negative;
	return (resultf);
}

static bool	is_ll_interval(long long intll, char *str)
{
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (intll == 255 && ft_strcmp(str, "255") != 0)
		return (false);
	if (intll >= 0)
	{
		if (intll <= INT64_MAX)
			return (true);
		else
			return (false);
	}
	else
	{
		if (intll >= INT64_MIN)
			return (true);
		else
			return (false);
	}
	return (false);
}

static bool	is_numeric_value(char *value)
{
	char	*str;

	str = value;
	if (str == NULL)
		return (false);
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

void	exit_(t_list *cmd_lst)
{
	long long		ll_int;
	unsigned char	real_exit_value;

	if (cmd_lst != NULL && ft_lstsize(cmd_lst) > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return ;
	}
	if (ft_lstsize(cmd_lst) == 1)
		exit (t_stats.status);
	cmd_lst = cmd_lst->next;
	ll_int = ft_atoll(cmd_lst->value);
	if (!is_numeric_value(cmd_lst->value) || \
	!is_ll_interval(ll_int, cmd_lst->value))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd_lst->value, 2);
		ft_putstr_fd(":  numeric argument required\n", 2);
		t_stats.status = 2;
		exit (2);
	}
	real_exit_value = (unsigned char) ll_int;
	t_stats.status = real_exit_value;
	exit (real_exit_value);
}
