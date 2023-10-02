/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:25:49 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/11/20 11:25:49 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;

	if (!set || !s1)
		return (NULL);
	if (s1[0] == 0x00)
		return (ft_strdup(s1));
	begin = 0;
	end = ft_strlen(s1) - 1;
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	while (end > begin && ft_strchr(set, s1[end]))
		end--;
	if (end - begin == 0)
		return (ft_strdup(s1));
	return (ft_substr(s1, begin, end - begin + 1));
}
