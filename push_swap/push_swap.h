/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:40:54 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/03 16:03:15 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

# define SUCCESS 0
# define FAILURE 1

typedef struct s_prop
{
	int				data;
	char			**as;
	struct s_prop	*link;
	int				index;
}				t_prop;

void	ft_check_params(int ac, char **av, t_prop *prop);
long	ft_atoilong(const char *str);

/* t_prop functions */
t_prop	*ft_lstnew_ps(int a);
void	printlist(t_prop *stack_a);
void	ft_lstadd_back_ps(t_prop **lst, t_prop *new);

/* Index Arrange */
void	ft_index_arrange(t_prop **stack_a);

#endif