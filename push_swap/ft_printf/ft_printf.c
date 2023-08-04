/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:59:06 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/02/28 16:37:00 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_nextchar(char ch, va_list listt)
{
	int	num;

	num = 0;
	if (ch == 'c')
		num = ft_putchar(va_arg(listt, int));
	if (ch == 's')
		num = ft_putstr(va_arg(listt, char *));
	if (ch == 'p')
		num = ft_putptr(va_arg(listt, unsigned long));
	if (ch == 'd' || ch == 'i')
		num = ft_putnbr_dec(va_arg(listt, int));
	if (ch == 'u')
		num = ft_putnbr_unsig_dec(va_arg(listt, unsigned int));
	if (ch == 'x' || ch == 'X')
		num = ft_puthex(va_arg(listt, unsigned int), ch);
	if (ch == '%')
		num = ft_putchar('%');
	return (num);
}

int	ft_printf(const char *str, ...)
{
	va_list	listt;
	int		i;
	int		num;

	i = 0;
	num = 0;
	va_start(listt, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			num += check_nextchar(str[i + 1], listt);
			i += 2;
		}
		else
			num += ft_putchar(str[i++]);
	}
	return (num);
}

// int	main()
// {
// 	char	d;

// 	d = 'a';
// 	ft_printf("%c", d);
// 	return (0);
// }