/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:05:41 by brogalsk          #+#    #+#             */
/*   Updated: 2025/01/29 13:05:43 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include <fcntl.h>

# define IMG_W 32
# define IMG_H 32
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UARROW 65362
# define LARROW 65361
# define DARROW 65364
# define RARROW 65363
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

typedef struct s_img
{
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*background;
}			t_img;

typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		diamonds;
}			t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	t_map	*map;
	t_img	*img;
}							t_data;

void	help(char buffer[2], t_data *data, char *temp, int fd);
void	put_background(t_data *data);
void	free_double_pointer(t_data *data);
void	ft_move(t_data *data, char pos, int dir);
void	ft_collect(t_data *data, char pos, int dir);
void	ft_player_move(t_data *data, char position, int direction);
void	check_path_of_collectables(t_data *data, int x, int y);
void	fill_visited(char ***visited, t_data *data);
void	put_object(t_data *data, char *relative_path);
void	put_player(t_data *data);
void	create_map(t_data *data);
void	handle_error(t_data *data, char *str, int num);
void	ft_initializer_helper(t_data *data);
void	ft_initializer(t_data *data, t_map *map);
void	winner(t_data *data);
void	check_filename(char *filename);
void	free_double_p(char ***s);
void	find_px_py(t_data *data);
void	window_size(t_data *data, char **argv);
void	calloc_failure(char *s);
void	ft_check_walls(t_data *data);
void	ft_check_content(t_data *data);
void	ft_input_error(t_data *data, int argc);
void	validate_input(t_data *data, char **argv, int argc);
void	check_path(t_data *data);
int		ft_count_c(char *s, char c);
int		ft_key_hook(int keycode, t_data *data);
int		e_valid_path(t_data *data, int x, int y, char **visited);
int		ft_count_lines(int fd, int x, int img_w);
int		ft_line_length(int fd);
int		ft_next(t_data *next);
int		main(int argc, char **argv);
int		c_valid_path(t_data *data, int x, int y, char **visited);
int		ft_exit(t_data *data);

#endif
