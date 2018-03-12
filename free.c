/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:29:06 by abouvero          #+#    #+#             */
/*   Updated: 2018/03/12 15:21:52 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_global(t_global *global)
{
	ft_memdel((void**)&global->map);
	ft_memdel((void**)&global);
}

void	free_round(t_global *global)
{
	int		i;

	i = 0;
	while (global->map[i])
	{
		ft_memdel((void**)&global->map[i]);
		ft_memdel((void**)&global->heat[i++]);
	}
	ft_memdel((void**)&global->heat);
	i = 0;
	while (global->piece[i])
		ft_memdel((void**)&global->piece[i++]);
	ft_memdel((void**)&global->piece);
}
