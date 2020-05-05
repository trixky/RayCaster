#include "cub3d.h"

void	ft_x_object(t_all *all, t_obj *x_tp)
{
	if (x_tp->length < all->fsc.x_lenght &&
			x_tp->length < all->fsc.y_lenght)
	{
		x_tp->width =
		(OBJECT_WIDTH / x_tp->length) * all->data.window_width;
		x_tp->height =
		(OBJECT_HEIGHT / x_tp->length) * all->data.window_width;
		if (x_tp->pos_y > all->player.pos_y)
		{
			if (x_tp->pos_x > all->player.pos_x)
				ft_x_object_1(all, x_tp);
			else
				ft_x_object_2(all, x_tp);
		}
		else
		{
			if (x_tp->pos_x > all->player.pos_x)
				ft_x_object_3(all, x_tp);
			else
				ft_x_object_4(all, x_tp);
		}
	}
}

void	ft_x_object_1(t_all *all, t_obj *x_tp)
{
	ft_x_object_1_dir(all, x_tp);
	if (x_tp->width / 2 > ft_absolute_float(x_tp->o_ray))
	{
		x_tp->end = (int)((all->data.window_height / 2) +
		(all->data.window_width / (x_tp->length) / 2));
		x_tp->start = x_tp->end - (int)x_tp->height;
		x_tp->index = x_tp->start;
		while (x_tp->index < x_tp->end &&
			x_tp->index < all->data.window_height)
		{
			if (x_tp->w_ob->sprite_data[ft_limit(((int)((((x_tp->width / 2) +
			(-x_tp->o_ray)) / x_tp->width) * x_tp->w_ob->width) +
			(int)((float)(x_tp->index - x_tp->start) / (float)(x_tp->end -
			x_tp->start) * (float)x_tp->w_ob->height) * x_tp->w_ob->width),
			x_tp->w_ob->size)] != 0)
				all->data.screen_data[ft_antiseg_leave_window(all->data.x_ray +
			x_tp->index * all->data.window_width, all->data.max_screen_pix)] =
			x_tp->w_ob->sprite_data[ft_limit(((int)((((x_tp->width / 2) +
			(-x_tp->o_ray)) / x_tp->width) * x_tp->w_ob->width) +
			(int)((float)(x_tp->index - x_tp->start) / (float)(x_tp->end -
			x_tp->start) * (float)x_tp->w_ob->height) * x_tp->w_ob->width),
			x_tp->w_ob->size)];
			x_tp->index++;
		}
	}
}

void	ft_x_object_2(t_all *all, t_obj *x_tp)
{
	ft_x_object_2_dir(all, x_tp);
	if (x_tp->width / 2 > ft_absolute_float(x_tp->o_ray))
	{
		x_tp->end = (int)((all->data.window_height / 2) +
		(all->data.window_width / (x_tp->length) / 2));
		x_tp->start = x_tp->end - (int)x_tp->height;
		x_tp->index = x_tp->start;
		while (x_tp->index < x_tp->end &&
			x_tp->index < all->data.window_height)
		{
			if (x_tp->w_ob->sprite_data[ft_limit(((int)((((x_tp->width / 2) +
			-(x_tp->o_ray)) / x_tp->width) * x_tp->w_ob->width) +
			(int)((float)(x_tp->index - x_tp->start) / (float)(x_tp->end -
			x_tp->start) * (float)x_tp->w_ob->height) * x_tp->w_ob->width),
			x_tp->w_ob->size)] != 0)
				all->data.screen_data[ft_antiseg_leave_window(all->data.x_ray +
			x_tp->index * all->data.window_width,
			all->data.max_screen_pix)] = x_tp->w_ob->sprite_data[ft_limit(
			((int)((((x_tp->width / 2) + -(x_tp->o_ray)) / x_tp->width) *
			x_tp->w_ob->width) + (int)((float)(x_tp->index - x_tp->start) /
			(float)(x_tp->end - x_tp->start) * (float)x_tp->w_ob->height)
			* x_tp->w_ob->width), x_tp->w_ob->size)];
			x_tp->index++;
		}
	}
}

void	ft_x_object_3(t_all *all, t_obj *x_tp)
{
	ft_x_object_3_dir(all, x_tp);
	if (x_tp->width / 2 > ft_absolute_float(x_tp->o_ray))
	{
		x_tp->end = (int)((all->data.window_height / 2) +
		(all->data.window_width / (x_tp->length) / 2));
		x_tp->start = x_tp->end - (int)x_tp->height;
		x_tp->index = x_tp->start;
		while (x_tp->index < x_tp->end &&
			x_tp->index < all->data.window_height)
		{
			if (x_tp->w_ob->sprite_data[ft_limit(((int)((((x_tp->width / 2) +
			-(x_tp->o_ray)) / x_tp->width) * x_tp->w_ob->width) +
			(int)((float)(x_tp->index - x_tp->start) / (float)(x_tp->end -
			x_tp->start) * (float)x_tp->w_ob->height) * x_tp->w_ob->width),
			x_tp->w_ob->size)] != 0)
				all->data.screen_data[ft_antiseg_leave_window(all->data.x_ray +
			x_tp->index * all->data.window_width, all->data.max_screen_pix)] =
			x_tp->w_ob->sprite_data[ft_limit(((int)((((x_tp->width / 2) +
			-(x_tp->o_ray)) / x_tp->width) * x_tp->w_ob->width) +
			(int)((float)(x_tp->index - x_tp->start) / (float)(x_tp->end -
			x_tp->start) * (float)x_tp->w_ob->height) * x_tp->w_ob->width),
			x_tp->w_ob->size)];
			x_tp->index++;
		}
	}
}

void	ft_x_object_4(t_all *all, t_obj *x_tp)
{
	ft_x_object_4_dir(all, x_tp);
	if (x_tp->width / 2 > ft_absolute_float(x_tp->o_ray))
	{
		x_tp->end = (int)((all->data.window_height / 2) +
		(all->data.window_width / (x_tp->length) / 2));
		x_tp->start = x_tp->end - (int)x_tp->height;
		x_tp->index = x_tp->start;
		while (x_tp->index < x_tp->end &&
			x_tp->index < all->data.window_height)
		{
			if (x_tp->w_ob->sprite_data[ft_limit(((int)((((x_tp->width / 2) +
			(-x_tp->o_ray)) / x_tp->width) * x_tp->w_ob->width) +
			(int)((float)(x_tp->index - x_tp->start) / (float)(x_tp->end -
			x_tp->start) * (float)x_tp->w_ob->height) * x_tp->w_ob->width),
			x_tp->w_ob->size)] != 0)
				all->data.screen_data[ft_antiseg_leave_window(all->data.x_ray +
			x_tp->index * all->data.window_width, all->data.max_screen_pix)] =
			x_tp->w_ob->sprite_data[ft_limit(((int)((((x_tp->width / 2) +
			(-x_tp->o_ray)) / x_tp->width) * x_tp->w_ob->width) +
			(int)((float)(x_tp->index - x_tp->start) / (float)(x_tp->end -
			x_tp->start) * (float)x_tp->w_ob->height) * x_tp->w_ob->width),
			x_tp->w_ob->size)];
			x_tp->index++;
		}
	}
}
