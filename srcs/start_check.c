#include "cub3d.h"

void	ft_check_parsing(t_all *all)
{
	if (all->player.direction == -2)
		ft_close(all, 2);
	if (all->data.window_width == 0 || all->data.window_height == 0 ||
	all->data.c_color == -1 || all->data.f_color == -1)
		ft_close(all, 3);
	if (all->map.array == NULL ||
			all->data.path_texture_no == NULL ||
			all->data.path_texture_so == NULL ||
			all->data.path_texture_we == NULL ||
			all->data.path_texture_ea == NULL ||
			all->data.path_texture_s == NULL)
		ft_close(all, 4);
}

void	ft_recize_window(t_all *all)
{
	if (all->data.window_width > MAX_WIDTH)
		all->data.window_width = MAX_WIDTH;
	if (all->data.window_height > MAX_HEIGHT)
		all->data.window_height = MAX_HEIGHT;
}

void	ft_check_all_path(t_all *all)
{
	int fd;

	if ((fd = open(all->data.path_texture_no, O_RDONLY)) < FALSE)
		ft_close(all, 7);
	close(fd);
	if ((fd = open(all->data.path_texture_so, O_RDONLY)) < FALSE)
		ft_close(all, 7);
	close(fd);
	if ((fd = open(all->data.path_texture_we, O_RDONLY)) < FALSE)
		ft_close(all, 7);
	close(fd);
	if ((fd = open(all->data.path_texture_ea, O_RDONLY)) < FALSE)
		ft_close(all, 7);
	close(fd);
	if ((fd = open(all->data.path_texture_s, O_RDONLY)) < FALSE)
		ft_close(all, 7);
	close(fd);
}
