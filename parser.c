/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:14:04 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/10 15:14:09 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		piece(t_global *global)
{
	char	*line;
	int		i;
	int		size[2];

	line = NULL;
	// ft_putendl_fd("PARSER", global->fd);
	ft_putendl_fd("    Entering piece", global->fd);
	get_size(size, 6, global);
	ft_putendl_fd("    After get_size()", global->fd);
	if (!(global->piece = (char**)ft_memalloc(sizeof(char*)
													* ((size[0]) + 1))))
		return (1);
	ft_putendl_fd("    After ft_memalloc()", global->fd);
	i = -1;
	// ft_putnbr_fd(size[0],global->fd);
	while (++i < size[0])
	{
	//	ft_putendl_fd("    Debut boucle gnl", global->fd);
		// ft_putnbr_fd(i,global->fd);
		// ft_putendl_fd("gnl", global->fd);
		get_next_line(0, &line);
		ft_putendl_fd(line, global->fd);
		//ft_putendl_fd("    milieu boucle gnl", global->fd);

		global->piece[i] = line;
		//ft_putendl_fd("    fin boucle gnl", global->fd);
	}
	// ft_printf("I : %d\n", i);
	global->piece[i] = 0;
	return (size[0]);
}

void 	fill_lines(t_global *global)
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

void 	trash_line(t_global *global)
{
	char	*line;
	int 	i;

	i = 0;
	line = NULL;int ret;
	ret = get_next_line(0, &line);
	//	i++;
	ft_putnbr_fd(ret, global->fd);
	ft_putendl_fd(line, global->fd);
//	ft_putstr_fd("TRASH : ", global->fd);
	// get_next_line(0, &line);
	ft_putendl_fd(line,global->fd);
	ft_strdel(&line);
}

void 	parse(int *end, t_global *global)
{
	char	*line;
	int		i;
	int		heat_size;

	if (*end != -1)
		trash_line(global);
	*end = 1;
	ft_putendl_fd("  Entering parser", global->fd);
	trash_line(global); // NUMERO DE LIGNE
	ft_putendl_fd("  After numero trash", global->fd);
	fill_lines(global);
	ft_putendl_fd("  After fill lines()", global->fd);
	// int j = 0;
	// while (global->map[j])
	// 	ft_printf("MAP %s\n", global->map[j++]);
	heat_size = piece(global);
	ft_putendl_fd("  Leaving parser", global->fd);
	// j = 0;
	// while (global->piece[j])
	// 	ft_printf("PIECE %s\n", global->piece[j++]);
}
