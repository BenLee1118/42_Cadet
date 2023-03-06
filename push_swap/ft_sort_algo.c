/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:15:55 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/06 16:57:48 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_prop **stack_a, t_prop **stack_b, t_prop *prop)
{
	int	a;
	int	b;
	int	c;

	a = ft_atoilong(prop->as[0]);
	b = ft_atoilong(prop->as[1]);
	c = ft_atoilong(prop->as[2]);
	stack_b = NULL;
	if (c > a && a > b)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (c < a && b < c)
		ra(stack_a);
	else if (a < c && b > c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && a > c)
		rra(stack_a);
}

void	ft_sort_algo(t_prop **stack_a, t_prop **stack_b, t_prop *prop, int size)
{
	if (!ft_check_sort(stack_a) || size == 1 || size == 0)
		return ;
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		ft_sort3(stack_a, stack_b, prop);
	printlist(*stack_a);
	// else if (size == 4)
	// 	ft_sort4(stack_a);
	// else if (size == 5)
	// 	ft_sort5(stack_a);
}
