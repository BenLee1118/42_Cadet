/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:48:50 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/10/03 21:27:36 by ltian-ha         ###   ########.fr       */
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
	int				i;
	int				n_fork;
	pthread_mutex_t	*fork;

	i = 0;
	n_fork = data->n_philo;
	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n_fork);
	while (i++ < n_fork)
		pthread_mutex_init(&fork[i], NULL);
	data->fork = fork;
	pthread_mutex_init(&(data->printing), NULL);
	pthread_mutex_init(&(data->checking), NULL);
	pthread_mutex_init(&(data->eating), NULL);
	pthread_mutex_init(&(data->dying), NULL);
	return (TRUE);
}

int	ft_init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;
	int		n_philo;

	i = 0;
	n_philo = data->n_philo;
	philo = (t_philo *) malloc(sizeof(t_philo) * n_philo);
	while (i++ < data->n_philo)
	{
		philo[i].id = i + 1;
		philo[i].fork_left_id = i;
		philo[i].fork_right_id = (i + 1) % data->n_philo;
		philo[i].n_ate = 0;
		philo[i].data = data;
	}
	data->philo = philo;
	return (TRUE);
}
// malloc 5 * sizeof(t_data)
// philo 1 1,2
// philo 2 2,3
// philo 3 3,1

// fork[3]