/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:47:55 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/10 15:22:41 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


void 	get_size(int *tab, int sta, t_global *global)
{
	char	*line;
	int		i;

	i = sta;
	line = NULL;
	// ft_putendl_fd("KAKA1", global->fd);
	get_next_line(0, &line);
	// ft_putendl_fd("KAKA2", global->fd);
	ft_putendl_fd(line, global->fd);
	tab[0] = ft_atoi(&line[sta]);
	// ft_putendl_fd("KAKA3", global->fd);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	tab[1] = ft_atoi(&line[i]);
	ft_strdel(&line);
}

int		get_player(void)
{
	char	*line;
	int		ret;

	line = NULL;
	get_next_line(0, &line);
	ret = (int)(line[10] - '0');
	ft_strdel(&line);
	return (ret);
}

int		global_init(t_global *global)
{
	int		size[2];


	get_size(size, 8, global);
	if (!(global->map = (char**)ft_memalloc(sizeof(char*) * size[1])) ||
						!(global->heat = (int**)ft_memalloc(sizeof(int*) * (size[1] + 1))))
		return (1);
	global->size.y = size[0];
	global->size.x = size[1];
	global->piece = NULL;
	return (0);
}

int		main(void)
{
	int			player;
	int			end;
	t_global	*global;


	end = -1;
	if (!(global = (t_global*)ft_memalloc(sizeof(t_global))))
		return (1);
	global->fd = open("/dev/ttys001", O_RDWR);
	ft_putendl_fd("MAIN", global->fd);
	player = get_player();
	if (global_init(global))
		return (1);
	while (end)
	{
		ft_putendl_fd("Debut boucle", global->fd);
		parse(&end, global);
		ft_putendl_fd("Parsing done", global->fd);
		heat_gen(global, player);
		ft_putendl_fd("Heat done", global->fd);
		resolve(&end, global, (player == 1 ? 'O' : 'X'));
		ft_putendl_fd("Resolve done", global->fd);
		free_round(global);
		ft_putendl_fd("Fin boucle", global->fd);
	}
	free_global(global);
	return (0);
}
