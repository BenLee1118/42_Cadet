/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:04:35 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/02/27 18:06:22 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_prop *prop)
{
	prop->mlx = mlx_init();
	if (prop->mlx == NULL)
		return ;
	prop->wind = mlx_new_window(prop->mlx, prop->num_col * BIT_SIZE, \
	prop->num_row * BIT_SIZE, "POKEMON MAZE RUN");
	if (prop->wind == NULL)
	{
		free(prop->wind);
		return ;
	}
}

void	init_images(t_prop *prop)
{
	int	i;
	int	j;

	prop->gnd = mlx_xpm_file_to_image(prop->mlx, GROUND, &i, &j);
	prop->wall = mlx_xpm_file_to_image(prop->mlx, WALLL, &i, &j);
	prop->exit = mlx_xpm_file_to_image(prop->mlx, KELUAR, &i, &j);
	prop->exit2 = mlx_xpm_file_to_image(prop->mlx, KELUAR2, &i, &j);
	prop->exit3 = mlx_xpm_file_to_image(prop->mlx, KELUAR3, &i, &j);
	prop->curexit = prop->exit;
	prop->playerd = mlx_xpm_file_to_image(prop->mlx, PLAYERD, &i, &j);
	prop->playeru = mlx_xpm_file_to_image(prop->mlx, PLAYERU, &i, &j);
	prop->playerl = mlx_xpm_file_to_image(prop->mlx, PLAYERL, &i, &j);
	prop->playerr = mlx_xpm_file_to_image(prop->mlx, PLAYERR, &i, &j);
	prop->coin1 = mlx_xpm_file_to_image(prop->mlx, COIN1, &i, &j);
	prop->coin2 = mlx_xpm_file_to_image(prop->mlx, COIN2, &i, &j);
	prop->coin3 = mlx_xpm_file_to_image(prop->mlx, COIN3, &i, &j);
	prop->curcoin = prop->coin1;
	prop->ghost1 = mlx_xpm_file_to_image(prop->mlx, GHOST1, &i, &j);
	prop->ghost2 = mlx_xpm_file_to_image(prop->mlx, GHOST2, &i, &j);
	prop->ghost3 = mlx_xpm_file_to_image(prop->mlx, GHOST3, &i, &j);
	prop->curgho = prop->ghost1;
}

void	init_player(t_prop *prop)
{
	int	i;
	int	j;

	i = 0;
	while (prop->map[i])
	{
		j = 0;
		while (prop->map[i][j] && prop->map[i][j] != '\n')
		{
			if (prop->map[i][j] == 'P')
			{
				prop->player_y = i;
				prop->player_x = j;
			}
			else if (prop->map[i][j] == 'G')
			{
				prop->ghost_y = i;
				prop->ghost_x = j;
			}
			j++;
		}
	i++;
	}
}

int	close_p(void *param)
{
	(void)param;
	exit(0);
}

void	hook_images(t_prop prop)
{
	mlx_loop_hook(prop.mlx, draw_frames, &prop);
	mlx_hook(prop.wind, 2, 0, key_handlers, &prop);
	mlx_hook(prop.wind, 17, 0, close_p, &prop);
	mlx_loop(prop.mlx);
}

//mlx_hook(prop.wind, 3, 0, keyrelease_handlers, &prop);