/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_prop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:12:50 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/08/02 21:46:31 by ltian-ha         ###   ########.fr       */
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
	return (mini_node);
}

// void	printlist(t_prop *stack_a)
// {
// 	t_prop	*tmp;

// 	tmp = stack_a;
// 	while (tmp != NULL)
// 	{
// 		ft_putnbr_fd(tmp->data, 1);
// 		ft_putendl_fd("", 1);
// 		tmp = tmp->link;
// 	}
// }
