/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:21:19 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/02/27 13:33:21 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**inspect_map(int fd, t_prop *prop);

int	error_params(char *str, char **map_str)
{
	if (map_str)
		free(*map_str);
	ft_putstr(str);
	exit(SUCCESS);
	return (0);
}

char	**inspect_params(int argc, char **argv, t_prop *prop)
{
	int	fd;
	int	pointing;

	if (argc != 2)
		error_params("Invalid Arguments", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_params("FILE NOT FOUND !!!", NULL);
	pointing = ft_strlen((const char *)argv[1]) - 4;
	if (ft_strncmp((argv[1] + pointing), ".ber", 4))
		error_params("WRONG FILE TYPE, PLS USE .ber", NULL);
	return (inspect_map(fd, prop));
}

char	**inspect_map(int fd, t_prop *prop)
{
	char	*map_sentence;
	char	**map;
	t_error	map_error;

	map_sentence = NULL;
	map = NULL;
	map_error = assign_maperr();
	*prop = assign_mapprop();
	ft_readmap(fd, &map_error, prop, &map_sentence);
	ft_map_error(&map_error, &map_sentence);
	map = ft_split(map_sentence, "\n");
	free(map_sentence);
	if (!map)
		error_params("WRONG MEMORY ALLOCATION !!!", NULL);
	return (map);
}
