/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:45:48 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/06 17:57:42 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw(t_vars *vars, char c, int y, int x)
{
	if (c == '1')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->img.wall, x * 32, y * 32);
	if (c == '0')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->img.bg, x * 32, y * 32);
	if (c == 'F')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->img.pne, x * 32, y * 32);
	if (c == 'C')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->img.token, x * 32, y * 32);
	if (c == 'P')
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->img.player, x * 32, y * 32);
}

static void	draw_exit(t_vars *vars, int y, int x)
{
	if (vars->coins == 0)
	{
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->img.exit_o, x * 32, y * 32);
		vars->endgame = 1;
	}
	else
		mlx_put_image_to_window
			(vars->mlx, vars->win, vars->img.exit_c, x * 32, y * 32);
}

int	draw_map(t_vars *vars)
{
	int	y;
	int	x;

	vars->endgame = 0;
	y = 0;
	x = 0;
	while (vars->matrix[y])
	{
		while (vars->matrix[y][x])
		{
			if (vars->matrix[y][x] == '1' || vars->matrix[y][x] == 'F' || \
				vars->matrix[y][x] == '0' || vars->matrix[y][x] == 'P' || \
				vars->matrix[y][x] == 'C')
				draw(vars, vars->matrix[y][x], y, x);
			else if (vars->matrix[y][x] == 'E')
				draw_exit(vars, y, x);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
