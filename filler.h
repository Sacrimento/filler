/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:46:30 by abouvero          #+#    #+#             */
/*   Updated: 2018/02/28 18:35:12 by abouvero         ###   ########.fr       */
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
	char	**heat;
	char	*piece;
	t_coo	coo;
}				t_global;

#endif
