/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:34:15 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/11/20 11:34:15 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !s2)
		return (0);
	dest = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	while (s1[i] != '\0' && k < ft_strlen(s1))
		dest[k++] = s1[i++];
	while (s2[j] != '\0' && k < (ft_strlen(s1) + ft_strlen(s2)))
		dest[k++] = s2[j++];
	dest[k] = '\0';
	return (dest);
}
