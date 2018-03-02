/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:01:40 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/02 17:57:16 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void 	affich(t_global *global)
{
	for (int j = 0; j < global->size.y; j++)
	{
		for (int  i = 0; i < global->size.x; i++)
			ft_printf("%3d ", global->heat[j][i]);
		ft_printf("\n");
	}
	ft_printf("\n\n");
}

int		get_hotter(t_global *global, int x, int y)
{
	int		min;

	min = 1337;
	if (x + 1 < global->size.x && global->heat[y][x + 1] != -42 && global->heat[y][x + 1] != -1 && global->heat[y][x + 1] < min)
		min = global->heat[y][x + 1];
	if (x - 1 > -1 && global->heat[y][x - 1] != -42 && global->heat[y][x - 1] != -1 && global->heat[y][x - 1] < min)
		min = global->heat[y][x - 1];
	if (y + 1 < global->size.y && global->heat[y + 1][x] != -42 && global->heat[y + 1][x] != -1 && global->heat[y + 1][x] < min)
		min = global->heat[y + 1][x];
	if (y - 1 > -1  && global->heat[y - 1][x] != -42 && global->heat[y - 1][x] != -1 && global->heat[y - 1][x] < min)
		min = global->heat[y - 1][x];
	// ft_printf("MIN : %d | COO : %d %d\n", min, y, x);
	return (min == 1337 ? -42 : min + 1);
}

int		is_heat_done(t_global *global)
{
	int		i;
	int		j;

	i = 0;
	while (i < global->size.y)
	{
		j = 0;
		while (j < global->size.x)
			if (global->heat[i][j++] == -42)
				return (0);
		i++;
	}
	return (1);
}

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

void 	apply_heat(t_global *global)
{
	int		i;
	int		j;

	while (!is_heat_done(global))
	{
		i = 0;
		while (i < global->size.y)
		{
			j = 0;
			while (j < global->size.x)
			{
				if (global->heat[i][j] == -42)
					global->heat[i][j] = get_hotter(global, j, i);
				j++;
			}
			i++;
		}
	}
}

int		heat_gen(t_global *global, int player)
{
	if (init_heat(global, player))
		return (1);
	apply_heat(global);
	affich(global);
	return (0);
}
