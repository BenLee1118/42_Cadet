/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:15:55 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/10 19:58:07 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_prop **stack_a)
{
	t_prop	*head;
	int		mini;
	int		next_mini;

	head = *stack_a;
	mini = find_mini_val(stack_a, -1);
	next_mini = find_mini_val(stack_a, mini);
	// printf(" %d %d \n", mini, next_mini);
	if (head->index == next_mini && head->link->index == mini)
		sa(stack_a);
	else if (head->index != mini && head->link->index == next_mini)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (head->index != next_mini && head->link->index == mini)
		ra(stack_a);
	else if (head->index == mini && head->link->index != next_mini)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (head->index == next_mini && head->link->index != mini)
		rra(stack_a);
	// printlist(*stack_a);
}

void	ft_sort4(t_prop **stack_a, t_prop **stack_b)
{
	t_prop	*mini_node;
	t_prop	*head;
	int		size_a;
	int		i;

	mini_node = find_mini_node(stack_a);
	size_a = ft_lstsize_ps(*stack_a);
	head = *stack_a;
	i = 0;
	while (i < size_a)
	{
		head = *stack_a;
		if (mini_node->index == head->index)
		{
			pb(stack_a, stack_b);
			break ;
		}
		else
			ra(stack_a);
		i++;
	}
	ft_sort3(stack_a);
	while (ft_lstsize_ps(*stack_b) != 0)
		pa(stack_a, stack_b);
}

void	ft_sort5(t_prop **stack_a, t_prop **stack_b)
{
	t_prop	*mini_node;
	// t_prop	*sec_mini_node;
	t_prop	*head;
	int		size_a;
	int		i;

	mini_node = find_mini_node(stack_a);
	size_a = ft_lstsize_ps(*stack_a);
	head = *stack_a;
	i = 0;
	while (i < size_a)
	{
		head = *stack_a;
		if (mini_node->data == head->data)
		{
			pb(stack_a, stack_b);
			break ;
		}
		else
			ra(stack_a);
		i++;
	}
	ft_sort4(stack_a, stack_b);
	// i = 0;
	// sec_mini_node = find_mini_node(stack_a);
	// while (i < size_a)
	// {
	// 	head = *stack_a;
	// 	if (sec_mini_node->data == head->data)
	// 	{
	// 		pb(stack_a, stack_b);
	// 		break ;
	// 	}
	// 	else
	// 		ra(stack_a);
	// 	i++;
	// }
	// ft_sort3(stack_a);
	// while (ft_lstsize_ps(*stack_b) != 0)
	// 	pa(stack_a, stack_b);
	// printlist(*stack_a);
}

void	ft_sort_algo(t_prop **stack_a, t_prop **stack_b, int size)
{
	if (!ft_check_sort(stack_a) || size == 1 || size == 0)
		return ;
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		ft_sort3(stack_a);
	else if (size == 4)
		ft_sort4(stack_a, stack_b);
	else if (size == 5)
		ft_sort5(stack_a, stack_b);
}
