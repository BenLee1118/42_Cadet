/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 23:02:58 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/10 23:24:02 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_ps(t_prop *lst)
{
	int		size;
	t_prop	*start;

	size = 0;
	start = lst;
	while (start != NULL)
	{
		size++;
		start = start->link;
	}
	return (size);
}

void	add_stack(int argc, t_prop **stack_a, t_prop *prop)
{
	t_prop	*new;
	int		i;

	i = 0;
	if (argc != 2)
		i = 1;
	while (prop->as[i])
	{
		new = ft_lstnew_ps(ft_atoilong(prop->as[i]));
		ft_lstadd_back_ps(stack_a, new);
		i++;
	}
}

void	ft_sort_stacks(t_prop **stack_a, t_prop **stack_b)
{
	if (ft_lstsize_ps(*stack_a) <= 5)
		ft_sort_algo(stack_a, stack_b, ft_lstsize_ps(*stack_a));
	else
		ft_sort_radix(stack_a, stack_b);
}
