/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 05:28:26 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/02/27 15:33:00 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_prop	assign_mapprop(void)
{
	t_prop	prop;

	prop.num_row = 0;
	prop.num_col = 0;
	prop.num_exit = 0;
	prop.num_p1 = 0;
	prop.num_gho = 0;
	prop.num_coll = 0;
	prop.coins_collected = 0;
	prop.exitable = 0;
	prop.steps_count = 0;
	prop.frame = 0;
	prop.seed1 = 1234;
	return (prop);
}

t_error	assign_maperr(void)
{
	t_error	map_error;

	map_error.inval_rowlen = 0;
	map_error.inval_char = 0;
	map_error.inval_n_exit = 0;
	map_error.inval_n_player = 0;
	map_error.inval_n_collect = 0;
	map_error.inval_borders = 0;
	return (map_error);
}
