/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:25:13 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/07 22:18:42 by ltian-ha         ###   ########.fr       */
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
	ft_rotation(stack_a);
	ft_error_mssg("ra\n");
}

void	rb(t_prop **stack_b)
{
	ft_rotation(stack_b);
	ft_error_mssg("rb\n");
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

void	pb(t_prop	*node_a, t_prop **stack_a, t_prop	**stack_b)
{
	int		data;
	t_prop	*new;
	t_prop	*temp;
	t_prop	*prev;

	prev = NULL;
	data = node_a->data;
	new = ft_lstnew_ps(data);
	ft_lstadd_back_ps(stack_b, new);
	temp = *stack_a;
	if (temp != NULL && temp->data == data)
	{
		*stack_a = temp->link;
		free(temp);
		return ;
	}
	while (temp != NULL && temp->data != data)
	{
		prev = temp;
		temp = temp->link;
	}
	prev->link = temp->link;
	free(temp);
}
