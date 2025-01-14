#include "so_long.h"

void	free_double_p(char ***s)
{
	int		i;

	if (!s || !(*s))
		return ;
	i = 0;
	while ((*s)[i])
		i++;
	i--;
	while (i >= 0)
	{
		free((*s)[i]);
		(*s)[i] = NULL;
		i--;
	}
	free((*s));
	*s = NULL;
}

void	find_px_py(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'P')
			{
				data->p_x = x;
				data->p_y = y;
			}
			x++;
		}
		y++;
	}
}

int	ft_line_length(int fd)
{
	char	buffer[1];
	int		length;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break ;
	}
	return (length);
}

int	ft_count_lines(int fd, int x, int img_w)
{
	char	*line;
	int		linecount;

	linecount = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((int)ft_strlen(line) < x / img_w
			|| (ft_strlen(line) == 1 && *line != '\n'))
		{
			free(line);
			ft_printf("Error\nwrong map dimension\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			free(line);
			linecount++;
		}
	}
	return (linecount);
}

void	window_size(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nInvalid map_path/map\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		printf("Error\nmap should be .ber\n");
		exit(EXIT_FAILURE);
	}
	data->size_x = (ft_line_length(fd) * IMG_W);
	data->size_y = (ft_count_lines(fd, data->size_x, IMG_W) * IMG_H);
}
