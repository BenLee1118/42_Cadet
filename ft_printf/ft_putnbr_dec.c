/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:28:26 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/12/06 18:40:57 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(int nb)
{
	int	num;

	num = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		num++;
	}
	while (nb > 0)
	{
		nb /= 10;
		num++;
	}
	return (num);
}

int	ft_putnbr_dec(int nb)
{
	int	num;

	num = ft_nbrlen(nb);
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_dec(nb / 10);
		ft_putnbr_dec(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (num);
}
