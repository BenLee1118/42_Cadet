/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:26:26 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/12/07 00:19:27 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = (unsigned char *)str;
	while (i < n)
		tmp[i++] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	if (count >= SIZE_MAX / size)
		return (0);
	i = count * size;
	ptr = malloc(i);
	if (!ptr)
		return (0);
	ft_bzero(ptr, i);
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	join = (char *)malloc((i + j + 1) * sizeof(char));
	if (!join)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	while (s1[i] != '\0')
		join[k++] = s1[i++];
	while (s2[j] != '\0')
		join[k++] = s2[j++];
	join[k] = '\0';
	return (join);
}
