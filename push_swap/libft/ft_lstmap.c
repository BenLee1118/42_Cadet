/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:41:57 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/11/20 11:41:57 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new;

	if (!lst)
		return (0);
	new = 0;
	while (lst)
	{
		start = ft_lstnew(f(lst->content));
		if (!start)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, start);
		lst = lst->next;
	}
	return (new);
}
