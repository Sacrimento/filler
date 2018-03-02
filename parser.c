/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:14:04 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/02 17:49:54 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		piece(t_global *global)
{
	char	*line;
	int		i;
	int		size[2];

	get_size(size, 6);
	if (!(global->piece = (char**)ft_memalloc(sizeof(char*)
													* (size[0] + 1))))
		return (1);
	i = 0;
	while (i < size[0])
	{
		get_next_line(0, &line);
		global->piece[i++] = line;
	}
	global->piece[i] = 0;
	return (size[0]);
}

void 	fill_lines(t_global *global)
{
	int		i;
	char	*line;

	i = 0;
	while (i < global->size.y)
	{
		get_next_line(0, &line);
		global->map[i++] = ft_strsub(line, 4, ft_strlen(line) - 4);
		ft_strdel(&line);
	}
	global->map[i] = 0;
}

void 	trash_line(void)
{
	char	*line;

	get_next_line(0, &line);
	ft_strdel(&line);
}

void 	parse(int *end, t_global *global)
{
	char	*line;
	int		i;
	int		heat_size;

	if (*end != -1)
		trash_line();
	*end = 1;
	trash_line();
	fill_lines(global);
	int j = 0;
	while (global->map[j])
		ft_printf("MAP %s\n", global->map[j++]);
	heat_size = piece(global);
	j = 0;
	ft_printf("TEST\n");
	while (global->piece[j])
		ft_printf("PIECE %s\n", global->piece[j++]);
}
