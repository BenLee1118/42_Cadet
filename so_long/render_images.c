/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:39:58 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/02/27 17:20:42 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_direction(t_prop *prop, int i, int j)
{
	if (prop->map[i][j] == 'P')
	{
		if (prop->direction == 's')
			mlx_put_image_to_window(prop->mlx, prop->wind, prop->playerd,
				j * BIT_SIZE, i * BIT_SIZE);
		else if (prop->direction == 'w')
			mlx_put_image_to_window(prop->mlx, prop->wind, prop->playeru,
				j * BIT_SIZE, i * BIT_SIZE);
		else if (prop->direction == 'd')
			mlx_put_image_to_window(prop->mlx, prop->wind, prop->playerr,
				j * BIT_SIZE, i * BIT_SIZE);
		else if (prop->direction == 'a')
			mlx_put_image_to_window(prop->mlx, prop->wind, prop->playerl,
				j * BIT_SIZE, i * BIT_SIZE);
		else
			mlx_put_image_to_window(prop->mlx, prop->wind, prop->playerd,
				j * BIT_SIZE, i * BIT_SIZE);
	}
}

void	parse_images(t_prop *prop, int width, int i, int j)
{
	if (prop->map[i][j] == '1')
		mlx_put_image_to_window(prop->mlx, prop->wind, prop->wall,
			j * BIT_SIZE, i * BIT_SIZE);
	player_direction(prop, i, j);
	if (prop->map[i][j] == 'C')
		mlx_put_image_to_window(prop->mlx, prop->wind, prop->curcoin,
			j * BIT_SIZE, i * BIT_SIZE);
	if (prop->map[i][j] == '0')
		mlx_put_image_to_window(prop->mlx, prop->wind, prop->gnd,
			j * BIT_SIZE, i * BIT_SIZE);
	if (prop->map[i][j] == 'E')
		mlx_put_image_to_window(prop->mlx, prop->wind, prop->curexit,
			width, i * BIT_SIZE);
	if (prop->map[i][j] == 'G')
		mlx_put_image_to_window(prop->mlx, prop->wind, prop->curgho,
			j * BIT_SIZE, i * BIT_SIZE);
}

int	render_images(t_prop *prop)
{
	int		i;
	size_t	j;
	int		width;

	if (!(prop->wind))
		return (FAILURE);
	i = 0;
	j = 0;
	width = 0;
	while (prop->map[i])
	{
		while (prop->map[i][j] && prop->map[i][j] != '\n')
		{
			parse_images(prop, width, i, j);
			width += BIT_SIZE;
			j++;
		}
		j = 0;
		width = 0;
		i++;
	}
	string_put(prop);
	return (SUCCESS);
}
