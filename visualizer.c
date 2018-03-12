/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:35:45 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/12 18:33:06 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

// void 	print_new_line

void 	print_grid(int fd)
{
	char	*line;
	int 	i;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Piece"))
		{
			ft_strdel(&line);
			return ;
		}
		i = 0;
		while (line[4 + i])
		{
			// ft_putendl_fd("BOUCLE",fd);
			if (line[4 + i] == '.')
				ft_printf("\e[100m \x1b[0m");
			else if (line[4 + i] == 'O' || line[4 + i] == 'o')
				ft_printf("\x1b[48;5;126m \x1b[0m");
			else if (line[4 + i] == 'X' || line[4 + i] == 'x')
				ft_printf("\x1b[48;5;166m \x1b[0m");
			i++;
		}
		ft_printf("\n");
		ft_strdel(&line);
	}
}

void 	print_hundred_lines(void)
{
	int 	i;

	i = 0;
	while (i < 100)
	{
		write(1, "\n", 1);
		i++;
	}
}

int 	main(void)
{
	char	*line;

	line = NULL;
	int fd = open("/dev/ttys001", O_RDWR);
	//ft_printf("\e[100m "); // LIGHT GREY
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "=="))
		{
			//get_score();
			break;
		}
		// if (ft_strstr(line, "Plateau"))
		// 	print_hundred_lines();
		if (ft_strstr(line, " "))
		{
			print_hundred_lines();
			print_grid(fd);
		}
		usleep(50000);
		ft_strdel(&line);
	}
	return (0);
}
