/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:14:04 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/15 16:47:12 by abouvero         ###   ########.fr       */
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
		return (-1);
	i = -1;
	while (++i < size[0])
	{
		if (get_next_line(0, &line) != 1)
			return (0);
		global->piece[i] = line;
	}
	global->piece[i] = 0;
	return (size[0]);
}

int		fill_lines(t_global *global)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (i < global->size.y)
	{
		if (get_next_line(0, &line) != 1)
			return (1);
		global->map[i++] = ft_strsub(line, 4, ft_strlen(line) - 4);
		ft_strdel(&line);
	}
	global->map[i] = 0;
	return (0);
}

int		trash_line(void)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) != 1)
		return (1);
	ft_strdel(&line);
	return (0);
}

int		parse(int *end, t_global *global)
{
	if (*end != -1)
		if (trash_line())
			return (1);
	*end = 1;
	if (trash_line())
		return (1);
	if (fill_lines(global))
		return (1);
	if (piece(global) == -1)
		return (1);
	return (0);
}
