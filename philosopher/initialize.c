/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:48:50 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/10/02 21:42:00 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_data(t_data *data, char **av)
{
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->n_eat = -1;
	data->all_eaten = 0;
	data->dead = 0;
	if (av[5])
		data->n_eat = ft_atoi(av[5]);
	return (ft_check_value(data));
}

int	ft_init_mutex(t_data *data)
{
	printf("%d \n", data->n_philo);
	return (TRUE);
}

// malloc 5 * sizeof(t_data)
// philo 1 1,2
// philo 2 2,3
// philo 3 3,1

// fork[3]