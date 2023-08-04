/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_arrange.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:21:43 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/10 23:12:35 by ltian-ha         ###   ########.fr       */
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

void	ft_index_arrange(t_prop **stack_a)
{
	int		index;

	index = 1;
	while (find_min(stack_a))
		(find_min(stack_a))->index = index++;
}
