/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:35:45 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/15 15:56:45 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_colors(char *line, int *ret)
{
	int i;

	i = 0;
	while (line[4 + i])
	{
		if (line[4 + i] == '.')
			ft_printf("\e[100m  \x1b[0m");
		else if (line[4 + i] == 'O')
			ft_printf("\x1b[48;5;126m  \x1b[0m");
		else if (line[4 + i] == 'o')
		{
			ft_printf("\x1b[48;5;135m  \x1b[0m");
			*ret = (*ret == 0 ? 1 : *ret);
		}
		else if (line[4 + i] == 'X')
			ft_printf("\x1b[48;5;166m  \x1b[0m");
		else if (line[4 + i] == 'x')
		{
			ft_printf("\x1b[48;5;172m  \x1b[0m");
			*ret = (*ret == 0 ? 2 : *ret);
		}
		i++;
	}
}

void	print_grid(int *score_p1, int *score_p2)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Piece") || ft_strstr(line, "fin"))
		{
			if (ret == 1)
				*score_p1 += 1;
			else if (ret == 2)
				*score_p2 += 1;
			ft_printf("\n\n\x1b[38;5;126mPlayer 1 [%d]\x1b[0m\n\x1b[38;5;166m"
							"Player 2 [%d]\x1b[0m\n\n", *score_p1, *score_p2);
			ft_strdel(&line);
			return ;
		}
		print_colors(line, &ret);
		ft_printf("\n");
		ft_strdel(&line);
	}
}

void	print_hundred_lines(void)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		write(1, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", 25);
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	*line;
	int		score_p1;
	int		score_p2;

	line = NULL;
	score_p1 = 0;
	score_p2 = 0;
	while (get_next_line(0, &line))
	{
		if (ft_isdigit(*line))
		{
			print_hundred_lines();
			print_grid(&score_p1, &score_p2);
		}
		usleep(argc == 2 && ft_atoi(argv[1]) > 0 ? ft_atoi(argv[1]) : 50000);
		ft_strdel(&line);
	}
	return (0);
}
