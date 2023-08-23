/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:02:22 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/08/23 21:37:13 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_pwr(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 && power == 0)
		return (1);
	else
		return (nb * ft_pwr(nb, power - 1));
}

static void	ft_receivedlength(int *bit_count, int signal, char *str)
{
	static int	strlen = 0;

	if (signal == SIGUSR2)
	{
		strlen += ft_pwr(2, *bit_count);
	}
	if (*bit_count == 31)
	{
		printf("%d \n", strlen);
		str = calloc(strlen + 1, sizeof(char));
		*bit_count = 0;
		strlen = 0;
		return ;
	}
	(*bit_count)++;
}

void	ft_receivedata(int signal)
{
	static int		bit_count = 0;
	char			*str;

	str = 0;
	ft_receivedlength(&bit_count, signal, str);
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
