/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:15:11 by jyim              #+#    #+#             */
/*   Updated: 2023/03/10 10:20:57 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_writestr(const char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	ft_error(const char *str)
{
	ft_writestr(str);
}
