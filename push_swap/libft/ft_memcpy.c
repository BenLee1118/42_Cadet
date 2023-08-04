/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:39:57 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/11/20 11:39:57 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*destt;
	char	*srcc;
	size_t	i;

	i = 0;
	destt = (char *)dest;
	srcc = (char *)src;
	if (!destt && !srcc)
		return (0);
	while (i < n)
	{
		destt[i] = srcc[i];
		i++;
	}
	return (destt);
}
