/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:02:54 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/08/28 21:36:00 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_strlen(int pid, int strlen)
{
	int	i;

	i = 0;
	while (i++ < 32)
	{
		if (strlen & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		strlen = strlen >> 1;
		usleep(100);
	}
}

void	ft_send_str(int pid, char letter)
{
	int	i;

	i = 0;
	while (i++ <= 7)
	{
		if (letter & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		letter = letter >> 1;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		strlen;
	int		i;
	int		j;
	char	*str;

	str = NULL;
	i = -1;
	if (ac != 3)
		return (1);
	pid = ft_atoi(av[1]);
	str = av[2];
	strlen = ft_strlen(str);
	ft_send_strlen(pid, strlen);
	j = -1;
	while (str[++j])
		ft_send_str(pid, str[j]);
	ft_send_str(pid, str[j]);
}
