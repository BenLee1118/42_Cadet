/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:27:13 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/10/03 20:43:02 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_check_value(t_data *data)
{
	if (data->n_philo < 1)
		return (FALSE);
	if (data->t_die < 1)
		return (FALSE);
	if (data->t_eat < 1)
		return (FALSE);
	if (data->t_sleep < 1)
		return (FALSE);
	if (data->n_eat < -1)
		return (FALSE);
	return (TRUE);
}

bool	ft_check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		return (false);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (true);
	else
		return (false);
}

bool	ft_check_params(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
	{
		printf ("Incorrect Number of Inputs/Arguments\n");
		return (FALSE);
	}
	while (i < ac)
	{
		if (!ft_check_number(av[i]))
		{
			printf("Not Number Variable Detected\n");
			return (FALSE);
		}
		i++;
	}
	printf("Everything correct \n");
	return (TRUE);
}
