/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:33:35 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/11/20 11:33:35 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	char	*src_start;
	char	*dst_end;
	size_t	dstl;
	size_t	left;

	src_start = src;
	dst_end = dest;
	left = size;
	while (left-- != 0 && *dst_end != '\0')
		dst_end++;
	dstl = dst_end - dest;
	left = size - dstl;
	if (left == 0)
		return (dstl + ft_strlen(src));
	while (*src != '\0')
	{
		if (left > 1)
		{
			*dst_end++ = *src;
			left--;
		}
		src++;
	}
	*dst_end = '\0';
	return (dstl + (src - src_start));
}
