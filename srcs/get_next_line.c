#include "cub3d.h"

int		get_next_line(int fd, char **line)
{
	static t_st	sta = {.i = BUFFER_SIZE, .ret = BUFFER_SIZE, .last_fd = 0};

	if (fd < 0 || line == NULL)
		return (-1);
	ft_init_line_buffer_lu(&line, sta.buffer, &sta.lu);
	ft_fd_manager(fd, &sta.i, &sta.ret, &sta.last_fd);
	while (sta.i <= sta.ret && sta.buffer[sta.i] != '\n')
		if (sta.i == sta.ret && (sta.i = 0) == 0)
		{
			if ((sta.ret = read(fd, sta.buffer, BUFFER_SIZE)) < 0)
				return (-1);
			else if (sta.ret == 0)
			{
				sta.i = BUFFER_SIZE;
				sta.ret = BUFFER_SIZE;
				return (sta.lu);
			}
			continue;
		}
		else if ((sta.lu = 1))
			ft_add_char(line, sta.buffer[sta.i++]);
	if (++sta.i <= sta.ret)
		return (1);
	return (sta.lu);
}
