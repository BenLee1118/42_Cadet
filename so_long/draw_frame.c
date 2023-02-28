/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:02:50 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/02/27 17:24:49 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_animations(t_prop *prop)
{
	if (prop->curexit == prop->exit && prop->curcoin == prop->coin1
		&& prop->curgho == prop->ghost1)
	{
		prop->curexit = prop->exit3;
		prop->curcoin = prop->coin2;
		prop->curgho = prop->ghost2;
	}
	else if (prop->curexit == prop->exit3 && prop->curcoin == prop->coin2
		&& prop->curgho == prop->ghost2)
	{
		prop->curexit = prop->exit2;
		prop->curcoin = prop->coin3;
		prop->curgho = prop->ghost3;
	}
	else
	{
		prop->curexit = prop->exit;
		prop->curcoin = prop->coin1;
		prop->curgho = prop->ghost1;
	}
}

int	draw_frames(t_prop *prop)
{
	prop->frame++;
	if (prop->frame != 8000)
		return (0);
	sprite_animations(prop);
	mlx_clear_window(prop->mlx, prop->wind);
	render_images(prop);
	prop->frame = 0;
	return (0);
}
