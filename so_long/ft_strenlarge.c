/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strenlarge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:53:12 by aperez-b          #+#    #+#             */
/*   Updated: 2023/02/26 23:45:00 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*run(char *s1, char *s2)
{
	int		i;
	int		len_s1;
	int		len_s2;
	char	*s3;

	i = 0;
	len_s1 = ft_strlen((const char *)s1);
	len_s2 = ft_strlen((const char *)s2);
	s3 = (char *)malloc(len_s1 + len_s2 + 1);
	if (s3 == NULL)
		return (NULL);
	while (i < len_s1 || i < len_s2)
	{
		if (i < len_s1)
			s3[i] = s1[i];
		if (i < len_s2)
			s3[i + len_s1] = s2[i];
		i++;
	}
	s3[len_s1 + len_s2] = '\0';
	free(s1);
	free(s2);
	return (s3);
}

char	*ft_strenlarge(char *s1, char *s2)
{
	if (!s1)
		return (ft_strrdup(s2));
	if (s2 == NULL || !s1)
		return (NULL);
	return (run(s1, s2));
}
