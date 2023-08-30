/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:02:22 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/08/30 20:27:27 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_pwr(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 && power == 0)
		return (1);
	else
		return (nb * ft_pwr(nb, power - 1));
}

static void	ft_receivedlength(int *bit_count, int signal, \
		char **str, int *receive)
{
	static int	strlen = 0;

	if (signal == SIGUSR2)
	{
		strlen += ft_pwr(2, *bit_count);
	}
	if (*bit_count == 31)
	{
		*receive = 1;
		*str = ft_calloc(strlen + 1, sizeof(char));
		*bit_count = 0;
		strlen = 0;
		return ;
	}
	(*bit_count)++;
}

void	ft_restart_var(char **str, int *receive, int *i)
{
	if (str)
	{
		ft_putendl_fd(*str, 1);
		free(*str);
		*str = 0;
	}
	*i = 0;
	*receive = 0;
}

void	ft_receivedata(int signal)
{
	static int			bit_count = 0;
	static char			*str = 0;
	static int			receive = 0;
	static int			char_val = 0;
	static int			i = 0;

	if (!receive)
		ft_receivedlength(&bit_count, signal, &str, &receive);
	else
	{
		if (signal == SIGUSR2)
			char_val += ft_pwr(2, bit_count);
		if (bit_count == 7)
		{
			str[i++] = char_val;
			bit_count = 0;
			if (char_val == 0)
				return (ft_restart_var(&str, &receive, &i));
			char_val = 0;
			return ;
		}
		bit_count++;
	}
}

int	main(void)
{
	int	pid;

	pid = (int)getpid();
	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_receivedata);
	signal(SIGUSR2, ft_receivedata);
	while (1)
	{
		usleep(100);
	}
}