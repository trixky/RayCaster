#include "ray_caster.h"

void	ft_generate_ray_wall_x_cut(t_all *all, int y_start,
		int y_index, int y_end)
{
	int y_range;

	all->fsc.y_wall_touched =
	(all->fsc.x_lenght < all->fsc.y_lenght) ? 0 : all->fsc.y_wall_touched;
	y_start = all->data.window_height / 2 - ((all->data.window_width /
	(all->fsc.x_lenght) / 2));
	y_index = y_start;
	y_end = all->data.window_height / 2 + ((all->data.window_width /
	(all->fsc.x_lenght) / 2));
	y_range = y_end - y_start;
	if ((int)y_index < 0)
		y_index = (int)0;
	if (all->fsc.x_wall_touched != 0)
	{
		while (y_index < y_end && y_index < all->data.window_height)
		{
			all->data.screen_data[all->data.x_ray + y_index *
			all->data.window_width] = all->ptr_wall_x->sprite_data[(int)(
				all->fsc.x_ray_of_wall * (float)all->ptr_wall_x->width) +
				(((y_index - y_start) * all->ptr_wall_x->height) /
				(y_end - y_start)) * all->ptr_wall_x->height];
			y_index++;
		}
	}
}

void	ft_generate_ray_wall_y_cut(t_all *all, int y_start,
		int y_index, int y_end)
{
	int y_range;

	y_start = all->data.window_height / 2 - ((all->data.window_width /
	(all->fsc.y_lenght) / 2));
	y_index = y_start;
	y_end = all->data.window_height / 2 + ((all->data.window_width /
	(all->fsc.y_lenght) / 2));
	y_range = y_end - y_start;
	if ((int)y_index < 0)
		y_index = (int)0;
	if (all->fsc.y_wall_touched != 0)
	{
		while (y_index < y_end && y_index < all->data.window_height)
		{
			all->data.screen_data[all->data.x_ray + y_index *
			all->data.window_width] = all->ptr_wall_y->sprite_data[(int)(
				all->fsc.y_ray_of_wall * (float)all->ptr_wall_y->width) +
				(((y_index - y_start) * all->ptr_wall_y->height) / (y_end -
				y_start)) * all->ptr_wall_y->height];
			y_index++;
		}
	}
}

void	ft_generate_ray_wall(t_all *all)
{
	int y_start;
	int y_index;
	int y_end;

	y_start = 0;
	y_index = 0;
	y_end = 0;
	ft_generate_ray_wall_x_cut(all, y_start, y_index, y_end);
	ft_generate_ray_wall_y_cut(all, y_start, y_index, y_end);
}
