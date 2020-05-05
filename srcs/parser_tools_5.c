#include "ray_caster.h"

int		ft_check_border(t_all *all)
{
	int y;
	int x;

	y = 0;
	while (y < all->map.height)
	{
		if (all->map.array[y][all->map.width - 1] != 1)
			return (TRUE);
		if (y == 0 || y == all->map.height - 1)
		{
			x = 0;
			while (x < all->map.width)
			{
				if (all->map.array[y][x] != 1)
					return (TRUE);
				x++;
			}
		}
		y++;
	}
	return (FALSE);
}

int		ft_parse_1_1_1_1(char **line, t_all *all, int fd, int first)
{
	int i;
	int ret;

	i = 1;
	while (first == '1')
	{
		free(*line);
		*line = NULL;
		if ((ret = get_next_line(fd, line)) < 0)
			return (ft_free_and_return((void **)line,
			(void **)&line, NULL, NULL));
			if ((all->map.array[i] = malloc(sizeof(int) *
					all->map.width)) == NULL)
			return (ft_free_and_return((void **)line,
			(void **)&line, NULL, NULL));
			if (ft_set_line_map(all, *line, all->map.array[i]) == TRUE)
			return (TRUE);
		first = **line;
		i++;
	}
	return (FALSE);
}

int		ft_parse_1_1_1(char **line, t_all *all, int fd)
{
	int		ret;
	char	first;

	if ((ret = get_next_line(fd, line)) <= 0)
		return (ft_free_and_return((void **)line, (void **)&line, NULL, NULL));
	first = '@';
	while (first != '1')
	{
		free(*line);
		*line = NULL;
		if ((ret = get_next_line(fd, line)) <= 0)
			return (ft_free_and_return((void **)line,
			(void **)&line, NULL, NULL));
			first = **line;
	}
	if ((all->map.array[0] = malloc(sizeof(int) * all->map.width)) == NULL)
		return (ft_free_and_return((void **)line, (void **)&line, NULL, NULL));
	if (ft_set_line_map(all, *line, all->map.array[0]) == TRUE)
		return (TRUE);
	if (ft_parse_1_1_1_1(line, all, fd, first) == TRUE)
		return (TRUE);
	return (FALSE);
}

int		ft_parse_1_1(char **line, char *path_map, t_all *all)
{
	int		fd;

	if ((all->map.array = malloc(sizeof(int *) *
			(all->map.height + 1))) == NULL)
		return (ft_free_and_return((void **)line, (void **)&line, NULL, NULL));
	ft_init_array(all);
	if ((fd = open(path_map, O_RDONLY)) < 0)
		return (TRUE);
	free(*line);
	*line = NULL;
	if (ft_parse_1_1_1(line, all, fd) == TRUE)
		return (TRUE);
	return (FALSE);
}

int		ft_parse_1(int fd, char *path_map, char **line, t_all *all)
{
	int space;

	all->map.width = 0;
	all->map.height = 1;
	space = 0;
	if (ft_im_last_readed(all) == FALSE)
		return (TRUE);
	while (line[0][all->map.width + space])
	{
		if (line[0][all->map.width + space] == '1')
			all->map.width++;
		else if (line[0][all->map.width + space] == ' ')
			space++;
		else
			return (TRUE);
	}
	*line = ft_free(*line);
	while (get_next_line(fd, line) > FALSE)
	{
		if (**line != '1')
			return (TRUE);
		all->map.height++;
		*line = ft_free(*line);
	}
	return ((ft_parse_1_1(line, path_map, all) || ft_check_border(all)));
}
