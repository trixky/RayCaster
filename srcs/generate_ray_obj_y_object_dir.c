#include "cub3d.h"

void	ft_y_object_5_dir(t_all *all, t_obj *y_temp)
{
	all->fsc.cp_direction = all->fsc.direction;
	if (all->fsc.cp_direction > RAD_180)
		all->fsc.cp_direction -= RAD_360;
	y_temp->direction = atan((y_temp->pos_y - all->player.pos_y) /
	(y_temp->pos_x - all->player.pos_x));
	y_temp->o_ray = (y_temp->direction - all->fsc.cp_direction) /
	all->data.incrementation;
}

void	ft_y_object_6_dir(t_all *all, t_obj *y_temp)
{
	y_temp->direction = RAD_90 + atan((all->player.pos_x - y_temp->pos_x) /
	(y_temp->pos_y - all->player.pos_y));
	y_temp->o_ray = (all->fsc.direction - y_temp->direction) /
	all->data.incrementation;
}

void	ft_y_object_7_dir(t_all *all, t_obj *y_temp)
{
	all->fsc.cp_direction = all->fsc.direction;
	if (all->fsc.cp_direction < RAD_180)
		all->fsc.cp_direction += RAD_360;
	y_temp->direction = RAD_270 + atan((y_temp->pos_x - all->player.pos_x) /
	(all->player.pos_y - y_temp->pos_y));
	y_temp->o_ray = (all->fsc.cp_direction - y_temp->direction) /
	all->data.incrementation;
}

void	ft_y_object_8_dir(t_all *all, t_obj *y_temp)
{
	y_temp->direction = RAD_180 + atan((all->player.pos_y - y_temp->pos_y) /
	(all->player.pos_x - y_temp->pos_x));
	y_temp->o_ray = (all->fsc.direction - y_temp->direction) /
	all->data.incrementation;
}
