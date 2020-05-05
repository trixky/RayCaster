int	ft_rad_90_y(t_all *all)
{
	int c;

	all->fsc.y_pos_y += ft_next_block_distance(all->fsc.y_pos_y, SUP);
	all->fsc.y_angle = tan(all->fsc.cp_direction);
	all->fsc.y_pos_x = all->player.pos_x + (all->fsc.y_pos_y -
	all->player.pos_y) / all->fsc.y_angle;
	all->fsc.y_lenght = sqrt(pow(all->player.pos_x - all->fsc.y_pos_x, 2) +
	pow(all->fsc.y_pos_y - all->player.pos_y, 2));
	all->fsc.y_ray_of_wall = ft_next_block_distance(all->fsc.y_pos_x, SUP);
	if (ft_check_case_exist(all->fsc.y_pos_y, all->fsc.y_pos_x, all) &&
	(c = all->map.array[(int)all->fsc.y_pos_y][(int)all->fsc.y_pos_x]) != 0)
	{
		if (c + 48 == '2' || c + 48 == '3' || c + 48 == '5')
			ft_lstadd_front(&all->fsc.x_obj,
			ft_lstnew(all, ft_cut_float(all->fsc.y_pos_x) + 0.5,
			ft_cut_float(all->fsc.y_pos_y) + 0.5, c + 48));
		else
		{
			all->fsc.y_wall_touched = c + 48;
			all->ptr_wall_y = &all->n_wall;
			return (TRUE);
		}
	}
	return (FALSE);
}

int	ft_rad_180_y(t_all *all)
{
	int c;

	all->fsc.y_pos_y += ft_next_block_distance(all->fsc.y_pos_y, SUP);
	all->fsc.y_angle = tan(RAD_180 - all->fsc.cp_direction);
	all->fsc.y_pos_x = all->player.pos_x - (all->fsc.y_pos_y -
	all->player.pos_y) / all->fsc.y_angle;
	all->fsc.y_lenght = sqrt(pow(all->player.pos_x - all->fsc.y_pos_x, 2) +
	pow(all->fsc.y_pos_y - all->player.pos_y, 2));
	all->fsc.y_ray_of_wall = ft_next_block_distance(all->fsc.y_pos_x, SUP);
	if (ft_check_case_exist(all->fsc.y_pos_y, all->fsc.y_pos_x, all) &&
	(c = all->map.array[(int)all->fsc.y_pos_y][(int)all->fsc.y_pos_x]) != 0)
	{
		if (c + 48 == '2' || c + 48 == '3' || c + 48 == '5')
			ft_lstadd_front(&all->fsc.x_obj,
			ft_lstnew(all, ft_cut_float(all->fsc.y_pos_x) + 0.5,
			ft_cut_float(all->fsc.y_pos_y) + 0.5, c + 48));
		else
		{
			all->fsc.y_wall_touched = c + 48;
			all->ptr_wall_y = &all->n_wall;
			return (TRUE);
		}
	}
	return (FALSE);
}

int	ft_rad_270_y(t_all *all)
{
	int c;

	all->fsc.y_pos_y -= ft_next_block_distance(all->fsc.y_pos_y, INF);
	all->fsc.y_angle = tan(RAD_270 - all->fsc.cp_direction);
	all->fsc.y_pos_x = all->player.pos_x - (all->player.pos_y -
	all->fsc.y_pos_y) * all->fsc.y_angle;
	all->fsc.y_lenght = sqrt(pow(all->player.pos_x - all->fsc.y_pos_x, 2) +
	pow(all->fsc.y_pos_y - all->player.pos_y, 2));
	all->fsc.y_ray_of_wall = ft_next_block_distance(all->fsc.y_pos_x, INF);
	if (ft_check_case_exist(all->fsc.y_pos_y - 1, all->fsc.y_pos_x, all) &&
	(c = all->map.array[(int)all->fsc.y_pos_y - 1][(int)all->fsc.y_pos_x]) != 0)
	{
		if (c + 48 == '2' || c + 48 == '3' || c + 48 == '5')
			ft_lstadd_front(&all->fsc.x_obj,
			ft_lstnew(all, ft_cut_float(all->fsc.y_pos_x) + 0.5,
			ft_cut_float(all->fsc.y_pos_y - 1) + 0.5, c + 48));
		else
		{
			all->fsc.y_wall_touched = c + 48;
			all->ptr_wall_y = &all->s_wall;
			return (TRUE);
		}
	}
	return (FALSE);
}

int	ft_rad_360_y(t_all *all)
{
	int c;

	all->fsc.y_pos_y -= ft_next_block_distance(all->fsc.y_pos_y, INF);
	all->fsc.y_angle = tan(all->fsc.cp_direction - RAD_270);
	all->fsc.y_pos_x = all->player.pos_x + (all->player.pos_y -
	all->fsc.y_pos_y) * all->fsc.y_angle;
	all->fsc.y_lenght = sqrt(pow(all->player.pos_x - all->fsc.y_pos_x, 2) +
	pow(all->fsc.y_pos_y - all->player.pos_y, 2));
	all->fsc.y_ray_of_wall = ft_next_block_distance(all->fsc.y_pos_x, INF);
	if (ft_check_case_exist(all->fsc.y_pos_y - 1, all->fsc.y_pos_x, all) &&
	(c = all->map.array[(int)all->fsc.y_pos_y - 1][(int)all->fsc.y_pos_x]) != 0)
	{
		if (c + 48 == '2' || c + 48 == '3' || c + 48 == '5')
			ft_lstadd_front(&all->fsc.x_obj,
			ft_lstnew(all, ft_cut_float(all->fsc.y_pos_x) + 0.5,
			ft_cut_float(all->fsc.y_pos_y - 1) + 0.5, c + 48));
		else
		{
			all->fsc.y_wall_touched = c + 48;
			all->ptr_wall_y = &all->s_wall;
			return (TRUE);
		}
	}
	return (FALSE);
}
