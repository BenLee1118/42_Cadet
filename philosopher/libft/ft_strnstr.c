/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:29:20 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/11/20 11:29:20 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (haystack == 0x00 && len == 0)
		return (0);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[j] != '\0')
	{
		i = 0;
		while (needle[i] != '\0' && (i + j) < len)
		{
			if (haystack[j + i] == needle[i])
				i++;
			else
				break ;
		}
		if (needle[i] == '\0')
			return ((char *)haystack + j);
		j++;
	}
	return (0);
}
