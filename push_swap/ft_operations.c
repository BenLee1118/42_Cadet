/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:25:13 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/05 18:35:00 by ltian-ha         ###   ########.fr       */
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

void	sa(t_prop **stack_a)
{
	ft_swap(stack_a);
	ft_error_mssg("sa\n");
}
