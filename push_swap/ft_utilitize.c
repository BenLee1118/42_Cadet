/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilitize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:12:24 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/09 20:38:58 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_prop **stack_a)
{
	t_prop	*node;

	node = *stack_a;
	while (node && node->link)
	{
		if (node->data > node->link->data)
			return (FAILURE);
		node = node->link;
	}
	return (SUCCESS);
}

int	find_mini_val(t_prop **stack_a, int i)
{
	t_prop	*head;
	int		min;

	head = *stack_a;
	min = head->index;
	if (i == min)
		min = head->link->index;
	while (head->link)
	{
		head = head->link;
		if (min > head->index && head->index != i)
			min = head->index;
	}
	return (min);
}

int	find_maxi_val(t_prop **stack_a, int i)
{
	t_prop	*head;
	int		max;

	head = *stack_a;
	max = head->index;
	if (i == max)
		max = head->link->index;
	while (head->link)
	{
		head = head->link;
		if (max < head->index && head->index != i)
			max = head->index;
	}
	return (max);
}

t_prop	*ft_free_node(t_prop **stack)
{
	t_prop	*temp;

	if (!(*stack)->link)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		temp = *stack;
		*stack = (*stack)->link;
	}
	return (*stack);
}
