/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:46:40 by rpedrosa          #+#    #+#             */
/*   Updated: 2024/11/28 11:52:33 by rpedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_height(char *map)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open(map, O_RDONLY);
	tmp = get_next_line(fd);
	i = 1;
	while (tmp)
	{
		r_free(&tmp);
		tmp = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

char	**create_matrix(char *map)
{
	char	**save;
	int		fd;
	int		i;

	i = get_height(map);
	save = ft_calloc(i + 1, sizeof(char **));
	i = 1;
	fd = open(map, O_RDONLY);
	save[0] = get_next_line(fd);
	while (save[i - 1])
		save[i++] = get_next_line(fd);
	close(fd);
	return (save);
}
/*
int main (int argc, char **argv)
{
	argc = 0;
	char	**save = create_matrix(argv[1]);
	int i = 0;
	while (save[i])
	{
		ft_printf("%s", save[i]);
		r_free(&save[i]);
		i++;
	}
	free(save);
}*/
