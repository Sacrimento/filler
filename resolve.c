/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:06:31 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/02 19:32:03 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void 	free_pos(t_pos *pos)
{
	if (pos->next)
		free_pos(pos->next);
	ft_memdel((void**)pos);
}

// void 	pos_new(t_pos *pos, int x, int y, int score)
// {
// 	t_pos		*new;
// 	t_pos		*beg;
//
// 	beg = pos;
// 	if (!(new = (t_pos*)malloc(sizeof(t_pos))))
// 		return ;
// 	new->heat = score;
// 	new->coo.x = i;
// 	new->coo.y = j;
// 	new->next = NULL;
// 	if (pos == NULL)
// 		return (new);
// 	while (pos->next)
// 		pos = pos->next;
// 	pos->next = new;
// 	return (beg);
// }

// int   can_place(t_global *global, int x, int y, char player)
// {
//   int   score;
//   int   same;
//   int   i;
//   int   j;
//
//   j = 0;
//   same = 0;
//   score = 0;
//   while (global->piece[j] != 0)
//   {
//     while (global->piece[j][i])
//     {
//       if (global->piece[j][i] == '*' && (j + y > global->size.y || i + x > global->size.x))
//         return (-1);
//       else if (global->piece[j][i] == '*' && global->map[y + j][x + i] == player)
//         same++;
//       else if (global->piece[j][i] == '*')
//         score += global->heat[j + y][i + x];
//       i++;
//     }
//     j++;
//   }
//   return (same == 1 ? score : -1);
// }

void 	placer(t_global *global, t_pos *pos, char player)
{
	int 	i;
	int 	j;
	int 	score;

	i = 0;
	while (i < global->size.y)
	{
		j = 0;
		while (j < global->size.x)
		{
			if ((score = can_place(global, j, i, player)) != -1)
				pos = pos_new(pos, j, i, score);
			j++;
		}
		i++;
	}
}

void 	resolve(int *end, t_global *global, char player)
{
	t_pos		*pos;
	t_coo		best_coo;
	int 		heat;

	best_coo.x = 0;
	best_coo.y = 0;
	heat = 1337;
	pos = NULL;
	// if (!(pos = (t_pos*)ft_memalloc(sizeof(t_pos))))
	// 	return ;
	placer(global, pos, player);
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
	if (best_coo.x == 0 && best_coo.y == 0)
		*end = 0;
	//ft_printf("%d %d\n", best_coo.x, best_coo.y);
	//free_pos();
 }
