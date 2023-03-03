/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:40:23 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/03 19:44:19 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	printlist(*stack_a);
	return (0);
}
