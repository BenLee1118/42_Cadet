/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:25:13 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/10 23:25:07 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_prop **stack)
{
	int		tmp_data;
	int		tmp_index;
	t_prop	*node;
	t_prop	*next_node;

	if (ft_lstsize_ps(*stack) < 2)
		return (FAILURE);
	tmp_data = 0;
	tmp_index = 0;
	node = *stack;
	next_node = node->link;
	if (!node && !next_node)
		ft_error_mssg("!!! Error While Swaping !!!");
	tmp_data = node->data;
	tmp_index = node->index;
	node->data = next_node->data;
	node->index = next_node->index;
	next_node->data = tmp_data;
	next_node->index = tmp_index;
	return (SUCCESS);
}

void	sa(t_prop **stack_a)
{
	if (!(ft_swap(stack_a)))
		ft_mssg("sa\n");
}

void	sb(t_prop **stack_b)
{
	if (!(ft_swap(stack_b)))
		ft_mssg("sb\n");
}

void	ss(t_prop **stack_a, t_prop **stack_b)
{
	if (!(ft_swap(stack_a)) && !(ft_swap(stack_b)))
		ft_mssg("ss\n");
}

void	ra(t_prop **stack_a)
{
	if (ft_lstsize_ps(*stack_a) > 1)
	{
		if (!ft_rotation(stack_a))
			ft_mssg("ra\n");
	}
}

// void	pb(t_prop **stack_a, t_prop	**stack_b)
// {
// 	int		data;
// 	t_prop	*new;

// 	data = (*stack_a)->data;
// 	new = ft_lstnew_ps(data);
// 	ft_lstadd_front_ps(stack_b, new);
// 	*stack_a = ft_free_node(stack_a);
// 	ft_error_mssg("pb\n");
// }

// void	pa(t_prop **stack_a, t_prop	**stack_b)
// {
// 	int		data;
// 	t_prop	*new;

// 	data = (*stack_b)->data;
// 	new = ft_lstnew_ps(data);
// 	ft_lstadd_front_ps(stack_a, new);
// 	*stack_b = ft_free_node(stack_b);
// 	ft_error_mssg("pa\n");
// }

// int	ft_push(t_prop **stack_to, t_prop **stack_from)
// {
// 	t_prop	*tmp;
// 	t_prop	*head_to;
// 	t_prop	*head_from;

// 	if (ft_lstsize_ps(*stack_from) == 0)
// 		return (-1);
// 	head_to = *stack_to;
// 	head_from = *stack_from;
// 	tmp = head_from;
// 	head_from = head_from->link;
// 	*stack_from = head_from;
// 	if (!head_to)
// 	{
// 		head_to = tmp;
// 		head_to->link = NULL;
// 		*stack_to = head_to;
// 	}
// 	else
// 	{
// 		tmp->link = head_to;
// 		*stack_to = tmp;
// 	}
// 	return (0);
// }