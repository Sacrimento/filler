/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:21:29 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/10 16:34:31 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"

int		ft_strcatspe(char **b, char *up)
{
	char	*st;
	int		i;
	int		j;

	if (!b || !*b || !up)
		return (-1);
	if (!(st = (char*)malloc(ft_strlen(*b) + ft_strlen(up) + 1)))
		return (-1);
	i = 0;
	while ((*b)[i])
	{
		st[i] = (*b)[i];
		i++;
	}
	j = 0;
	while (up[j])
		st[i++] = up[j++];
	st[i] = '\0';
	free(*b);
	*b = st;
	return (1);
}

int		ft_re(int fd, t_l *e, char **line, int s)
{
	char	buff[BUFF_SIZE + 1];
	int		f[2];

	f[1] = -1;
	while ((f[0] = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[f[0]] = '\0';
		f[1] = 0;
		while (f[1] < f[0] && buff[f[1]] != '\n')
			f[1]++;
		if (f[0] != f[1])
		{
			buff[f[1]] = '\0';
			if ((ft_strcatspe(line, buff) == -1) || !(e->s = ft_strdup(
					&(buff[f[1] + 1]))))
				return (-1);
			return (1);
		}
		ft_strcatspe(line, buff);
	}
	if (f[0] < 0)
		return (-1);
	return ((s == 1 || f[1] >= 0) ? 1 : 0);
}

int		ft_comp(int fd, t_l *e, char **line)
{
	char	*str;
	int		d[2];

	d[0] = 0;
	if (e->s)
	{
		d[1] = ft_strlen(e->s);
		while (d[0] < d[1] && (e->s)[d[0]] != '\n')
			d[0]++;
		e->s[d[0]] = '\0';
		if (!(*line = ft_strdup(e->s)))
			return (-1);
		if (d[1] != d[0])
		{
			str = ft_strdup(&(e->s[d[0] + 1]));
			ft_strdel(&(e->s));
			e->s = str;
			return (1);
		}
		ft_strdel(&(e->s));
		return (ft_re(fd, e, line, d[1] > 0));
	}
	else if (!(e->s) && !(*line = (char*)ft_memalloc(1)))
		return (-1);
	return (ft_re(fd, e, line, 0));
}

t_l		*ft_getright(int fd, t_l *begin)
{
	while (begin && begin->next && begin->fd != fd)
		begin = begin->next;
	return (begin);
}

int		get_next_line(int fd, char **line)
{
	static t_l	*e;
	t_l			*tmp;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (!e)
	{
		if (!(e = (t_l*)malloc(sizeof(t_l))))
			return (-1);
		e->s = NULL;
		e->next = NULL;
		e->fd = fd;
	}
	tmp = ft_getright(fd, e);
	if (tmp && tmp->fd != fd)
	{
		if (!(tmp->next = (t_l*)malloc(sizeof(t_l))))
			return (-1);
		tmp = tmp->next;
		tmp->next = NULL;
		tmp->s = NULL;
		tmp->fd = fd;
	}
	return (ft_comp(fd, tmp, line));
}
