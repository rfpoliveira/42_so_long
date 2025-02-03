/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:26:57 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/11 14:29:32 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player(char key, t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.player);
	if (key == 'w')
		vars->img.player = mlx_xpm_file_to_image
			(vars->mlx, "assets/images/pb.xpm", &vars->img_w, &vars->img_h);
	if (key == 'd')
		vars->img.player = mlx_xpm_file_to_image
			(vars->mlx, "assets/images/pr.xpm", &vars->img_w, &vars->img_h);
	if (key == 'a' || key == 's')
		vars->img.player = mlx_xpm_file_to_image
			(vars->mlx, "assets/images/pl.xpm", &vars->img_w, &vars->img_h);
}

void	update_exit(char key, t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.pne);
	if (key == 'w')
		vars->img.pne = mlx_xpm_file_to_image
			(vars->mlx, "assets/images/pneb.xpm", &vars->img_w, &vars->img_h);
	if (key == 'd')
		vars->img.pne = mlx_xpm_file_to_image
			(vars->mlx, "assets/images/pner.xpm", &vars->img_w, &vars->img_h);
	if (key == 'a' || key == 's')
		vars->img.pne = mlx_xpm_file_to_image
			(vars->mlx, "assets/images/pnel.xpm", &vars->img_w, &vars->img_h);
}
