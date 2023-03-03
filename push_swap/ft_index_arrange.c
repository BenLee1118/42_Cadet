/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_arrange.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:21:43 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/03 19:08:49 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_prop	*find_min(t_prop **stack_a)
{
	t_prop	*min_node;
	t_prop	*head;
	int		found_min;

	min_node = NULL;
	head = *stack_a;
	found_min = 0;
	if (head)
	{
		while (head)
		{
			if ((head)->index == -1 && (!found_min
					|| (head)->data < min_node->data))
			{
				min_node = head;
				found_min = 1;
			}
			//printlist(*stack_a);
			// ft_printf("\n%d\n", (*stack_a)->data);
			(head) = (head)->link;
		}
	}
	return (min_node);
}

void	ft_index_arrange(t_prop **stack_a)
{
	t_prop	*head;
	int		index;

	index = 0;
	head = find_min(stack_a);
	while (head)
	{
		head->index = index++;
		ft_printf("\n%d\n", index);
		head = find_min(stack_a);
	}
}
