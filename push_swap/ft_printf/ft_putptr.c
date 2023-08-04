/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:19:37 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/12/06 19:42:57 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(unsigned long nb)
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

void	ft_writeptr(unsigned long nb)
{
	char	*set;

	set = "0123456789abcdef";
	if (nb > 15)
	{
		ft_writeptr(nb / 16);
		ft_writeptr(nb % 16);
	}
	else
		ft_putchar(set[nb]);
}

int	ft_putptr(unsigned long nb)
{
	int	num;

	num = 0;
	num += ft_putstr("0x");
	num += ft_ptrlen(nb);
	ft_writeptr(nb);
	return (num);
}
