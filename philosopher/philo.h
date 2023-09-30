/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:43:14 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/09/30 21:33:12 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

# define RED "\033[0;31m"
# define RESET "\033[1;37m"

# define FALSE 0
# define TRUE 1

typedef struct s_philo
{
	int		n;
	int		i;
	int		eat_times;
	int		died;
	// struct	*s_data;
	// pthread_t			tid;
	// pthread_mutex_t	*left; // = fork[0] pthread_mutex_lock(left)
	// pthread_mutex_t *right; // =fork[1]
	// int left_fork_id; // = 0 pthread_mutex_lock(data->fork[left_fork_id])
	// int right_for_id; // = 1
}	t_philo;

typedef struct s_data
{
	int all_eaten; // =0, =1 -> while(philo[++i] && i < philonum){int eaten=0; if(philo[i].eaten == 5){eaten += 1}if(eaten == philonum) data.all_eaten = 1;}
	int died; // =0, =1 -> 
	int	philonum;
	int				number_of_eats;
	// pthread_t			*tid;
	int				tte;
	int				tts;
	int				ttd;
	pthread_mutex_t	*fork;
	t_philo	*philo;
}	t_data;

// checkers.c //
bool	ft_check_number(char *str);
bool	ft_check_params(int ac, char **av);

// utilities.c //
void	ft_print_message(void);

#endif

