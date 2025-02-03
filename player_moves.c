/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:41:19 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/09 15:48:16 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hit_w(t_vars *vars)
{
	update_exit('w', vars);
	update_player('w', vars);
	if (vars->matrix[vars->player.y][vars->player.x] == '1')
		vars->player.y++;
	else
	{
		mlx_clear_window(vars->mlx, vars->win);
		if (vars->matrix[vars->player.y][vars->player.x] == 'C')
			vars->coins--;
		if (vars->matrix[vars->player.y][vars->player.x] == 'E')
			vars->matrix[vars->player.y][vars->player.x] = 'F';
		else
			vars->matrix[vars->player.y][vars->player.x] = 'P';
		if (vars->matrix[vars->player.y + 1][vars->player.x] == 'F')
			vars->matrix[vars->player.y + 1][vars->player.x] = 'E';
		else if (vars->matrix[vars->player.y + 1][vars->player.x] != '1' || \
			vars->matrix[vars->player.y + 1][vars->player.x] != 'E')
			vars->matrix[vars->player.y + 1][vars->player.x] = '0';
		ft_printf("Moves: %i\n", vars->moves);
		vars->moves++;
		draw_map(vars);
	}
}

void	hit_s(t_vars *vars)
{
	update_exit('s', vars);
	update_player('s', vars);
	if (vars->matrix[vars->player.y][vars->player.x] == '1')
		vars->player.y--;
	else
	{
		mlx_clear_window(vars->mlx, vars->win);
		if (vars->matrix[vars->player.y][vars->player.x] == 'C')
			vars->coins--;
		if (vars->matrix[vars->player.y][vars->player.x] == 'E')
			vars->matrix[vars->player.y][vars->player.x] = 'F';
		else
			vars->matrix[vars->player.y][vars->player.x] = 'P';
		if (vars->matrix[vars->player.y - 1][vars->player.x] == 'F')
			vars->matrix[vars->player.y - 1][vars->player.x] = 'E';
		else if (vars->matrix[vars->player.y - 1][vars->player.x] != '1' || \
			vars->matrix[vars->player.y - 1][vars->player.x] != 'E')
			vars->matrix[vars->player.y - 1][vars->player.x] = '0';
		ft_printf("Moves: %i\n", vars->moves);
		vars->moves++;
		draw_map(vars);
	}
}

void	hit_d(t_vars *vars)
{
	update_exit('d', vars);
	update_player('d', vars);
	if (vars->matrix[vars->player.y][vars->player.x] == '1')
		vars->player.x--;
	else
	{
		mlx_clear_window(vars->mlx, vars->win);
		if (vars->matrix[vars->player.y][vars->player.x] == 'C')
			vars->coins--;
		if (vars->matrix[vars->player.y][vars->player.x] == 'E')
			vars->matrix[vars->player.y][vars->player.x] = 'F';
		else
			vars->matrix[vars->player.y][vars->player.x] = 'P';
		if (vars->matrix[vars->player.y][vars->player.x - 1] == 'F')
			vars->matrix[vars->player.y][vars->player.x - 1] = 'E';
		else if (vars->matrix[vars->player.y][vars->player.x - 1] != '1' || \
			vars->matrix[vars->player.y][vars->player.x - 1] != 'E')
			vars->matrix[vars->player.y][vars->player.x - 1] = '0';
		ft_printf("Moves: %i\n", vars->moves);
		vars->moves++;
		draw_map(vars);
	}
}

void	hit_a(t_vars *vars)
{
	update_exit('a', vars);
	update_player('a', vars);
	if (vars->matrix[vars->player.y][vars->player.x] == '1')
		vars->player.x++;
	else
	{
		mlx_clear_window(vars->mlx, vars->win);
		if (vars->matrix[vars->player.y][vars->player.x] == 'C')
			vars->coins--;
		if (vars->matrix[vars->player.y][vars->player.x] == 'E')
			vars->matrix[vars->player.y][vars->player.x] = 'F';
		else
			vars->matrix[vars->player.y][vars->player.x] = 'P';
		if (vars->matrix[vars->player.y][vars->player.x + 1] == 'F')
			vars->matrix[vars->player.y][vars->player.x + 1] = 'E';
		else if (vars->matrix[vars->player.y][vars->player.x + 1] != '1' || \
			vars->matrix[vars->player.y][vars->player.x + 1] != 'E')
			vars->matrix[vars->player.y][vars->player.x + 1] = '0';
		ft_printf("Moves: %i\n", vars->moves);
		vars->moves++;
		draw_map(vars);
	}
}
