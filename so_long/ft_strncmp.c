/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 08:33:24 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/02/24 08:33:24 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	a;

	a = 0;
	while ((s1[a] != 0x00 || s2[a] != 0x00) && a < n)
	{
		if ((s1[a] < s2[a]) || (s1[a] > s2[a]))
			return ((unsigned char )s1[a] - (unsigned char)s2[a]);
		a++;
	}
	return (0);
}
