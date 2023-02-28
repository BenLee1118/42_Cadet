/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maplysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 05:32:47 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/02/27 12:46:32 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count(char *str, char c)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			nb++;
		i++;
	}
	return (nb);
}

void	ft_readmap(int fd, t_error *map_error, t_prop *prop, char **map_sent)
{
	char	*str;
	char	*last_str;

	str = NULL;
	last_str = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
		{
			if (!prop->num_col)
				error_params("MAP EMPTY !!!", NULL);
			else
				ft_scan_map(last_str, map_error, prop, 1);
			free(last_str);
			break ;
		}
		free(last_str);
		ft_scan_map(str, map_error, prop, !prop->num_row);
		last_str = ft_substr(str, 0, ft_strlen(str));
		*map_sent = ft_strenlarge(*map_sent, str);
		prop->num_row++;
	}
}

void	ft_scan_map(char *str, t_error *map_error, t_prop *prop, int last)
{
	if (!prop->num_col)
		prop->num_col = ft_strlen(str) - 1;
	if (prop->num_col && ((prop->num_col != (int)ft_strlen(str) - 1 && \
			ft_strrchr(str, '\n')) || (prop->num_col != ft_strlen(str) \
			&& !ft_strrchr(str, '\n'))))
		map_error->inval_rowlen = 1;
	if (str[prop->num_col - 1] != '1' || str[0] != '1' || \
			(ft_count(str, '1') != prop->num_col && last))
		map_error->inval_borders = 1;
	prop->num_exit += ft_count(str, 'E');
	prop->num_p1 += ft_count(str, 'P');
	prop->num_gho += ft_count(str, 'G');
	prop->num_coll += ft_count(str, 'C');
	map_error->inval_n_exit = prop->num_exit > 1;
	map_error->inval_n_player = prop->num_p1 > 1;
	map_error->inval_n_collect = prop->num_coll < 1;
	while (str && *str)
	{
		if (!ft_strrchr("01CEPG\n", *str))
			map_error->inval_char = 1;
		str++;
	}
}

int	ft_map_error(t_error *map_error, char **map_str)
{
	if (map_error->inval_rowlen)
		error_params("MAP NOT RECTANGULAR !!", map_str);
	if (map_error->inval_borders)
		error_params("MAP NOT SURROUND BY WALLS !!", map_str);
	if (map_error->inval_char)
		error_params("OTHER char(s) SPOTTED in map!", map_str);
	if (map_error->inval_n_exit)
		error_params("SHOULD ONLY ONE EXIT !!", map_str);
	if (map_error->inval_n_player)
		error_params("SHOULD ONLY ONE PLAYER !!", map_str);
	if (map_error->inval_n_collect)
		error_params("AT LEAST ONE COLLECTABLES !!", map_str);
	return (0);
}
