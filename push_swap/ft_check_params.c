/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:47:09 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/03 16:03:17 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_mssg(char *str)
{
	ft_putstr(str);
}

int	ft_check_value(char *nums)
{
	int	i;

	i = 0;
	if (nums[0] == '-')
		i++;
	while (nums[i])
	{
		if (!ft_isdigit(nums[i]))
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

int	ft_check_repeat(int hold_val, char **nums, int i)
{
	while (nums[++i])
	{
		if (ft_atoi(nums[i]) == hold_val)
			return (SUCCESS);
	}
	return (FAILURE);
}

void	ft_check_params(int ac, char **av, t_prop *prop)
{
	int			i;
	long		hold_val;
	// t_prop		prop;

	i = 0;
	if (ac > 2)
	{
		prop->as = av;
		i = 1;
	}
	else
		prop->as = ft_split(av[1], ' ');
	while (prop->as[i])
	{
		hold_val = ft_atoilong(prop->as[i]);
		if (!ft_check_value(prop->as[i]))
			ft_error_mssg("!!! NOT A NUMBER !!! \n");
		else if (hold_val > 2147483647 || hold_val < -2147483648)
			ft_error_mssg("!!! OVER BUDGET !!! \n");
		else if (!ft_check_repeat(hold_val, prop->as, i))
			ft_error_mssg("!!! HAVE REPETITION !!! \n");
		else
			ft_error_mssg("CORRECT \n");
		i += 1;
	}
}
