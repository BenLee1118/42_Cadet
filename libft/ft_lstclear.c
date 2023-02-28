/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:43:07 by ltian-ha          #+#    #+#             */
/*   Updated: 2022/11/20 11:43:07 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*start;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		start = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = start;
	}
	*lst = NULL;
}
