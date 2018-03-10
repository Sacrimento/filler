/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:09:28 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/07 17:59:34 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// static int	check_special_char(const char *str)
// {
// 	int		i;
//
// 	i = 0;
// 	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
// 			|| str[i] == '\t' || str[i] == '\f' || str[i] == '\r')
// 		i++;
// 	return (i);
// }
//
// static long	convert_to_int(const char *str, int i)
// {
// 	long	nbr;
//
// 	nbr = 0;
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		nbr = (nbr * 10) + (str[i] - '0');
// 		i++;
// 	}
// 	return (nbr);
// }
//
// int			ft_atoi(const char *str)
// {
// 	int		i;
// 	int		negative;
// 	long	nbr;
//
// 	negative = 0;
// 	i = check_special_char(str);
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			negative = 1;
// 		i++;
// 	}
// 	nbr = convert_to_int(str, i);
// 	if (nbr < -2147483648)
// 		return (0);
// 	if (!negative)
// 		return (nbr);
// 	return (-nbr);
// }
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
