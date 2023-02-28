/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:14:38 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/10/20 11:14:38 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char const *s, unsigned int start, int tot_len)
{
	char	*dest;
	int		i;
	int		j;

	i = start;
	j = 0;
	dest = (char *)malloc(tot_len + 1);
	if (!s || !(dest))
		return (0);
	while (j < tot_len && i < ft_strlen(s))
	{
		dest[j++] = s[i++];
	}
	dest[j] = '\0';
	return (dest);
}
