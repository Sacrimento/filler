/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:46:30 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/02 15:50:24 by abouvero         ###   ########.fr       */
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

typedef struct	s_global
{
	char	**map;
	int		**heat;
	char	**piece;
	t_coo	size;
}				t_global;

void 	parse(t_global *global);
void 	get_size(int *tab, int sta);
void 	free_round(t_global *global, int heat_size);

#endif
