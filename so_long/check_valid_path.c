/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:29:41 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/02/27 17:37:13 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(int i, int j, t_prop prop, int *num_collections)
{
	if (*num_collections != prop.old_collections)
		return ;
	if (prop.map[i][j] == '1' || i > prop.num_row || \
			j > prop.num_col || j < 0 || i < 0)
		return ;
	if (prop.visited [i][j] == 1)
		return ;
	if (prop.map[i][j] == 'P')
	{
		*num_collections += 1;
		return ;
	}
	prop.visited[i][j] = 1;
	floodfill(i + 1, j, prop, num_collections);
	floodfill(i - 1, j, prop, num_collections);
	floodfill(i, j + 1, prop, num_collections);
	floodfill(i, j - 1, prop, num_collections);
}

void	floodfill_exit(int i, int j, t_prop prop, int *exit)
{
	if (*exit == 1)
		return ;
	if (prop.map[i][j] == '1' || i > prop.num_row || \
			j > prop.num_col || j < 0 || i < 0)
		return ;
	if (prop.visited [i][j] == 1)
		return ;
	if (prop.map[i][j] == 'E')
	{
		*exit = 1;
		return ;
	}
	prop.visited[i][j] = 1;
	floodfill_exit(i + 1, j, prop, exit);
	floodfill_exit(i - 1, j, prop, exit);
	floodfill_exit(i, j + 1, prop, exit);
	floodfill_exit(i, j - 1, prop, exit);
}

void	reset_visited(t_prop *prop)
{
	int	i;
	int	j;

	i = -1;
	while (++i < prop->num_row)
	{
		j = -1;
		while (++j < prop->num_col)
			prop->visited[i][j] = 0;
	}
}

void	loop_floodfill(t_prop prop, int num_collections, int exit)
{
	int	i;
	int	j;

	i = 0;
	while (prop.map[i])
	{
		j = 0;
		while (prop.map[i][j])
		{
			if (prop.map[i][j] == 'C')
			{
				floodfill(i, j, prop, &num_collections);
				prop.old_collections = num_collections;
			}
			reset_visited(&prop);
			if (prop.map[i][j] == 'P')
				floodfill_exit(i, j, prop, &exit);
			reset_visited(&prop);
			j++;
		}
		i++;
	}
	if (prop.old_collections != prop.num_coll || exit == 0)
		error_params("INVALID PATH or NO EXIT/PLAYER !!!", NULL);
}

void	check_valid_path(t_prop prop)
{
	int		i;
	int		num_collections;
	int		exit;

	prop.old_collections = 0;
	num_collections = 0;
	exit = 0;
	prop.visited = ft_calloc(prop.num_row, sizeof(int *));
	i = 0;
	while (i < prop.num_row)
	{
		prop.visited[i] = ft_calloc(prop.num_col, sizeof(int));
		i++;
	}
	loop_floodfill(prop, num_collections, exit);
	i = -1;
	while (++i < prop.num_row)
		free(prop.visited[i]);
	free(prop.visited);
}
