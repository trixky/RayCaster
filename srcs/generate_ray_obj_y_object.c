#include "ray_caster.h"

void	ft_y_object(t_all *all, t_obj *y_tp)
{
	if (y_tp->length < all->fsc.x_lenght &&
			y_tp->length < all->fsc.y_lenght)
	{
		y_tp->width =
		(OBJECT_WIDTH / y_tp->length) * all->data.window_width;
		y_tp->height =
		(OBJECT_HEIGHT / y_tp->length) * all->data.window_width;
		if (y_tp->pos_y > all->player.pos_y)
		{
			if (y_tp->pos_x > all->player.pos_x)
				ft_y_object_5(all, y_tp);
			else
				ft_y_object_6(all, y_tp);
		}
		else
		{
			if (y_tp->pos_x > all->player.pos_x)
				ft_y_object_7(all, y_tp);
			else
				ft_y_object_8(all, y_tp);
		}
	}
}

void	ft_y_object_5(t_all *all, t_obj *y_tp)
{
	ft_y_object_5_dir(all, y_tp);
	if (y_tp->width / 2 > ft_absolute_float(y_tp->o_ray))
	{
		y_tp->end = (int)((all->data.window_height / 2) +
		(all->data.window_width / (y_tp->length) / 2));
		y_tp->start = y_tp->end - (int)y_tp->height;
		y_tp->index = y_tp->start;
		while (y_tp->index < y_tp->end &&
			y_tp->index < all->data.window_height)
		{
			if (y_tp->w_ob->sprite_data[ft_limit(((int)((((y_tp->width / 2) +
			-(y_tp->o_ray)) / y_tp->width) * y_tp->w_ob->width) +
			(int)((float)(y_tp->index - y_tp->start) / (float)(y_tp->end -
			y_tp->start) * (float)y_tp->w_ob->height) * y_tp->w_ob->width),
			y_tp->w_ob->size)] != 0)
				all->data.screen_data[ft_antiseg_leave_window(all->data.x_ray +
			y_tp->index * all->data.window_width, all->data.max_screen_pix)] =
			y_tp->w_ob->sprite_data[ft_limit(((int)((((y_tp->width / 2) +
			-(y_tp->o_ray)) / y_tp->width) * y_tp->w_ob->width) +
			(int)((float)(y_tp->index - y_tp->start) / (float)(y_tp->end -
			y_tp->start) * (float)y_tp->w_ob->height) * y_tp->w_ob->width),
			y_tp->w_ob->size)];
			y_tp->index++;
		}
	}
}

void	ft_y_object_6(t_all *all, t_obj *y_tp)
{
	ft_y_object_6_dir(all, y_tp);
	if (y_tp->width / 2 > ft_absolute_float(y_tp->o_ray))
	{
		y_tp->end = (int)((all->data.window_height / 2) +
		(all->data.window_width / (y_tp->length) / 2));
		y_tp->start = y_tp->end - (int)y_tp->height;
		y_tp->index = y_tp->start;
		while (y_tp->index < y_tp->end &&
			y_tp->index < all->data.window_height)
		{
			if (y_tp->w_ob->sprite_data[ft_limit(((int)((((y_tp->width / 2) +
			y_tp->o_ray) / y_tp->width) * y_tp->w_ob->width) +
			(int)((float)(y_tp->index - y_tp->start) / (float)(y_tp->end -
			y_tp->start) * (float)y_tp->w_ob->height) * y_tp->w_ob->width),
			y_tp->w_ob->size)] != 0)
				all->data.screen_data[ft_antiseg_leave_window(all->data.x_ray +
			y_tp->index * all->data.window_width, all->data.max_screen_pix)] =
			y_tp->w_ob->sprite_data[ft_limit(((int)((((y_tp->width / 2) +
			y_tp->o_ray) / y_tp->width) * y_tp->w_ob->width) +
			(int)((float)(y_tp->index - y_tp->start) /
			(float)(y_tp->end - y_tp->start) * (float)y_tp->w_ob->height) *
			y_tp->w_ob->width), y_tp->w_ob->size)];
			y_tp->index++;
		}
	}
}

void	ft_y_object_7(t_all *all, t_obj *y_tp)
{
	ft_y_object_7_dir(all, y_tp);
	if (y_tp->width / 2 > ft_absolute_float(y_tp->o_ray))
	{
		y_tp->end = (int)((all->data.window_height / 2) +
		(all->data.window_width / (y_tp->length) / 2));
		y_tp->start = y_tp->end - (int)y_tp->height;
		y_tp->index = y_tp->start;
		while (y_tp->index < y_tp->end &&
			y_tp->index < all->data.window_height)
		{
			if (y_tp->w_ob->sprite_data[ft_limit(((int)((((y_tp->width / 2) +
			y_tp->o_ray) / y_tp->width) * y_tp->w_ob->width) +
			(int)((float)(y_tp->index - y_tp->start) / (float)(y_tp->end -
			y_tp->start) * (float)y_tp->w_ob->height) * y_tp->w_ob->width),
			y_tp->w_ob->size)] != 0)
				all->data.screen_data[ft_antiseg_leave_window(all->data.x_ray +
			y_tp->index * all->data.window_width, all->data.max_screen_pix)] =
			y_tp->w_ob->sprite_data[ft_limit(((int)((((y_tp->width / 2) +
			y_tp->o_ray) / y_tp->width) * y_tp->w_ob->width) +
			(int)((float)(y_tp->index - y_tp->start) /
			(float)(y_tp->end - y_tp->start) * (float)y_tp->w_ob->height) *
			y_tp->w_ob->width), y_tp->w_ob->size)];
			y_tp->index++;
		}
	}
}

void	ft_y_object_8(t_all *all, t_obj *y_tp)
{
	ft_y_object_8_dir(all, y_tp);
	if (y_tp->width / 2 > ft_absolute_float(y_tp->o_ray))
	{
		y_tp->end = (int)((all->data.window_height / 2) +
		(all->data.window_width / (y_tp->length) / 2));
		y_tp->start = y_tp->end - (int)y_tp->height;
		y_tp->index = y_tp->start;
		while (y_tp->index < y_tp->end &&
			y_tp->index < all->data.window_height)
		{
			if (y_tp->w_ob->sprite_data[ft_limit(((int)((((y_tp->width / 2) +
			y_tp->o_ray) / y_tp->width) * y_tp->w_ob->width) +
			(int)((float)(y_tp->index - y_tp->start) / (float)(y_tp->end -
			y_tp->start) * (float)y_tp->w_ob->height) * y_tp->w_ob->width),
			y_tp->w_ob->size)] != 0)
				all->data.screen_data[ft_antiseg_leave_window(all->data.x_ray +
			y_tp->index * all->data.window_width, all->data.max_screen_pix)] =
			y_tp->w_ob->sprite_data[ft_limit(((int)((((y_tp->width / 2) +
			y_tp->o_ray) / y_tp->width) * y_tp->w_ob->width) +
			(int)((float)(y_tp->index - y_tp->start) / (float)(y_tp->end -
			y_tp->start) * (float)y_tp->w_ob->height) * y_tp->w_ob->width),
			y_tp->w_ob->size)];
			y_tp->index++;
		}
	}
}
