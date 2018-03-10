/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:21:29 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/10 15:41:52 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"

// static int			create_line(char **line, t_fd_list *current)
// {
// 	int		i;
// 	char	*tmp;
//
// 	i = 0;
// 	if (*current->str)
// 	{
// 		while (current->str[i] != '\n' && current->str[i])
// 			i++;
// 		*line = ft_strsub(current->str, 0, i);
// 		tmp = ft_strsub(current->str, i + 1, ft_strlen(current->str) - i);
// 		ft_memdel((void**)&current->str);
// 		current->str = tmp;
// 		return (1);
// 	}
// 	return (0);
// }
//
// static char			*ft_strjoin_custom(char *s1, char *s2)
// {
// 	int		i;
// 	int		j;
// 	char	*new_s;
//
// 	i = 0;
// 	j = 0;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	if (!(new_s = (char*)malloc(sizeof(char) *
// 					(ft_strlen(s1) + ft_strlen(s2) + 1))))
// 		return (NULL);
// 	while (s1[i])
// 		new_s[j++] = s1[i++];
// 	i = 0;
// 	while (s2[i])
// 		new_s[j++] = s2[i++];
// 	free(s1);
// 	new_s[j] = '\0';
// 	return (new_s);
// }
//
// static	int			ft_read(t_fd_list *current, int fd)
// {
// 	int		ret;
// 	char	*buff;
//
// 	buff = ft_strnew(BUFF_SIZE);
// 	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && *buff)
// 	{
// 		buff[ret] = '\0';
// 		current->str = ft_strjoin_custom(current->str, buff);
// 		if (ft_memchr(current->str, '\n', ft_strlen(current->str)))
// 			break ;
// 	}
// 	free(buff);
// 	if (ret < 0)
// 		return (-1);
// 	return (0);
// }
//
// static t_fd_list	*get_line_by_fd(t_fd_list **list, int fd)
// {
// 	t_fd_list	*current;
// 	t_fd_list	*new;
//
// 	current = *list;
// 	if (current->fd == fd)
// 		return (current);
// 	while (current->next)
// 	{
// 		if (current->next->fd == fd)
// 			return (current->next);
// 		current = current->next;
// 	}
// 	if (!(new = (t_fd_list*)malloc(sizeof(t_fd_list))))
// 		return (NULL);
// 	new->fd = fd;
// 	new->str = ft_strnew(0);
// 	new->next = NULL;
// 	if (current)
// 		current->next = new;
// 	return (new);
// }
//
// int					get_next_line(const int fd, char **line)
// {
// 	static t_fd_list	*list;
// 	t_fd_list			*current;
//
// 	if (!list)
// 	{
// 		if (!(list = (t_fd_list*)malloc(sizeof(t_fd_list))))
// 			return (-1);
// 		list->fd = -1337;
// 		list->next = NULL;
// 	}
// 	if (!(current = get_line_by_fd(&list, fd)) || fd < 0 || !line ||
// 							BUFF_SIZE <= 0 || ft_read(current, fd) == -1)
// 		return (-1);
// 	if (create_line(line, current))
// 		return (1);
// 	free(current->str);
// 	current->str = ft_strnew(0);
// 	return (0);
// }

// static char	*ft_strjoin_custom(char *s1, char *s2)
// {
// 	char	*newstr;
// 	size_t	alloc_length;
//
// 	newstr = NULL;
// 	if (!s1 && s2)
// 		return (s2);
// 	if (s1 && s2)
// 	{
// 		alloc_length = (size_t)(ft_strlen(s1) + ft_strlen(s2) + 1);
// 		if (!(newstr = ft_strnew(alloc_length)))
// 			return (NULL);
// 		ft_strcat(newstr, s1);
// 		ft_strcat(newstr, s2);
// 		free(s1);
// 		free(s2);
// 	}
// 	return (newstr);
// }
//
// static char	*copy_a_line(char *str)
// {
// 	char			*copy;
// 	unsigned int	count;
//
// 	count = 0;
// 	if (!str)
// 		return (NULL);
// 	while (str[count] && str[count] != '\n')
// 		count++;
// 	if (!(copy = ft_strnew(count)))
// 		return (NULL);
// 	ft_strncpy(copy, str, count);
// 	return (copy);
// }
//
// static char	*after_n(char *str)
// {
// 	char *after;
//
// 	if (str && str[0])
// 	{
// 		after = ft_strchr(str, '\n');
// 		if (after && after[0])
// 		{
// 			after++;
// 			str = ft_strcpy(str, after);
// 		}
// 		else
// 			ft_memset(str, '\0', BUFF_SIZE);
// 	}
// 	return (str);
// }
//
// static int	fill_line(char **line, char *temp, const int fd)
// {
// 	long cursor;
//
// 	cursor = 0;
// 	if (temp[0])
// 	{
// 		*line = ft_strjoin_custom(*line, copy_a_line(temp));
// 		if (ft_strchr(temp, '\n'))
// 			return (1);
// 	}
// 	while ((cursor = read(fd, temp, BUFF_SIZE)))
// 	{
// 		if (cursor < 1)
// 			return (cursor);
// 		temp[cursor] = '\0';
// 		*line = ft_strjoin_custom(*line, copy_a_line(temp));
// 		if (ft_strchr(temp, '\n'))
// 			return (1);
// 		else
// 			temp[0] = '\0';
// 	}
// 	return (0);
// }
//
// int			get_next_line(const int fd, char **line)
// {
// 	static t_fd		temp;
// 	char			*local_line;
// 	long			cursor;
//
// 	local_line = NULL;
// 	if ((!temp.str && !(!(temp.str = ft_strnew(BUFF_SIZE)))
// 		&& !(temp.fd = -1)) || BUFF_SIZE < 1 || fd < 0 || !line)
// 		return (-1);
// 	if (temp.fd != fd)
// 		temp.str[0] = '\0';
// 	temp.fd = fd;
// 	cursor = fill_line(&local_line, temp.str, fd);
// 	if (cursor == -1)
// 		return (-1);
// 	if (local_line && cursor >= 0)
// 	{
// 		temp.str = after_n(temp.str);
// 		*line = local_line;
// 		if (temp.str[0] == '\0')
// 			ft_memdel((void**)&temp.str);
// 		return (1);
// 	}
// 	if (cursor == 0 && temp.str)
// 		ft_memdel((void**)&temp.str);
// 	return (cursor);
// }

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
