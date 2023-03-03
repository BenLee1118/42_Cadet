/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_prop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:12:50 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/03 17:58:07 by ltian-ha         ###   ########.fr       */
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
