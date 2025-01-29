/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:05:21 by brogalsk          #+#    #+#             */
/*   Updated: 2025/01/29 13:05:23 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help(char buffer[2], t_data *data, char *temp, int fd)
{
	int	i;
	int	bytes;

	bytes = 1;
	i = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n' && buffer[0] != '\0')
		{
			if (data->map->map[i] == NULL)
				data->map->map[i] = ft_strdup("");
			temp = data->map->map[i];
			data->map->map[i] = ft_strjoin(data->map->map[i], buffer);
			free(temp);
		}
		else
			i++;
	}
}

void	handle_error(t_data *data, char *str, int num)
{
	if (num)
		free_double_pointer(data);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_initializer_helper(t_data *data)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./textures/player_left.xpm";
	data->img->player_left = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	if (!data->img->player_left)
		handle_error(data, "Error\nPlayer left file not found", 1);
	relative_path = "./textures/player_down.xpm";
	data->img->player_down = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	if (!data->img->player_down)
		handle_error(data, "Error\nPlayer down file not found", 1);
	relative_path = "./textures/player_right.xpm";
	data->img->player_right = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	if (!data->img->player_right)
		handle_error(data, "Error\nPlayer right file not found", 1);
	relative_path = "./textures/background.xpm";
	data->img->background = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	if (!data->img->background)
		handle_error(data, "Error\nBackground file not found", 1);
}

void	ft_initializer(t_data *data, t_map *map)
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	t_img	*img;

	data->map = map;
	img = malloc(sizeof(t_img));
	if (!img)
	{
		perror("Error\nmalloc failed/n");
		exit(EXIT_FAILURE);
	}
	data->img = img;
	relative_path = "textures/player_up.xpm";
	data->img->player_up = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	if (!data->img->player_up)
		handle_error(data, "Error\nPlayer up file not found", 1);
	ft_initializer_helper(data);
	data->counter = 0;
	data->collected = 0;
}
