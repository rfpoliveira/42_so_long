/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:00:34 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/12/04 14:11:13 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_counter	map_dim(char **map)
{
	t_counter	map_dim;

	map_dim.x = 0;
	map_dim.y = 0;
	while (map[map_dim.y])
		map_dim.y++;
	while (map[map_dim.y - 1][map_dim.x])
		map_dim.x++;
	map_dim.x--;
	return (map_dim);
}
/*
int main (void)
{
	char** map = create_matrix("maps/test.ber");
	counter dim = map_dim(map);
	ft_printf("y: %i, x:%i\n", dim.y, dim.x);
	int i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	matrix_free(map);
}*/
