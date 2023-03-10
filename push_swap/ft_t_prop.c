/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_prop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:12:50 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/10 15:18:45 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_prop	*ft_lstnew_ps(int a)
{
	t_prop	*new;

	new = (t_prop *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->data = a;
	new->link = NULL;
	new->index = -1;
	return (new);
}

void	ft_lstadd_front_ps(t_prop **lst, t_prop *new)
{
	new->link = *lst;
	*lst = new;
}

void	ft_lstadd_back_ps(t_prop **lst, t_prop *new)
{
	t_prop	*start;

	start = *lst;
	if (start)
	{
		while (start->link && start->link != NULL)
		{
			start = start->link;
		}
		start->link = new;
		new->link = NULL;
	}
	else
	{
		*lst = new;
		(*lst)->link = NULL;
	}
}

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

t_prop	*ft_lastnode_ps(t_prop *stack)
{
	t_prop	*last;

	last = stack;
	while (last->link != NULL)
	{
		last = last->link;
		if (last->link == NULL)
			return (last);
	}
	return (last);
}

t_prop	*find_mini_node(t_prop **stack)
{
	t_prop	*head;
	t_prop	*mini_node;
	int		key;

	head = *stack;
	mini_node = NULL;
	key = 0;
	while (head)
	{
		if (!key || (mini_node->index > head->index))
		{
			mini_node = head;
			key = 1;
		}
		head = head->link;
	}
	// printf(" data = %d index = %d \n", mini_node->data, mini_node->index);
	return (mini_node);
}

// t_prop	*ft_lstlast_ps(t_prop *head)
// {
// 	t_prop	*tmp;

// 	tmp = head;
// 	while (tmp->link)
// 	{
// 		tmp = tmp->link;
// 		if (tmp->link == NULL)
// 			return (tmp);
// 	}
// 	return (tmp);
// }

// // Adds the specified node to a stack (list) making it the last node
// void	ft_lstadd_back_ps(t_prop **stack, t_prop *new)
// {
// 	t_prop	*n;

// 	if (*stack)
// 	{
// 		n = ft_lstlast_ps(*stack);
// 		n->link = new;
// 		new->link = NULL;
// 	}
// 	else
// 	{
// 		*stack = new;
// 		(*stack)->link = NULL;
// 	}
// }

void	printlist(t_prop *stack_a)
{
	t_prop	*tmp;

	tmp = stack_a;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->data, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->link;
	}
}
