/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:45:28 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/11/20 11:45:28 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	total_size;
	void	*dest;

	if (size == 0 || nitems == 0)
		return (ft_strdup(""));
	if (nitems >= SIZE_MAX / size)
		return (0);
	total_size = size * nitems;
	dest = malloc(total_size);
	if (!dest)
		return (0);
	ft_bzero(dest, total_size);
	return (dest);
}
