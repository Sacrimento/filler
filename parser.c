/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:14:04 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/10 17:39:31 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		piece(t_global *global)
{
	char	*line;
	int		i;
	int		size[2];

	line = NULL;
	get_size(size, 6);
	if (!(global->piece = (char**)ft_memalloc(sizeof(char*)
													* ((size[0]) + 1))))
		return (1);
	i = -1;
	while (++i < size[0])
	{
		get_next_line(0, &line);
		global->piece[i] = line;
	}
	global->piece[i] = 0;
	return (size[0]);
}

void	fill_lines(t_global *global)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (i < global->size.y)
	{
		get_next_line(0, &line);
		global->map[i++] = ft_strsub(line, 4, ft_strlen(line) - 4);
		ft_strdel(&line);
	}
	global->map[i] = 0;
}

void	trash_line(void)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	ft_strdel(&line);
}

void	parse(int *end, t_global *global)
{
	if (*end != -1)
		trash_line();
	*end = 1;
	trash_line();
	fill_lines(global);
	piece(global);
}
