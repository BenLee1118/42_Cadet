/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:42:51 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/10/03 21:03:39 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	ft_philo_start(t_data *data)
// {
// 	while (i < data->philonum)
// 	{
// 		pthread_create()
// 	}
	
// }
// void *test(void *data)
// {
// 	int i = 0;
// 	while(1)
// 	{
// 		if (i > 1000)
// 			return 0;
// 		printf("%d\n", i++);
// 	}
// }

int	main(int argc, char **argv)
{
	t_data	data;
	// pthread_t t0;

	// pthread_create(&t0, NULL, &test, &data);
	// pthread_join(t0, NULL);
	// printf("EXITED\n");

	if (!ft_check_params(argc, argv))
	{
		ft_print_message();
		return (FALSE);
	}
	if (!ft_init_data(&data, argv) || !ft_init_mutex(&data) || \
	!ft_init_philo(&data))
	{
		free(data.philo);
		return (FALSE);
	}
	// ft_philo_start(&data);
	// ft_philo_end(&data); //free
}
