/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:26:26 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/11 01:28:17 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzeroo(void *str, int n)
{
	unsigned char	*tmp;
	int				i;

	i = 0;
	tmp = (unsigned char *)str;
	while (i < n)
		tmp[i++] = 0;
}

void	*ft_callocc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	if (count >= SIZE_MAX / size)
		return (0);
	i = count * size;
	ptr = malloc(i);
	if (!ptr)
		return (0);
	ft_bzeroo(ptr, i);
	return (ptr);
}

int	ft_strlenn(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchrr(const char *s, int c)
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

char	*ft_strjoinn(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;
	int		k;

	if (!s1 || !s2)
		return (0);
	i = ft_strlenn(s1);
	j = ft_strlenn(s2);
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
