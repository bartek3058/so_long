#include "so_long.h"

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("---------------------------------------\n");
	ft_printf("|				LOSE !\n              |\n");
	ft_printf("|				TRY AGAIN             |\n");
	ft_printf("---------------------------------------\n");
	free_double_pointer(data);
	exit(EXIT_SUCCESS);
}

void	put_object(t_data *data, char *relative_path)
{
	int		img_width;
	int		img_height;

	data->map->object = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	if (!data->map->object)
		handle_error(data, "Error\nexit file not found", 1);
	mlx_put_image_to_window(data->mlx, data->win, data->map->object,
		(data->map->x * IMG_W), (data->map->y * IMG_H));
	mlx_destroy_image(data->mlx, data->map->object);
	data->map->object = NULL;
}

void	put_player(t_data *data)
{
	data->p_x = data->map->x;
	data->p_y = data->map->y;
	mlx_put_image_to_window(data->mlx, data->win, data->img->player_up,
		(data->p_x * IMG_W), (data->p_y * IMG_H));
}

void	create_map(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->size_y / IMG_H))
	{
		if (data->map->map[data->map->y][data->map->x] == 'P')
			put_player(data);
		else if (data->map->map[data->map->y][data->map->x] == '1')
			put_object(data, "./textures/wall.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'C')
			put_object(data, "./textures/collectable.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'E')
			put_object(data, "./textures/exit.xpm");
		if (data->map->x < (data->size_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}

void	calloc_failure(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}
