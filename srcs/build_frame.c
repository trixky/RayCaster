#include "ray_caster.h"

void	ft_frame(t_all *all)
{
	float	end_field;

	all->fsc.direction =
	ft_degree_to_rad(all->player.direction) - ft_degree_to_rad(30);
	end_field = ft_degree_to_rad(all->player.direction) + ft_degree_to_rad(30);
	all->data.incrementation =
	ft_degree_to_rad((float)60 / (float)(all->data.window_width - 1));
	all->data.x_ray = 0;
	while (all->fsc.direction < end_field)
	{
		ft_shot_faisceau(all);
		ft_generate_ray_wall(all);
		ft_generate_ray_obj(all);
		all->fsc.direction += all->data.incrementation;
		all->data.x_ray++;
	}
}

void	ft_init_shot_faisceau(t_all *all)
{
	all->fsc.closest_lenght_obj = 100.0;
	all->fsc.x_pos_x = all->player.pos_x;
	all->fsc.x_pos_y = all->player.pos_y;
	all->fsc.x_lenght = 0;
	all->fsc.x_wall_touched = FALSE;
	ft_lstclear(&all->fsc.x_obj);
	all->fsc.y_pos_x = all->player.pos_x;
	all->fsc.y_pos_y = all->player.pos_y;
	all->fsc.y_lenght = 0;
	all->fsc.y_wall_touched = FALSE;
	ft_lstclear(&all->fsc.y_obj);
	all->fsc.cp_direction = all->fsc.direction;
	if (all->fsc.cp_direction > RAD_360)
		all->fsc.cp_direction -= RAD_360;
	else if (all->fsc.cp_direction < RAD_0)
		all->fsc.cp_direction += RAD_360;
}

int		ft_shot_faisceau(t_all *all)
{
	ft_init_shot_faisceau(all);
	if (all->fsc.cp_direction > RAD_0)
	{
		if (all->fsc.cp_direction <= RAD_90)
			ft_shot_faisceau_90(all);
		else if (all->fsc.cp_direction < RAD_180)
			ft_shot_faisceau_180(all);
		else if (all->fsc.cp_direction <= RAD_270)
			ft_shot_faisceau_270(all);
		else if (all->fsc.cp_direction <= RAD_360)
			ft_shot_faisceau_360(all);
	}
	return (TRUE);
}
