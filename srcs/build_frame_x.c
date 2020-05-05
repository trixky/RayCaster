#include "cub3d.h"

int	ft_rad_90_x(t_all *all)
{
	int c;

	all->fsc.x_pos_x += ft_next_block_distance(all->fsc.x_pos_x, SUP);
	all->fsc.x_angle = tan(all->fsc.cp_direction);
	all->fsc.x_pos_y = all->player.pos_y + all->fsc.x_angle *
	(all->fsc.x_pos_x - all->player.pos_x);
	all->fsc.x_lenght = sqrt(pow(all->player.pos_x - all->fsc.x_pos_x, 2) +
	pow(all->fsc.x_pos_y - all->player.pos_y, 2));
	all->fsc.x_ray_of_wall = ft_next_block_distance(all->fsc.x_pos_y, INF);
	if (ft_check_case_exist(all->fsc.x_pos_y, all->fsc.x_pos_x, all) &&
	(c = all->map.array[(int)all->fsc.x_pos_y][(int)all->fsc.x_pos_x]) != 0)
	{
		if (c + 48 == '2' || c + 48 == '3' || c + 48 == '5')
			ft_lstadd_front(&all->fsc.y_obj,
			ft_lstnew(all, ft_cut_float(all->fsc.x_pos_x) + 0.5,
			ft_cut_float(all->fsc.x_pos_y) + 0.5, c + 48));
		else
		{
			all->fsc.x_wall_touched = c + 48;
			all->ptr_wall_x = &all->o_wall;
			return (TRUE);
		}
	}
	return (FALSE);
}

int	ft_rad_180_x(t_all *all)
{
	int c;

	all->fsc.x_pos_x -= ft_next_block_distance(all->fsc.x_pos_x, INF);
	all->fsc.x_angle = tan(RAD_180 - all->fsc.cp_direction);
	if (all->fsc.x_angle < (float)0)
		all->fsc.x_angle = 1000000;
	all->fsc.x_pos_y = all->player.pos_y + all->fsc.x_angle *
	(all->player.pos_x - all->fsc.x_pos_x);
	all->fsc.x_lenght = sqrt(pow(all->player.pos_x - all->fsc.x_pos_x, 2) +
	pow(all->fsc.x_pos_y - all->player.pos_y, 2));
	all->fsc.x_ray_of_wall = ft_next_block_distance(all->fsc.x_pos_y, SUP);
	if (ft_check_case_exist(all->fsc.x_pos_y, all->fsc.x_pos_x - 1, all) &&
	(c = all->map.array[(int)all->fsc.x_pos_y][(int)all->fsc.x_pos_x - 1]) != 0)
	{
		if ((c += 48) > 0 && (c == '2' || c == '3' || c == '5'))
			ft_lstadd_front(&all->fsc.y_obj, ft_lstnew(all, ft_cut_float(all->
			fsc.x_pos_x - 1) + 0.5, ft_cut_float(all->fsc.x_pos_y) + 0.5, c));
		else
		{
			all->fsc.x_wall_touched = c;
			all->ptr_wall_x = &all->e_wall;
			return (TRUE);
		}
	}
	return (FALSE);
}

int	ft_rad_270_x(t_all *all)
{
	int c;

	all->fsc.x_pos_x -= ft_next_block_distance(all->fsc.x_pos_x, INF);
	all->fsc.x_angle = tan(all->fsc.cp_direction - RAD_180);
	all->fsc.x_pos_y = all->player.pos_y - all->fsc.x_angle *
	(all->player.pos_x - all->fsc.x_pos_x);
	all->fsc.x_lenght = sqrt(pow(all->player.pos_x - all->fsc.x_pos_x, 2) +
	pow(all->fsc.x_pos_y - all->player.pos_y, 2));
	all->fsc.x_ray_of_wall = ft_next_block_distance(all->fsc.x_pos_y, SUP);
	if (ft_check_case_exist(all->fsc.x_pos_y, all->fsc.x_pos_x - 1, all) &&
	(c = all->map.array[(int)all->fsc.x_pos_y][(int)all->fsc.x_pos_x - 1]) != 0)
	{
		if (c + 48 == '2' || c + 48 == '3' || c + 48 == '5')
			ft_lstadd_front(&all->fsc.y_obj,
			ft_lstnew(all, ft_cut_float(all->fsc.x_pos_x - 1) + 0.5,
			ft_cut_float(all->fsc.x_pos_y) + 0.5, c + 48));
		else
		{
			all->fsc.x_wall_touched = c + 48;
			all->ptr_wall_x = &all->e_wall;
			return (TRUE);
		}
	}
	return (FALSE);
}

int	ft_rad_360_x(t_all *all)
{
	int c;

	all->fsc.x_pos_x += ft_next_block_distance(all->fsc.x_pos_x, SUP);
	all->fsc.x_angle = tan(RAD_360 - all->fsc.cp_direction);
	all->fsc.x_pos_y = all->player.pos_y - all->fsc.x_angle *
	(all->fsc.x_pos_x - all->player.pos_x);
	all->fsc.x_lenght = sqrt(pow(all->player.pos_x - all->fsc.x_pos_x, 2) +
	pow(all->fsc.x_pos_y - all->player.pos_y, 2));
	all->fsc.x_ray_of_wall = ft_next_block_distance(all->fsc.x_pos_y, INF);
	if (ft_check_case_exist(all->fsc.x_pos_y, all->fsc.x_pos_x, all) &&
	(c = all->map.array[(int)all->fsc.x_pos_y][(int)all->fsc.x_pos_x]) != 0)
	{
		if (c + 48 == '2' || c + 48 == '3' || c + 48 == '5')
			ft_lstadd_front(&all->fsc.y_obj, ft_lstnew(all, ft_cut_float(all->
			fsc.x_pos_x) + 0.5, ft_cut_float(all->fsc.x_pos_y) + 0.5, c + 48));
		else
		{
			all->fsc.x_wall_touched = c + 48;
			all->ptr_wall_x = &all->o_wall;
			return (TRUE);
		}
	}
	return (FALSE);
}
