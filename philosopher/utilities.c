/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:27:24 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/09/30 18:08:34 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_message(void)
{
	printf ("Type the correct Inputs\n");
	printf (RED "Usage: ./philo \
	[number_of_philosophers]\
	[time_to_die]\
	[time_to_eat]\
	[time_to_sleep]\
	[number_of_time_each_philosophers_must_eat]\n" RESET);
	exit (EXIT_FAILURE);
}
