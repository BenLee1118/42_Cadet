/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:30:42 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/02/27 18:06:12 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_free_bonus(char **tab)
// {
// 	size_t	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	tab = NULL;
// 	return ;
// }

int	main(int argc, char **argv)
{
	char	**map;
	t_prop	prop;

	map = inspect_params(argc, argv, &prop);
	prop.map = map;
	check_valid_path(prop);
	init_window(&prop);
	init_images(&prop);
	render_images(&prop);
	init_player(&prop);
	hook_images(prop);
	// free(prop.mlx);
	// if (prop.map)
	// 	ft_free_bonus(prop.map);
	return (0);
}
