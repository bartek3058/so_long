/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:05:46 by brogalsk          #+#    #+#             */
/*   Updated: 2025/02/03 10:28:02 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_walls(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < (data->size_y / IMG_H))
	{
		if ((int)ft_strlen(data->map->map[y]) != data->size_x / IMG_W)
			handle_error(data, "Error\nmap has to be rectangular", 1);
		x = 0;
		while (x < (data->size_x / IMG_W))
		{
			if (data->map->map[y][x] != '0' && data->map->map[y][x] != '1' &&
				data->map->map[y][x] != 'C' && data->map->map[y][x] != 'P' &&
					data->map->map[y][x] != 'E')
				handle_error(data, "Error\nIncorrect\n", 1);
			else if (((y == 0) || (x == 0)) && data->map->map[y][x] != '1')
				handle_error(data, "Error\nmaps not close by walls\n", 1);
			else if ((y == (data->size_y / IMG_H -1)
					|| x == (data->size_x / IMG_W -1))
				&& data->map->map[y][x] != '1')
				handle_error(data, "Error\nmaps not close by walls\n", 1);
			x++;
		}
		y++;
	}
}

int	ft_count_c(char *s, char c)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (!s)
		return (-1);
	while (s && s[i])
	{
		if (s[i++] == c)
			x++;
	}
	return (x);
}

void	ft_check_content(t_data *data)
{
	int		y;
	int		exit;
	int		player;

	exit = 0;
	player = 0;
	data->map->diamonds = 0;
	y = 0;
	while (data->map->map && data->map->map[y])
	{
		exit += ft_count_c(data->map->map[y], 'E');
		player += ft_count_c(data->map->map[y], 'P');
		data->map->diamonds += ft_count_c(data->map->map[y], 'C');
		y++;
	}
	if (player != 1 || exit != 1)
		handle_error(data, "Error\nThere is an error in map/\n", 1);
	if (data->map->diamonds == 0)
		handle_error(data, "Error\nNo diamond to collect\n", 1);
}

void	ft_input_error(t_data *data, int argc)
{
	if (argc != 2)
	{
		handle_error(data, "Error\nUsage: './so_long map/map.ber'\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	validate_input(t_data *data, char **argv, int argc)
{
	int		fd;
	int		i;
	char	buffer[2];
	char	*temp;

	temp = NULL;
	ft_input_error(data, argc);
	i = 0;
	buffer[1] = '\0';
	fd = open(argv[1], O_RDONLY);
	help(buffer, data, temp, fd);
	if (data->size_x / IMG_H == i)
		handle_error(data, "Error\nWrong map dimensions", 1);
	ft_check_content(data);
	ft_check_walls(data);
}
