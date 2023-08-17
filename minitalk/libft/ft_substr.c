/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:25:24 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/11/20 11:25:24 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t tot_len)
{
	char	*dest;
	size_t	j;

	j = 0;
	if (tot_len == 0 || !s)
		return (ft_strdup(""));
	dest = (char *)malloc((tot_len + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (j < tot_len && *s)
	{
		if (s[start] == 0x00)
			break ;
		if (start >= ft_strlen(s))
			return (ft_strdup(""));
		dest[j++] = s[start++];
	}
	dest[j] = '\0';
	return (dest);
}
