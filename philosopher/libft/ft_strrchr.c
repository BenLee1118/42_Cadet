/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 04:45:06 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/10/17 04:45:06 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*strr;

	strr = NULL;
	while (*str)
	{
		if (*str == c)
			strr = (char *)str;
		str++;
	}
	if (c == '\0')
		strr = (char *)str;
	return (strr);
}
