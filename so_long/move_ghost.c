/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ghost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:20:36 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/02/27 13:49:35 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	scangho_next_pcs(t_prop *prop, int direction, char pcs)
{
	if ((direction == 1
			&& prop->map[prop->ghost_y][prop->ghost_x + 1] == pcs)
			|| (direction == 2
			&& prop->map[prop->ghost_y][prop->ghost_x - 1] == pcs)
			|| (direction == 3
			&& prop->map[prop->ghost_y + 1][prop->ghost_x] == pcs)
			|| (direction == 4
			&& prop->map[prop->ghost_y - 1][prop->ghost_x] == pcs))
		return (SUCCESS);
	else
		return (FAILURE);
}

void	game_lost(t_prop *prop)
{
	error_params("  !!!!!! GAME OVER LOSERRRR !!!!!!  ", NULL);
	mlx_destroy_window(prop->mlx, prop->wind);
	prop->wind = NULL;
	exit(SUCCESS);
}

void	move_ghost(t_prop *prop, int direction)
{
	if (scangho_next_pcs(prop, direction, '1') == SUCCESS
		|| scangho_next_pcs(prop, direction, 'E') == SUCCESS
		|| scangho_next_pcs(prop, direction, 'C') == SUCCESS)
		return ;
	if (scangho_next_pcs(prop, direction, 'P') == SUCCESS
		|| prop->map[prop->ghost_y][prop->ghost_x] ==
		prop->map[prop->player_y][prop->player_x])
		game_lost(prop);
	prop->map[prop->ghost_y][prop->ghost_x] = '0';
	if (direction == 1)
		prop->ghost_x += 1;
	else if (direction == 2)
		prop->ghost_x -= 1;
	else if (direction == 3)
		prop->ghost_y += 1;
	else if (direction == 4)
		prop->ghost_y -= 1;
	prop->map[prop->ghost_y][prop->ghost_x] = 'G';
}
