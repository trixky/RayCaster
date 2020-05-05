#include "cub3d.h"

void	ft_x_object_1_dir(t_all *all, t_obj *x_temp)
{
	x_temp->direction = atan((x_temp->pos_y - all->player.pos_y) /
	(x_temp->pos_x - all->player.pos_x));
	x_temp->o_ray = (x_temp->direction - all->fsc.direction) /
	all->data.incrementation;
}

void	ft_x_object_2_dir(t_all *all, t_obj *x_temp)
{
	x_temp->direction = RAD_90 + atan((all->player.pos_x - x_temp->pos_x) /
	(x_temp->pos_y - all->player.pos_y));
	x_temp->o_ray = (x_temp->direction - all->fsc.direction) /
	all->data.incrementation;
}

void	ft_x_object_3_dir(t_all *all, t_obj *x_temp)
{
	x_temp->direction = RAD_270 + atan((x_temp->pos_x - all->player.pos_x) /
	(all->player.pos_y - x_temp->pos_y));
	x_temp->o_ray = (x_temp->direction - all->fsc.direction) /
	all->data.incrementation;
}

void	ft_x_object_4_dir(t_all *all, t_obj *x_temp)
{
	x_temp->direction = RAD_180 + atan((all->player.pos_y - x_temp->pos_y) /
	(all->player.pos_x - x_temp->pos_x));
	x_temp->o_ray = (x_temp->direction - all->fsc.direction) /
	all->data.incrementation;
}
