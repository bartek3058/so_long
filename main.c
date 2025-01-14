#include "so_long.h"

void	winner(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img->player_up);
	mlx_destroy_image(data->mlx, data->img->player_down);
	mlx_destroy_image(data->mlx, data->img->player_left);
	mlx_destroy_image(data->mlx, data->img->player_right);
	mlx_destroy_image(data->mlx, data->img->background);
	ft_printf("---------------------------------------\n");
	ft_printf("|			CONGRATULATIONS!!         |\n");
	ft_printf("|				YOU WON !!            |\n");
	ft_printf("|			YOU WIN IN %d MOVES       |\n", data->counter);
	ft_printf("---------------------------------------\n");
	free_double_pointer(data);
	exit(EXIT_SUCCESS);
}

int	ft_key_hook(int keycode, t_data *data)
{
	ft_printf("Keycode pressed: %d\n", keycode);
	if (keycode == ESC)
		ft_exit(data);
	else if (keycode == W || keycode == UARROW)
		ft_move(data, 'y', UP);
	else if (keycode == A || keycode == LARROW)
		ft_move(data, 'x', LEFT);
	else if (keycode == S || keycode == DARROW)
		ft_move(data, 'y', DOWN);
	else if (keycode == D || keycode == RARROW)
		ft_move(data, 'x', RIGHT);
	if (data->map->map[data->p_y][data->p_x] == 'E')
		winner(data);
	return (0);
}

void	check_filename(char *file_name)
{
	file_name = file_name + (ft_strlen(file_name) -4);
	if (ft_strncmp(file_name, ".ber", 4))
	{
		write(2, "Error\n Wrong file extension", 28);
		exit(1);
	}
}

int	ft_next(t_data *data)
{
	put_background(data);
	create_map(data);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->win, ft_key_hook, data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	window_size(&data, argv);
	check_filename(argv[1]);
	map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	if (!map.map)
		calloc_failure("Error\ncalloc failed\n");
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		perror("Error\nprogram initialization failes\n");
		exit(EXIT_FAILURE);
	}
	ft_initializer(&data, &map);
	validate_input(&data, argv, argc);
	check_path(&data);
	data.win = mlx_new_window(data.mlx, data.size_x, data.size_y, "brogalsk");
	ft_next(&data);
	mlx_loop(data.mlx);
	perror("Error\nProgramme failed to loop\n");
	exit(EXIT_FAILURE);
}
