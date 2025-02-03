/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:32:40 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/25 14:33:48 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_win(t_vars *vars)
{
	if (vars->endgame == 1 && \
		vars->matrix[vars->player.y][vars->player.x] == 'E')
	{
		ft_printf("YOU WIN!\nThanks for playing!\n");
		ft_exit(vars);
	}
}

static void	movement(int keycode, t_vars *vars)
{
	if (keycode == XK_w || keycode == XK_Up)
	{
		vars->player.y--;
		check_win(vars);
		hit_w(vars);
	}
	else if (keycode == XK_s || keycode == XK_Down)
	{
		vars->player.y++;
		check_win(vars);
		hit_s(vars);
	}
	else if (keycode == XK_d || keycode == XK_Right)
	{
		vars->player.x++;
		check_win(vars);
		hit_d(vars);
	}
	else if (keycode == XK_a || keycode == XK_Left)
	{
		vars->player.x--;
		check_win(vars);
		hit_a(vars);
	}
}

static int	keystroke(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		ft_exit(vars);
	else
		movement(keycode, vars);
	return (0);
}

void	handle_input(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, keystroke, vars);
	mlx_hook(vars->win, 17, 1L << 17, ft_exit, vars);
}
//mlx_hook(vars->win, 9, 1L << 21, draw_map, vars);
