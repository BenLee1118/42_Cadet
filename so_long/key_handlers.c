/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:39:31 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/02/27 18:05:47 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_player_directions(int key, t_prop *prop)
{
	if (key == UP)
	{
		prop->direction = 'w';
		player_move(prop);
	}
	if (key == LEFT)
	{
		prop->direction = 'a';
		player_move(prop);
	}
	if (key == DOWN)
	{
		prop->direction = 's';
		player_move(prop);
	}
	if (key == RIGHT)
	{
		prop->direction = 'd';
		player_move(prop);
	}
}

unsigned int	xor_rand(t_prop *prop)
{
	unsigned int	seed;

	seed = prop->seed1;
	seed ^= (seed << 13);
	seed ^= (seed >> 17);
	seed ^= (seed << 5);
	prop->seed1 = seed;
	return (1 + seed % 4);
}

int	key_handlers(int key, t_prop *prop)
{
	int	num;

	if (key == ESC)
	{
		mlx_destroy_window(prop->mlx, prop->wind);
		prop->wind = 0;
		exit(SUCCESS);
	}
	else
	{
		key_player_directions(key, prop);
	}
	if (prop->num_gho)
	{
		num = (int)xor_rand(prop);
		move_ghost(prop, num);
	}
	mlx_clear_window(prop->mlx, prop->wind);
	render_images(prop);
	return (SUCCESS);
}

// int	keyrelease_handlers(t_prop *prop)
// {
// 	mlx_destroy_window(prop->mlx, prop->wind);
// 	prop->wind = NULL;
// 	return (0);
// }
