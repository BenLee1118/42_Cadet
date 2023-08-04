/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsig_dec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:39:57 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/12/06 19:21:57 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unbrlen(unsigned int nb)
{
	int	num;

	num = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		num++;
	}
	return (num);
}

int	ft_putnbr_unsig_dec(unsigned int nb)
{
	int	num;

	num = ft_unbrlen(nb);
	if (nb > 9)
	{
		ft_putnbr_unsig_dec(nb / 10);
		ft_putnbr_unsig_dec(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (num);
}
