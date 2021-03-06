/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:01:40 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/12 14:26:12 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_hotter(t_global *global, int x, int y)
{
	int		min;

	min = 1337;
	if (x + 1 < global->size.x && global->heat[y][x + 1] != -42
		&& global->heat[y][x + 1] != -1 && global->heat[y][x + 1] < min)
		min = global->heat[y][x + 1];
	if (x - 1 > -1 && global->heat[y][x - 1] != -42
		&& global->heat[y][x - 1] != -1 && global->heat[y][x - 1] < min)
		min = global->heat[y][x - 1];
	if (y + 1 < global->size.y && global->heat[y + 1][x] != -42
		&& global->heat[y + 1][x] != -1 && global->heat[y + 1][x] < min)
		min = global->heat[y + 1][x];
	if (y - 1 > -1 && global->heat[y - 1][x] != -42
		&& global->heat[y - 1][x] != -1 && global->heat[y - 1][x] < min)
		min = global->heat[y - 1][x];
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

void	init_players(t_global *global, char player)
{
	int		i;
	int		j;

	i = 0;
	while (i < global->size.y)
	{
		j = 0;
		while (j < global->size.x)
		{
			global->map[i][j] = ft_toupper(global->map[i][j]);
			if (global->map[i][j] != '.')
				global->heat[i][j] = (global->map[i][j] == player ? -42 : 0);
			j++;
		}
		i++;
	}
}

void	apply_heat(t_global *global)
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
	int		i;
	int		j;

	if (!(global->heat = (int**)ft_memalloc(sizeof(int*) * global->size.y)))
		return (1);
	i = 0;
	while (i < global->size.y)
	{
		j = 0;
		if (!(global->heat[i] = (int*)ft_memalloc(sizeof(int) *
															global->size.x)))
			return (1);
		while (j < global->size.x)
			global->heat[i][j++] = -42;
		i++;
	}
	init_players(global, (player == 1 ? 'O' : 'X'));
	apply_heat(global);
	return (0);
}
