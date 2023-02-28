/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:55:41 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/11/07 21:55:41 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	char_count(int n)
{
	int	num;

	num = 0;
	if (n < 0)
	{
		num++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		num++;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		i;

	if (n == -2147483648)
		return (ft_strrdup("-2147483648"));
	if (n == 0)
		return (ft_strrdup("0"));
	i = char_count(n);
	tab = (char *)malloc((i + 1) * sizeof(char));
	if (!tab)
		return (0);
	tab[i] = 0x00;
	if (n < 0)
	{
		tab[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		tab[--i] = (n % 10) + 48;
		n /= 10;
	}
	return (tab);
}
