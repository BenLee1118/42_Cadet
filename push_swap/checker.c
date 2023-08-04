/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 23:39:37 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/08/02 21:37:31 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_actions(char *str, t_prop **stack_a, t_prop **stack_b)
{
	if (!(ft_strcmp(str, "sa")))
	{
		ft_swap(stack_a);
		return (SUCCESS);
	}
	if (!(ft_strcmp(str, "sb")))
	{
		ft_swap(stack_b);
		return (SUCCESS);
	}
	if (!(ft_strcmp(str, "ss")))
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
		return (SUCCESS);
	}
	if (!(ft_strcmp(str, "pa")))
	{
		ft_push(stack_a, stack_b);
		return (SUCCESS);
	}
	if (!(ft_strcmp(str, "pb")))
	{
		ft_push(stack_b, stack_a);
		return (SUCCESS);
	}
	if (!(ft_strcmp(str, "ra")))
	{
		if (ft_lstsize_ps(*stack_a) > 1)
		{
			ft_rotation(stack_a);
			return (SUCCESS);
		}
	}
	if (!(ft_strcmp(str, "rb")))
	{
		if (ft_lstsize_ps(*stack_b) > 1)
		{
			ft_rotation(stack_b);
			return (SUCCESS);
		}
	}
	if (!(ft_strcmp(str, "rr")))
	{
		if (ft_lstsize_ps(*stack_a) > 1 && ft_lstsize_ps(*stack_b) > 1)
		{
			ft_rotation(stack_a);
			ft_rotation(stack_b);
			return (SUCCESS);
		}
	}
	if (!(ft_strcmp(str, "rra")))
	{
		ft_rotation_rev(stack_a);
		return (SUCCESS);
	}
	if (!(ft_strcmp(str, "rrb")))
	{
		ft_rotation_rev(stack_b);
		return (SUCCESS);
	}	
	if (!(ft_strcmp(str, "rrr")))
	{
		ft_rotation_rev(stack_a);
		ft_rotation_rev(stack_b);
		return (SUCCESS);
	}
	return (FAILURE);
}

void	ft_looping(t_prop **stack_a, t_prop **stack_b, int size)
{
	char	*str;

	str = NULL;
	(void) size;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (str[ft_strlen(str) - 1] == '\n')
			str[ft_strlen(str) - 1] = 0;
		if (ft_actions(str, stack_a, stack_b))
		{
			ft_error_mssg("Error");
			break ;
		}
		free(str);
	}
	if (!ft_check_sort(stack_a) && *stack_b == NULL)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int argc, char **argv)
{
	t_prop	**stack_a;
	t_prop	**stack_b;
	t_prop	prop;
	int		size;

	if (argc < 2)
		return (FAILURE);
	ft_check_params(argc, argv, &prop);
	stack_a = (t_prop **)calloc(1, sizeof(t_prop));
	stack_b = (t_prop **)calloc(1, sizeof(t_prop));
	add_stack(argc, stack_a, &prop);
	ft_index_arrange(stack_a);
	size = ft_lstsize_ps(*stack_a);
	ft_looping(stack_a, stack_b, size);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
