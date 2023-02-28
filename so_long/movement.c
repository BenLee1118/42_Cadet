/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:38:39 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/02/27 18:24:19 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	scan_next_pcs(t_prop *prop, char pcs)
{
	if ((prop->direction == 'd' && \
		prop->map[prop->player_y][prop->player_x + 1] == pcs)
		|| (prop->direction == 'a' && \
		prop->map[prop->player_y][prop->player_x - 1] == pcs)
		|| (prop->direction == 's' && \
		prop->map[prop->player_y + 1][prop->player_x] == pcs)
		|| (prop->direction == 'w' && \
		prop->map[prop->player_y - 1][prop->player_x] == pcs))
	{
		if (pcs == 'C')
			prop->coins_collected++;
		return (SUCCESS);
	}
	else
		return (FAILURE);
}

/* // void	scan_next_coin(t_prop *prop, char coin)
// {
// 	if ((prop->direction == 'd' && \
// 		prop->map[prop->player_y][prop->player_x + 1] == coin)
// 		|| (prop->direction == 'a' && \
// 		prop->map[prop->player_y][prop->player_x - 1] == coin)
// 		|| (prop->direction == 's' && \
// 		prop->map[prop->player_y + 1][prop->player_x] == coin)
// 		|| (prop->direction == 'w' && \
// 		prop->map[prop->player_y - 1][prop->player_x] == coin))
// 			prop->coins_collected++;
// } */

void	counter(t_prop *prop)
{
	ft_putstr("Steps Count =	");
	ft_putstr(ft_itoa(prop->steps_count));
	ft_putstr("\t Pokeball Collected =	");
	ft_putstr(ft_itoa(prop->coins_collected));
	ft_putstr("/");
	ft_putstr(ft_itoa(prop->num_coll));
	ft_putstr("\n");
}

void	victory(t_prop *prop)
{
	ft_putstr("!!! CONGRATULATIONS, YOU WON !!! \n\n");
	mlx_destroy_window(prop->mlx, prop->wind);
	prop->wind = 0;
	exit (SUCCESS);
}

void	player_move(t_prop	*prop)
{
	if (scan_next_pcs(prop, '1') == SUCCESS
		|| (prop->exitable == 0
			&& scan_next_pcs(prop, 'E') == SUCCESS))
		return ;
	prop->steps_count++;
	scan_next_pcs(prop, 'C');
	if (prop->coins_collected == prop->num_coll)
		prop->exitable = 1;
	if (prop->num_gho)
		if (scan_next_pcs(prop, 'G') == SUCCESS
			|| prop->map[prop->ghost_y][prop->ghost_x]
				== prop->map[prop->player_y][prop->player_x])
			game_lost(prop);
	prop->map[prop->player_y][prop->player_x] = '0';
	if (prop->direction == 'w')
		prop->player_y -= 1;
	else if (prop->direction == 'd')
		prop->player_x += 1;
	else if (prop->direction == 'a')
		prop->player_x -= 1;
	else if (prop->direction == 's')
		prop->player_y += 1;
	counter(prop);
	if (prop->exitable == 1 && prop->map[prop->player_y][prop->player_x] == 'E')
		victory(prop);
	prop->map[prop->player_y][prop->player_x] = 'P';
}
