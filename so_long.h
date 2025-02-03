/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:24:17 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/25 14:27:38 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// libraries

# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include "libft/libft.h"

// macros

// custom structs

typedef struct s_img
{
	void	*player;
	void	*token;
	void	*bg;
	void	*wall;
	void	*exit_c;
	void	*exit_o;
	void	*pne;
}		t_img;

typedef struct v_counter
{
	int	x;
	int	y;
}		t_counter;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		img;
	char		**matrix;
	t_counter	dim;
	t_counter	player;
	int			coins;
	int			moves;
	int			img_h;
	int			img_w;
	int			endgame;
}				t_vars;

// functions

void		handle_input(t_vars *vars);
int			check_map(char *map_matrix, t_vars *vars);
char		**create_matrix(char *map);
t_counter	map_dim(char **map);
int			check_path(char **map, t_vars *vars);
int			draw_map(t_vars *vars);
void		game_init(t_vars *vars, char *path);
int			ft_exit(t_vars *vars);
void		hit_w(t_vars *vars);
void		hit_s(t_vars *vars);
void		hit_a(t_vars *vars);
void		hit_d(t_vars *vars);
void		handle_input(t_vars *vars);
void		update_player(char key, t_vars *vars);
void		update_exit(char key, t_vars *vars);

#endif
