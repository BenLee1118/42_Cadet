/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:15:55 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/05 18:35:05 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_algo(t_prop **stack_a, t_prop **stack_b, int size)
{
	if (!ft_check_sort(stack_a) || size == 1 || size == 0)
		return ;
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		ft_sort3(stack_a);
	// else if (size == 4)
	// 	ft_sort4(stack_a);
	// else if (size == 5)
	// 	ft_sort5(stack_a);
}
