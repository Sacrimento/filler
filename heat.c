/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:01:40 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/02 16:44:55 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void 	init_players(t_global *global, int player)
{
	int		i;
	int		j;

	i = 0;
	while (i < global->size.y)
	{
		j = 0;
		while (j < global->size.x)
		{
			if (global->map[i][j] != '.')
				global->heat[i][j] = (player == 1 &&
				(global->map[i][j] == 'x' || global->map[i][j] == 'X') ? 0 : -1);
			j++;
		}
		i++;
	}
}

int		init_heat(t_global *global, int player)
{
	int		i;
	int		j;

	if(!(global->heat = (int**)ft_memalloc(sizeof(int*) * global->size.y)))
		return (1);
	i = 0;
	while (i < global->size.y)
	{
		j = 0;
		if (!(global->heat[i] = (int*)ft_memalloc(sizeof(int) * global->size.x)))
			return (1);
		while (j < global->size.x)
			global->heat[i][j++] = -42;
		i++;
	}
	init_players(global, player);
	return (0);
}

int		heat_gen(t_global *global, int player)
{
	if (init_heat(global, player))
		return (1);
	for (int j = 0; j < global->size.y; j++)
	{
		for (int  i = 0; i < global->size.x; i++)
			ft_printf("%3d ", global->heat[j][i]);
		ft_printf("\n");
	}
	return (0);
}
