/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:39:16 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/11/20 11:39:16 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int src, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char *)str;
	while (i < n)
	{
		dest[i] = src;
		i++;
	}
	return (dest);
}
