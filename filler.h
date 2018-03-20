/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:46:30 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/20 11:42:29 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/includes/libft.h"

typedef struct	s_coo
{
	int		x;
	int		y;
}				t_coo;

typedef struct	s_pos
{
	int				heat;
	t_coo			coo;
	struct s_pos	*next;
}				t_pos;

typedef struct	s_global
{
	char	**map;
	int		**heat;
	char	**piece;
	t_coo	size;
}				t_global;

int				parse(int *end, t_global *global);
int				get_size(int *tab, int sta);
void			free_round(t_global *global);
int				heat_gen(t_global *global, int player);
void			resolve(int *end, t_global *global, char player);
void			free_global(t_global *global);
void			free_pos(t_pos *pos);

#endif
