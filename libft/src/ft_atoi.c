/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:09:28 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/10 16:34:39 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_ispace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		is_negative;
	int		final;

	i = 0;
	final = 0;
	is_negative = 0;
	while (ft_ispace(str[i]) || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || (str[i] == '+' && ft_isdigit(str[i + 1])))
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		is_negative = 1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		final = (final * 10) + (str[i++] - 48);
	if (is_negative == 1)
		return (-final);
	return (final);
}
