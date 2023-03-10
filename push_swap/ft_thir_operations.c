/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thir_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:50:38 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/10 23:13:51 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotation(t_prop **stack)
{
	t_prop	*first_node;
	t_prop	*last_node;

	if (ft_lstsize_ps(*stack) < 2)
		return (FAILURE);
	first_node = *stack;
	last_node = ft_lastnode_ps(first_node);
	*stack = first_node->link;
	last_node->link = first_node;
	first_node->link = NULL;
	return (SUCCESS);
}

int	ft_rotation_rev(t_prop **stack)
{
	t_prop	*first_node;
	t_prop	*last_node;

	if (ft_lstsize_ps(*stack) < 2)
		return (FAILURE);
	first_node = *stack;
	last_node = ft_lastnode_ps(first_node);
	while (first_node)
	{
		if (first_node->link->link == NULL)
		{
			first_node->link = NULL;
			break ;
		}
		first_node = first_node->link;
	}
	last_node->link = *stack;
	*stack = last_node;
	return (SUCCESS);
}

int	ft_push(t_prop **dest, t_prop **src)
{
	t_prop	*arrive;
	t_prop	*depart;
	t_prop	*temp;

	if (ft_lstsize_ps(*src) == 0)
		return (FAILURE);
	arrive = *dest;
	depart = *src;
	temp = depart;
	depart = depart->link;
	*src = depart;
	if (!arrive)
	{
		arrive = temp;
		arrive->link = NULL;
		*dest = arrive;
	}
	else
	{
		temp->link = arrive;
		*dest = temp;
	}
	return (SUCCESS);
}

void	pa(t_prop **stack_a, t_prop **stack_b)
{
	if (ft_push(stack_a, stack_b) == -1)
		return ;
	ft_mssg("pa\n");
}

void	pb(t_prop **stack_a, t_prop **stack_b)
{
	if (ft_push(stack_b, stack_a) == -1)
		return ;
	ft_mssg("pb\n");
}
