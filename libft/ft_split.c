/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:36:45 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/11/20 11:36:45 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	tab_num(char const *s, char c)
{
	int	num;
	int	stopper;

	num = 0;
	stopper = 0;
	while (*s)
	{
		if (*s != c && stopper == 0)
		{
			stopper = 1;
			num++;
		}
		else if (*s == c)
			stopper = 0;
		s++;
	}
	return (num);
}

static char	*ft_sentendup(char const *str, int start, int finish)
{
	char	*senten;
	int		i;

	i = 0;
	senten = malloc((finish - start) * sizeof(char));
	while (start < finish)
		senten[i++] = str[start++];
	senten[i] = '\0';
	return (senten);
}

size_t	ft_loop(char const *s, char c, char **tab)
{
	int		start;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			tab[j++] = ft_sentendup(s, start, i);
			start = -1;
		}
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	char	**tab;

	j = 0;
	if (!s)
		return (0);
	tab = malloc((tab_num(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	j = ft_loop(s, c, tab);
	tab[j] = 0x00;
	return (tab);
}
