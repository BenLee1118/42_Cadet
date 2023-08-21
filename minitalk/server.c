/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:02:22 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/08/21 22:26:19 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receivedata(int signal)
{
	// if (signal == SIGUSR1)
	// {
	// 	printf("%d\n\n", signal);
	// }
	// else
	// {
	// 	printf("2nd: %d\n\n", signal);
	// }
}

int	main(void)
{
	int	pid;

	pid = (int)getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_receivedata);
	signal(SIGUSR2, ft_receivedata);

	while (1)
	{
		usleep(100);
	}
}
