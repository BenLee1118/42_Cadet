/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:25:13 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/09 21:20:33 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_prop **stack)
{
	int		tmp_data;
	int		tmp_index;
	t_prop	*node;
	t_prop	*next_node;

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
}

void	ft_rotation(t_prop **stack)
{
	t_prop	*first_node;
	t_prop	*last_node;

	first_node = *stack;
	last_node = ft_lastnode_ps(stack);
	*stack = first_node->link; // Ori link starts at second node
	last_node->link = first_node; // last node links to first node
	first_node->link = NULL; // first node links to NULL
}

void	ft_rotation_rev(t_prop **stack)
{
	t_prop	*first_node;
	t_prop	*last_node;

	first_node = *stack;
	last_node = ft_lastnode_ps(stack);
	while (first_node)
	{
		if (first_node->link->link == NULL)
		{
			first_node->link = NULL;
			break ;
		}
		first_node = first_node->link;
	}
	last_node->link = *stack; // last node links to first node
	*stack = last_node; // Ori link starts at last node
}

void	sa(t_prop **stack_a)
{
	ft_swap(stack_a);
	ft_error_mssg("sa\n");
}

void	sb(t_prop **stack_b)
{
	ft_swap(stack_b);
	ft_error_mssg("sb\n");
}

void	ss(t_prop **stack_a, t_prop **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_error_mssg("ss\n");
}

void	ra(t_prop **stack_a)
{
	if (ft_lstsize_ps(*stack_a) > 1)
	{
		ft_rotation(stack_a);
		ft_error_mssg("ra\n");
	}
}

void	rb(t_prop **stack_b)
{

	if (ft_lstsize_ps(*stack_b) > 1)
	{
		ft_rotation(stack_b);
		ft_error_mssg("rb\n");
	}
}

void	rr(t_prop **stack_a, t_prop **stack_b)
{
	ft_rotation(stack_a);
	ft_rotation(stack_b);
	ft_error_mssg("rr\n");
}

void	rra(t_prop	**stack_a)
{
	ft_rotation_rev(stack_a);
	ft_error_mssg("rra\n");
}

void	rrb(t_prop	**stack_b)
{
	ft_rotation_rev(stack_b);
	ft_error_mssg("rrb\n");
}

void	rrr(t_prop	**stack_a, t_prop	**stack_b)
{
	ft_rotation_rev(stack_a);
	ft_rotation_rev(stack_b);
	ft_error_mssg("rrr\n");
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

int	push(t_prop **stack_to, t_prop **stack_from)
{
	t_prop	*tmp;
	t_prop	*head_to;
	t_prop	*head_from;

	if (ft_lstsize_ps(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->link;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->link = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->link = head_to;
		*stack_to = tmp;
	}
	return (0);
}

int	pa(t_prop **stack_a, t_prop **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_prop **stack_a, t_prop **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}