/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_arrange.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:21:43 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/07 19:52:46 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_prop	*find_min(t_prop **stack_a)
{
	t_prop	*min_node;
	t_prop	*node;
	int		found_min;

	min_node = NULL;
	node = *stack_a;
	found_min = 0;
	while (node)
	{
		if (node->index == -1 && (!found_min
				|| node->data < min_node->data))
		{
			min_node = node;
			found_min = 1;
		}
		node = node->link;
	}
	return (min_node);
}

// void	ft_index_arrange(t_prop **stack_a)
// {
// 	t_prop	*head;
// 	int		index;

// 	index = 0;
// 	head = find_min(stack_a);
// 	while (head)
// 	{
// 		head->index = index++;
// 		ft_printf("\n%d\n", head->data);
// 		head = find_min(stack_a);
// 	}
// }

void	ft_index_arrange(t_prop **stack_a)
{
	int		index;

	index = 1;
	// printlist(*stack_a);
	while (find_min(stack_a))
	{
		// ft_printf("\n%d\n", (find_min(stack_a))->data);
		(find_min(stack_a))->index = index++;
	}
}
