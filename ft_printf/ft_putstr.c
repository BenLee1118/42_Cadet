/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:46:41 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/02/28 16:07:39 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
		i++;
	length = write(1, str, i);
	return (length);
}
