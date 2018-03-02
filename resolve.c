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

void 	placer(t_global *global, t_pos *pos)
{
	int 	i;
	int 	j;

	i = 0;
	while (i < global->size.y)
	{
		j = 0;
		while (j < global->size.x)
		{
			if (can_place(global, j, i))
				pos_new(pos, j, i);
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
	if (!(pos = (t_pos*)ft_memalloc(sizeof(t_pos))))
		return ;
	placer(global, pos);
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
	//free_poss();
 }
