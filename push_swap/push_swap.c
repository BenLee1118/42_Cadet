/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:40:23 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/08/02 21:47:04 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	main(int argc, char **argv)
{
	t_prop	**stack_a;
	t_prop	**stack_b;
	t_prop	prop;

	if (argc < 2)
		return (FAILURE);
	ft_check_params(argc, argv, &prop);
	stack_a = (t_prop **)calloc(1, sizeof(t_prop));
	stack_b = (t_prop **)calloc(1, sizeof(t_prop));
	add_stack(argc, stack_a, &prop);
	ft_index_arrange(stack_a);
	if (!ft_check_sort(stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		exit (0);
	}
	ft_sort_stacks(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	exit (0);
}
