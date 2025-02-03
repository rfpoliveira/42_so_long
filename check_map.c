/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:01:33 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/27 14:09:16 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map_line(char *s)
{
	int	i;

	i = 0;
	if (s[i++] != '1')
		return (-1);
	while (s[i] != '\n' && s[i])
	{
		if (s[i] != '1' && s[i] != '0' && s[i] != 'E' \
			&& s[i] != 'P' && s[i] != 'C')
			return (-1);
		i++;
	}
	i--;
	if (s[i] == '\n')
		i--;
	if (s[i] != '1')
		return (-1);
	return (0);
}

static int	check_map_topbot(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != '\n' && s[i] != '\0')
			return (-1);
		i++;
	}
	return (0);
}

static int	check_count(char **map_matrix)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map_matrix[i])
	{
		while (map_matrix[i][j])
		{
			if (map_matrix[i][j] == 'C')
				count += 10;
			else if (map_matrix[i][j] == 'E' || map_matrix[i][j] == 'P')
				count += 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (count % 10 != 2 || count / 10 < 1)
		return (-1);
	return (count / 10);
}

static int	check_map_util(char **map_matrix, int height, int i, t_vars *vars)
{
	while (i < height)
	{
		if (check_map_line(map_matrix[i]) == -1)
			return (-1);
		i++;
	}
	vars->coins = check_count(map_matrix);
	if (check_map_topbot(map_matrix[0]) == -1 \
		|| check_map_topbot(map_matrix[height - 1]) == -1 \
		|| check_count(map_matrix) == -1 || check_path(map_matrix, vars) == -1)
		return (-1);
	return (0);
}

int	check_map(char *map, t_vars *vars)
{
	int		i;
	int		height;
	char	**map_matrix;

	map_matrix = create_matrix(map);
	i = 1;
	height = 0;
	vars->coins = 0;
	while (map_matrix[height])
	{
		if (ft_strlen(map_matrix[height]) != ft_strlen(map_matrix[0]) || \
			ft_strlen(map_matrix[0]) == 0)
			return (matrix_free(map_matrix), -1);
		height++;
	}
	if (check_map_util(map_matrix, height, i, vars) == -1)
		return (matrix_free(map_matrix), -1);
	return (matrix_free(map_matrix), 0);
}
/*
int main (int argc, char **argv)
{
	argc = 0;
	char **maps = create_matrix(argv[1]);
	int i = check_map(maps);
	int j = 0;
	while (maps[j])
	{
		r_free(&maps[j]);
		j++;
	}
	free(maps);
	ft_printf("%i\n", i);
}*/
