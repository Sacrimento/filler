/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:06:31 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/20 12:35:15 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			get_negative(t_global *g, int coo)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (g->piece[0][i])
		i++;
	while (g->piece[j])
		j++;
	return (coo == 1 ? -i + 1 : -j + 1);
}

t_pos		*pos_new(t_pos *pos, int x, int y, int score)
{
	t_pos		*new;
	t_pos		*beg;

	beg = pos;
	if (!(new = (t_pos*)malloc(sizeof(t_pos))))
		return (NULL);
	new->heat = score;
	new->coo.x = x;
	new->coo.y = y;
	new->next = NULL;
	if (pos == NULL)
		return (new);
	while (pos->next)
		pos = pos->next;
	pos->next = new;
	return (beg);
}

int			can_place(t_global *g, int x, int y, char player)
{
	int		score;
	int		same;
	t_coo	coo;

	coo.y = -1;
	same = 0;
	score = 0;
	while (g->piece[++coo.y] != 0 && (coo.x = -1))
		while (g->piece[coo.y][++coo.x])
			if (g->piece[coo.y][coo.x] == '*' && ((coo.y + y >=
g->size.y || coo.x + x >= g->size.x) || coo.y + y < 0 || x + coo.x < 0))
				return (-1);
			else if (coo.x + x >= 0 && y + coo.y >= 0 && (coo.y + y <
				g->size.y && coo.x + x < g->size.x)
	&& g->piece[coo.y][coo.x] == '*' && (g->map[coo.y + y][coo.x + x]
		!= player && g->map[coo.y + y][coo.x + x] != ft_tolower(player)
							&& g->map[coo.y + y][coo.x + x] != '.'))
				return (-1);
			else if (g->piece[coo.y][coo.x] == '*' &&
						(g->map[y + coo.y][x + coo.x] == player
					|| g->map[y + coo.y][x + coo.x] == ft_tolower(player)))
				same++;
			else if (g->piece[coo.y][coo.x] == '*')
				score += g->heat[coo.y + y][coo.x + x];
	return (same == 1 ? score : -1);
}

t_pos		*placer(t_global *g, t_pos *pos, char player)
{
	int		i;
	int		j;
	int		score;

	i = get_negative(g, 1);
	while (i < g->size.y)
	{
		j = get_negative(g, 2);
		while (j < g->size.x)
		{
			if ((score = can_place(g, j, i, player)) != -1)
				if (!(pos = pos_new(pos, j, i, score)))
					return (NULL);
			j++;
		}
		i++;
	}
	return (pos);
}

void		resolve(int *end, t_global *g, char player)
{
	t_pos		*pos;
	t_pos		*del;
	t_coo		best_coo;
	int			heat;

	best_coo.x = -1;
	best_coo.y = -1;
	heat = 1337;
	pos = NULL;
	del = placer(g, pos, player);
	pos = del;
	while (pos)
	{
		if (pos->heat < heat)
		{
			heat = pos->heat;
			best_coo.x = pos->coo.x;
			best_coo.y = pos->coo.y;
		}
		pos = pos->next;
	}
	if (best_coo.x == -1 && best_coo.y == -1)
		*end = 0;
	ft_printf("%d %d\n", best_coo.y, best_coo.x);
	free_pos(del);
}
