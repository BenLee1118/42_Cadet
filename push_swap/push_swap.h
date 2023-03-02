/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:40:54 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/03/02 18:05:32 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

# define SUCCESS 0
# define FAILURE 1

void	ft_check_params(int ac, char **av);
long	ft_atoilong(const char *str);

#endif