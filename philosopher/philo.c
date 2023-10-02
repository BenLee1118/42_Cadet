/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:42:51 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/10/02 18:09:26 by ltian-ha         ###   ########.fr       */
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
	// t_data	data;
	// pthread_t t0;

	// pthread_create(&t0, NULL, &test, &data);
	// pthread_join(t0, NULL);
	// printf("EXITED\n");

	if (!ft_check_params(argc, argv))
	{
		ft_print_message();
		return (FALSE);
	}
	// if (ft_initialize(&data, argv))
	// {
	// 	free(data.philo);
	// 	return (FALSE);
	// }
	// ft_philo_start(&data);
	// ft_philo_end(&data); //free
}
