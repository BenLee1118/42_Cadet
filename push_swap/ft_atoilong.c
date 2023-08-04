/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoilong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:01:41 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/02 18:10:33 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoilong(const char *str)
{
	int		i;
	long	result;
	int		sign;
	int		j;

	i = 0;
	sign = 1;
	result = 0;
	j = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (j == 10)
			break ;
		result = result * 10 + str[i] - '0';
		i++;
		j++;
	}
	return (result * sign);
}
