/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sec_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:53:11 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/10 23:12:57 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_prop **stack_b)
{
	if (ft_lstsize_ps(*stack_b) > 1)
	{
		if (!ft_rotation(stack_b))
			ft_mssg("rb\n");
	}
}

void	rr(t_prop **stack_a, t_prop **stack_b)
{
	if (ft_lstsize_ps(*stack_a) > 1 && ft_lstsize_ps(*stack_b) > 1)
	{
		if (!ft_rotation(stack_a) && !ft_rotation(stack_b))
			ft_mssg("rr\n");
	}
}

void	rra(t_prop	**stack_a)
{
	if (!ft_rotation_rev(stack_a))
		ft_mssg("rra\n");
}

void	rrb(t_prop	**stack_b)
{
	if (!ft_rotation_rev(stack_b))
		ft_mssg("rrb\n");
}

void	rrr(t_prop	**stack_a, t_prop	**stack_b)
{
	if (!ft_rotation_rev(stack_a) && !ft_rotation_rev(stack_b))
		ft_mssg("rrr\n");
}
