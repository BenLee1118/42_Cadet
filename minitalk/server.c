/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:02:22 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/08/17 20:47:38 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receivedata(int signal)
{
	if (signal == SIGUSR1)
	{
		printf("hi\n\n");
	}
	else
	{
		printf("bye \n\n");
	}
}

int	main(void)
{
	int	pid;

	pid = (int)getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_receivedata);

	while (1)
	{
		usleep(100);
	}
}