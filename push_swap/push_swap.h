/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:40:54 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/11 16:51:55 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdint.h>

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

/* Check Paramas */
void	ft_check_params(int ac, char **av, t_prop *prop);
void	ft_mssg(char *str);
void	ft_error_mssg(char *str);
long	ft_atoilong(const char *str);

/* Add and Sort */
int		ft_lstsize_ps(t_prop *lst);
void	ft_sort_stacks(t_prop **stack_a, t_prop **stack_b);
void	add_stack(int argc, t_prop **stack_a, t_prop *prop);

/* link list functions */
t_prop	*ft_lstnew_ps(int a);
void	printlist(t_prop *stack_a);
void	ft_lstadd_back_ps(t_prop **lst, t_prop *new);
t_prop	*ft_lastnode_ps(t_prop *stack);
t_prop	*find_mini_node(t_prop **stack);
void	ft_lstadd_front_ps(t_prop **lst, t_prop *new);

/* Index Arrange */
void	ft_index_arrange(t_prop **stack_a);

/* Sort for Algorythm */
void	ft_sort_algo(t_prop **stack_a, t_prop **stack_b, int size);
void	ft_sort_radix(t_prop **stack_a, t_prop **stack_b);

/* Operations */
int		ft_swap(t_prop **stack);
void	sa(t_prop **stack_a);
void	sb(t_prop **stack_b);
void	ss(t_prop **stack_a, t_prop **stack_b);
void	ra(t_prop **stack_a);

/* Second Operations */
void	rb(t_prop **stack_b);
void	rr(t_prop **stack_a, t_prop **stack_b);
void	rra(t_prop	**stack_a);
void	rrb(t_prop	**stack_b);
void	rrr(t_prop	**stack_a, t_prop	**stack_b);

/* Third Operations */
int		ft_rotation(t_prop **stack);
int		ft_rotation_rev(t_prop **stack);
int		ft_push(t_prop **dest, t_prop **src);
void	pa(t_prop **stack_a, t_prop **stack_b);
void	pb(t_prop **stack_a, t_prop **stack_b);
// void	pb(t_prop **stack_a, t_prop	**stack_b);
// void	pa(t_prop **stack_a, t_prop	**stack_b);

/* Utilitise */
int		ft_check_sort(t_prop **stack_a);
void	ft_obtain_value(t_prop	*prop, int *a, int *b, int *c);
int		find_mini_val(t_prop **stack_a, int i);
int		find_maxi_val(t_prop **stack_a, int i);
t_prop	*ft_free_node(t_prop **stack);
void	ft_free_stack(t_prop **stack);
void	ft_free_str(char **str);

/* Bonus */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		ft_strcmp(const char *s1, const char *s2);
char	*get_next_line(int fd);
void	ft_bzeroo(void *str, int n);
void	*ft_callocc(size_t count, size_t size);
int		ft_strlenn(const char *str);
char	*ft_strchrr(const char *s, int c);
char	*ft_strjoinn(char const *s1, char const *s2);
#endif