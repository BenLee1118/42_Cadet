/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:45:26 by ltian-ha          #+#    #+#             */
/*   Updated: 2023/02/27 16:38:40 by ltian-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <time.h>

/* Struct to store and handle layout properties */
typedef struct s_prop
{
	int					num_row;
	int					num_col;
	int					num_exit;
	int					num_p1;
	int					num_gho;
	int					num_coll;
	char				**map;
	int					**visited;
	int					old_collections;
	void				*mlx;
	void				*wind;
	void				*gnd;
	void				*wall;
	void				*exit;
	void				*exit2;
	void				*exit3;
	void				*playerd;
	void				*playerr;
	void				*playerl;
	void				*playeru;
	void				*coin1;
	void				*coin2;
	void				*coin3;
	void				*ghost1;
	void				*ghost2;
	void				*ghost3;
	int					player_x;
	int					player_y;
	int					ghost_x;
	int					ghost_y;
	int					exitable;
	char				direction;
	int					coins_collected;
	int					steps_count;
	unsigned int		seed1;
	int					frame;
	void				*curexit;
	void				*curcoin;
	void				*curgho;
}				t_prop;

/* Struct to handle all possible layout errors */
typedef struct s_error
{
	int	inval_rowlen;
	int	inval_char;
	int	inval_n_exit;
	int	inval_n_player;
	int	inval_n_ghosts;
	int	inval_n_collect;
	int	inval_borders;
}				t_error;

/* Analysis towards the map and variables */
t_prop	assign_mapprop(void);
t_error	assign_maperr(void);
void	ft_readmap(int fd, t_error *map_error, t_prop *prop, char **map_sent);
void	ft_scan_map(char *str, t_error *map_error, t_prop *prop, int is_last);
int		error_params(char *str, char **map_str);
int		ft_map_error(t_error *map_error, char **map_str);

/* Basic checks to see if the correct file has been opened */
char	**inspect_params(int argc, char **argv, t_prop *prop);

/* Runs all map checker and builds map as a matrix */
char	**check_map(int fd, t_prop *prop);

/* Runs the map to check the path */
void	check_valid_path(t_prop prop);

/* Regular functions needed */
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strrchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, int tot_len);
char	*ft_strenlarge(char *s1, char *s2);
char	*ft_strdup(char *str, char *charset);
char	*get_next_line(int fd);
char	**ft_split(char *str, char *charset);
char	*ft_strrdup(const char *src);
char	*ft_itoa(int n);
void	ft_putstr(char *str);

/* Get Next Line Functions */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
void	ft_bzero(void *str, int n);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

/* Runs the game */
# ifndef BIT_SIZE
#  define BIT_SIZE 64
# endif

void	init_window(t_prop *prop);
void	init_images(t_prop *prop);
int		render_images(t_prop *prop);
void	init_player(t_prop *prop);
void	player_move(t_prop	*prop);
void	move_ghost(t_prop *prop, int direction);
void	hook_images(t_prop prop);
int		key_handlers(int key, t_prop *prop);
void	string_put(t_prop *prop);
void	game_lost(t_prop *prop);
int		draw_frames(t_prop *prop);
//int		keyrelease_handlers(t_prop *prop);

/* DEFINITION OF IMAGES */
# define PLAYERD "assests/Player.xpm"
# define PLAYERU "assests/Player4.xpm"
# define PLAYERL "assests/Player2.xpm"
# define PLAYERR "assests/Player3.xpm"
# define KELUAR "assests/exit.xpm"
# define KELUAR2 "assests/medchar.xpm"
# define KELUAR3 "assests/smallchar.xpm"
# define WALLL "assests/Wall.xpm"
# define COIN1 "assests/coin1.xpm"
# define COIN2 "assests/poke2.xpm"
# define COIN3 "assests/poke3.xpm"
# define GHOST1 "assests/ghost1.xpm"
# define GHOST2 "assests/ghost2.xpm"
# define GHOST3 "assests/ghost3.xpm"
# define GROUND "assests/Floor.xpm"

/* DEFINITION OF KEY */
# define ESC 53
# define UP	13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define SUCCESS 0
# define FAILURE 1

#endif