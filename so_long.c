/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:52:48 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/20 11:55:14 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(char *map)
{
	int		fd;
	int		i;
	int		len;
	char	*buff;

	len = ft_strlen(map);
	if (map[len - 1] != 'r' || map[len - 2] != 'e' || map[len - 3] != 'b' \
		|| map[len - 4] != '.' || ft_strlen(ft_strchr(map, '/')) == 5 || \
		ft_strlen(map) == 4)
		return (-1);
	buff = malloc(1);
	fd = open(map, O_RDONLY);
	i = read(fd, buff, 1);
	if (i == 0)
		i = -1;
	if (fd != -1)
		close(fd);
	free(buff);
	return (i);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2 || check_file(argv[1]) == -1)
	{
		ft_printf("Error\nInvalid arguments or file\n");
		return (0);
	}
	if (check_map(argv[1], &vars) != -1)
	{
		game_init(&vars, argv[1]);
		handle_input(&vars);
		mlx_loop(vars.mlx);
	}
	else
		ft_printf("Error\nInvalid Map\n");
	return (0);
}
