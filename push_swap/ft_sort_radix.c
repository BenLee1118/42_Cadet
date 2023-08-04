/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:11:34 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/09 21:37:03 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max_bits(t_prop **stack_a)
{
	int	max;
	int	i;

	i = 0;
	max = find_maxi_val(stack_a, -1);
	while (1)
	{
		i++;
		if (max / 2 == 0)
			break ;
		max /= 2;
	}
	return (i);
}

// void	ft_sort_radix(t_prop **stack_a, t_prop **stack_b)
// {
// 	t_prop	*head_a;
// 	t_prop	*head_b;
// 	int		max;
// 	int		i;
// 	int		j;
// 	int		size_a;
// 	int 	size_b;

// 	i = 0;
// 	head_a = *stack_a;
// 	head_b = *stack_b;
// 	max = ft_get_max_bits(stack_a);
// 	// printf("%d \n", size_b);
// 	while (i < max)
// 	{
// 		j = 0;
// 		size_a = ft_lstsize_ps(*stack_a);
// 		size_b = ft_lstsize_ps(*stack_b);
// 		// printf("%d \n", size_a);
// 		// printf("%d \n", size_b);
// 		while (j < size_a)
// 		{
// 			head_a = *stack_a;
// 			if (((head_a->index >> i) & 1) == 0)
// 			{
// 				pb(stack_a, stack_b);
// 				rb(stack_b);
// 			}
// 			else
// 				ra(stack_a);
// 			j++;
// 		}
// 		j = 0;
// 		while (j < size_b)
// 		{
// 			head_b = *stack_b;
// 			if (((head_b->index >> i) & 1) == 1)
// 			{
// 				pa(stack_a, stack_b);
// 				if (i + 1 != max)
// 					ra(stack_a);
// 			}
// 			else
// 				rb(stack_b);
// 			j++;
// 		}
// 		i++;
// 	}
// 	while (ft_lstsize_ps(*stack_b) != 0)
// 		pa(stack_a, stack_b);
// }

// static int	ft_get_max_bits(t_prop **stack)
// {
// 	t_prop	*head;
// 	int		max;
// 	int		max_bits;

// 	head = *stack;
// 	max = head->index;
// 	max_bits = 0;
// 	while (head)
// 	{
// 		if (head->index > max)
// 			max = head->index;
// 		head = head->link;
// 	}
// 	while ((max >> max_bits) != 0)
// 		max_bits++;
// 	return (max_bits);
// }

void	ft_sort_radix(t_prop **stack_a, t_prop **stack_b)
{
	t_prop	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize_ps(head_a);
	max_bits = ft_get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize_ps(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
