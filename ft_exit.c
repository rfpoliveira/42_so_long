/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:30:06 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/09 11:34:26 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_vars *vars)
{
	matrix_free(vars->matrix);
	mlx_destroy_image(vars->mlx, vars->img.player);
	mlx_destroy_image(vars->mlx, vars->img.bg);
	mlx_destroy_image(vars->mlx, vars->img.token);
	mlx_destroy_image(vars->mlx, vars->img.wall);
	mlx_destroy_image(vars->mlx, vars->img.exit_c);
	mlx_destroy_image(vars->mlx, vars->img.exit_o);
	mlx_destroy_image(vars->mlx, vars->img.pne);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}
