#include "cub3d.h"

int		ft_is_first_letter(char **line)
{
	if ((line[0][0] == 'R' && line[0][1] == ' ') ||
			(line[0][0] == 'N' && line[0][1] == 'O') ||
			(line[0][0] == 'S' && line[0][1] == 'O') ||
			(line[0][0] == 'W' && line[0][1] == 'E') ||
			(line[0][0] == 'E' && line[0][1] == 'A') ||
			(line[0][0] == 'S' && line[0][1] == ' ') ||
			(line[0][0] == 'F' && line[0][1] == ' ') ||
			(line[0][0] == 'C' && line[0][1] == ' ') ||
			(line[0][0] == '1') ||
			(line[0][0] == '\n') ||
			(line[0][0] == '\0'))
		return (TRUE);
	return (FALSE);
}

int		ft_parser_first_line(t_all *all, char **line, int fd, char *path_map)
{
	if (line[0][0] == 'R' && ft_parse_r(*line, all, NULL, NULL) == 1)
		return (ft_exit_parser(fd, &line));
	if (line[0][0] == 'N' && line[0][1] == 'O' && ft_parse_no(*line, all) == 1)
		return (ft_exit_parser(fd, &line));
	if (line[0][0] == 'S' && line[0][1] == 'O' && ft_parse_so(*line, all) == 1)
		return (ft_exit_parser(fd, &line));
	if (line[0][0] == 'W' && line[0][1] == 'E' && ft_parse_we(*line, all) == 1)
		return (ft_exit_parser(fd, &line));
	if (line[0][0] == 'E' && line[0][1] == 'A' && ft_parse_ea(*line, all) == 1)
		return (ft_exit_parser(fd, &line));
	if (line[0][0] == 'S' && line[0][1] != 'O' && ft_parse_s(*line, all) == 1)
		return (ft_exit_parser(fd, &line));
	if (line[0][0] == 'F' && ft_parse_f(*line, all) == 1)
		return (ft_exit_parser(fd, &line));
	if (line[0][0] == 'C' && ft_parse_c(*line, all) == 1)
		return (ft_exit_parser(fd, &line));
	if (line[0][0] == '1' && ft_parse_1(fd, path_map, line, all) == 1)
		return (ft_exit_parser(fd, &line));
	if (ft_is_first_letter(line) == FALSE)
		return (ft_exit_parser(fd, &line));
	free(*line);
	return (FALSE);
}

int		ft_parser(t_all *all, char *path_map)
{
	int		fd;
	char	**line;
	int		is_readed[8];
	int		readed;

	line = NULL;
	readed = 0;
	if ((fd = open(path_map, O_RDONLY)) < 0)
		return (ft_exit_parser(fd, &line));
	if ((line = malloc(sizeof(char *) * 1)) == NULL)
		return (ft_exit_parser(fd, &line));
	ft_init_is_readed(is_readed);
	while (get_next_line(fd, line) > FALSE)
		if (ft_parser_first_line(all, line, fd, path_map) == TRUE)
			return (TRUE);
	free(*line);
	*line = NULL;
	free(line);
	line = NULL;
	return (FALSE);
}
