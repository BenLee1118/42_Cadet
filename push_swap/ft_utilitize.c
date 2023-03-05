/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilitize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:12:24 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/05 18:32:18 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_prop **stack_a)
{
	t_prop	*node;
	t_prop	*next_node;

	node = *stack_a;
	next_node = node->link;
	while (node && next_node)
	{
		if (node->data > next_node->data)
			return (FAILURE);
		next_node = node->link;
		node = node->link;
	}
	return (SUCCESS);
}
