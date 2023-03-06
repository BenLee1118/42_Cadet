/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilitize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:12:24 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/06 16:39:51 by ltian-ha         ###   ########.fr       */
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
