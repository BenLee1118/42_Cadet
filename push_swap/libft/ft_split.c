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

int	tab_num(char const *s, char c)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			num++;
		i++;
	}
	return (num);
}

int	str_length(char const *s, char c)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		length++;
	}
	return (length);
}

char	**ft_loop(char const *s, char c, char **tab, int count)
{
	int		strlen;
	int		i;
	int		j;

	while (*s == c)
		s++;
	i = -1;
	while (++i < count)
	{
		while (*s == c)
			s++;
		j = 0;
		strlen = str_length(s, c);
		tab[i] = (char *)malloc(sizeof(char) * (strlen + 1));
		if (!tab[i])
			return (NULL);
		while (j < strlen)
		{
			tab[i][j] = *s;
			s++;
			j++;
		}
		tab[i][j] = '\0';
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (0);
	tab = (char **)malloc((tab_num(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = ft_loop(s, c, tab, tab_num(s, c));
	tab[tab_num(s, c)] = NULL;
	return (tab);
}
