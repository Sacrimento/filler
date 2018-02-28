/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:47:55 by abouvero          #+#    #+#             */
/*   Updated: 2018/02/28 18:36:58 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void 	get_size(int *tab)
{
	char	*line;
	int		i;

	i = 8;
	get_next_line(0, &line);
	tab[0] = ft_atoi(&line[8]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	tab[1] = ft_atoi(&line[i]);
}

int		get_player(void)
{
	char	*line;

	get_next_line(0, &line);
	return ((int)(line[10] - '0'));
}

int		global_init(t_global *global)
{
	int		size[2];

	get_size(size);
	if (!(global = ft_memalloc(sizeof(t_global)))
		return (1);
	if (!(global->map = ft_memalloc(sizeof(char*) * size[1])) ||
						!(global->heat = ft_memalloc(sizeof(char*) * size[1])))
		return (1);
	global->coo.x = size[0];
	global->coo.y = size[1];
	global->piece = NULL;
}

int		main(void)
{
	int			player;
	int			end;
	t_global	global;

	end = 0;
	player = get_player();
	if (global_init(&global))
		return (1);
	//while (!end)
	//	parse(&end);
	ft_printf("Player : %d\n", player);
	return (0);
}
