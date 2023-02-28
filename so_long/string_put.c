/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:04:28 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/02/27 18:26:35 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	string_put(t_prop *prop)
{
	char	*tab;
	char	*tab2;
	char	*tab3;

	mlx_string_put(prop->mlx, prop->wind, 550, 85, 0xCD5C5C, \
		"Steps Count =  ");
	tab = ft_itoa(prop->steps_count);
	mlx_string_put(prop->mlx, prop->wind, 700, 85, 0x9B59B6, tab);
	mlx_string_put(prop->mlx, prop->wind, 1150, 85, 0xCD5C5C, \
		"Pokeballs Collected =  ");
	tab2 = ft_itoa(prop->coins_collected);
	mlx_string_put(prop->mlx, prop->wind, 1380, 85, 0x9B59B6, tab2);
	mlx_string_put(prop->mlx, prop->wind, 1400, 85, 0xCD5C5C, \
		"/");
	tab3 = ft_itoa(prop->num_coll);
	mlx_string_put(prop->mlx, prop->wind, 1410, 85, 0x9B59B6, tab3);
	mlx_string_put(prop->mlx, prop->wind, 800, 85, 0xCD5C5C, \
		"   !!!POKEMON GAME !!!   ");
	free(tab);
	free(tab2);
	free(tab3);
}
