#include "cub3d.h"

void	ft_shot_faisceau_90(t_all *all)
{
	while (all->fsc.x_pos_x - all->player.pos_x <= MAX_LENGTH_FSC)
		if (ft_rad_90_x(all) == TRUE)
			break ;
	while (all->fsc.y_pos_y - all->player.pos_y <= MAX_LENGTH_FSC)
		if (ft_rad_90_y(all) == TRUE)
			break ;
}

void	ft_shot_faisceau_180(t_all *all)
{
	while (all->player.pos_x - all->fsc.x_pos_x <= MAX_LENGTH_FSC)
		if (ft_rad_180_x(all) == TRUE)
			break ;
	while (all->fsc.y_pos_y - all->player.pos_y <= MAX_LENGTH_FSC)
		if (ft_rad_180_y(all) == TRUE)
			break ;
}

void	ft_shot_faisceau_270(t_all *all)
{
	while (all->player.pos_x - all->fsc.x_pos_x <= MAX_LENGTH_FSC)
		if (ft_rad_270_x(all) == TRUE)
			break ;
	while (all->player.pos_y - all->fsc.y_pos_y <= MAX_LENGTH_FSC)
		if (ft_rad_270_y(all) == TRUE)
			break ;
}

void	ft_shot_faisceau_360(t_all *all)
{
	while (all->fsc.x_pos_x - all->player.pos_x <= MAX_LENGTH_FSC)
		if (ft_rad_360_x(all) == TRUE)
			break ;
	while (all->player.pos_y - all->fsc.y_pos_y <= MAX_LENGTH_FSC)
		if (ft_rad_360_y(all) == TRUE)
			break ;
}
