/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:42:40 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/12/06 20:06:35 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int nb)
{
	int	num;

	num = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 16;
		num++;
	}
	return (num);
}

void	ft_lower(unsigned int nb)
{
	char	*set;

	set = "0123456789abcdef";
	if (nb > 15)
	{
		ft_lower(nb / 16);
		ft_lower(nb % 16);
	}
	else
		ft_putchar(set[nb]);
}

void	ft_upper(unsigned int nb)
{
	char	*set;

	set = "0123456789ABCDEF";
	if (nb > 15)
	{
		ft_upper(nb / 16);
		ft_upper(nb % 16);
	}
	else
		ft_putchar(set[nb]);
}

int	ft_puthex(unsigned int nb, char c)
{
	int	num;

	num = ft_hexlen(nb);
	if (c == 'x')
		ft_lower(nb);
	else
		ft_upper(nb);
	return (num);
}
