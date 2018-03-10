/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:22:29 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/10 16:36:24 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include "./libft.h"
# define BUFF_SIZE 20

typedef struct	s_l
{
	char		*s;
	int			fd;
	struct s_l	*next;
}				t_l;

int				get_next_line(const int fd, char **line);

#endif
