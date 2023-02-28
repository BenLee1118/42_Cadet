/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:40:50 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/11/20 11:40:50 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*strr;
	unsigned char	ch;

	i = 0;
	strr = (unsigned char *)str;
	ch = (unsigned char )c;
	while (i < n)
	{
		if (ch == strr[i])
			return (&strr[i]);
		i++;
	}
	return (0);
}
