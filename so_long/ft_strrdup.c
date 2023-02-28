/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:11:06 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/10/08 13:11:06 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrdup(const char *src)
{
	char		*dest;
	size_t		index;

	index = 0;
	dest = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	if (dest == NULL)
		return (0);
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
