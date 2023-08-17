/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:40:23 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/11/20 11:40:23 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*strr1;
	unsigned char	*strr2;
	int				i;

	strr1 = (unsigned char *)str1;
	strr2 = (unsigned char *)str2;
	i = 0;
	while (n != 0)
	{
		if (strr1[i] != strr2[i])
			return (strr1[i] - strr2[i]);
		i++;
		n--;
	}
	return (0);
}
