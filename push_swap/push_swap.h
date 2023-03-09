/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:40:54 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/09 20:49:35 by ltian-ha         ###   ########.fr       */
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
	char			**as;
	int				ac;
	int				data;
	struct s_prop	*link;
	int				index;
}				t_prop;

void	ft_check_params(int ac, char **av, t_prop *prop);
void	ft_error_mssg(char *str);
long	ft_atoilong(const char *str);

/* link list functions */
t_prop	*ft_lstnew_ps(int a);
void	printlist(t_prop *stack_a);
void	ft_lstadd_back_ps(t_prop **lst, t_prop *new);
int		ft_lstsize_ps(t_prop *lst);
t_prop	*ft_lastnode_ps(t_prop **stack);
t_prop	*find_mini_node(t_prop **stack);
void	ft_lstadd_front_ps(t_prop **lst, t_prop *new);

/* Index Arrange */
void	ft_index_arrange(t_prop **stack_a);

/* Sort for Algorythm */
void	ft_sort_algo(t_prop **stack_a, t_prop **stack_b, int size);
void	ft_sort_radix(t_prop **stack_a, t_prop **stack_b);

/* Operations */
void	sa(t_prop **stack_a);
void	ra(t_prop **stack_a);
void	rb(t_prop **stack_b);
void	rr(t_prop **stack_a, t_prop **stack_b);
void	rra(t_prop	**stack_a);
void	rrb(t_prop	**stack_b);
void	rrr(t_prop	**stack_a, t_prop	**stack_b);
// void	pb(t_prop **stack_a, t_prop	**stack_b);
// void	pa(t_prop **stack_a, t_prop	**stack_b);
int	pa(t_prop **stack_a, t_prop **stack_b);
int	pb(t_prop **stack_a, t_prop **stack_b);

/* Utilitise */
int		ft_check_sort(t_prop **stack_a);
void	ft_obtain_value(t_prop	*prop, int *a, int *b, int *c);
int		find_mini_val(t_prop **stack_a, int i);
int		find_maxi_val(t_prop **stack_a, int i);
t_prop	*ft_free_node(t_prop **stack);

#endif