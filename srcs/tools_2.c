#include "ray_caster.h"

int		ft_infinite_rotation_player(t_all *all)
{
	if (all->player.direction > 360)
		all->player.direction -= 360;
	else if (all->player.direction < 0)
		all->player.direction += 360;
	return (all->player.direction);
}

float	ft_fsc_inifinit_rotation(float rad)
{
	if (rad >= RAD_360)
		rad -= RAD_360;
	else if (rad < RAD_0)
		rad += RAD_360;
	return (rad);
}

int		ft_check_case_exist(float y, float x, t_all *all)
{
	if (x < (float)0 ||
			x >= (float)all->map.width ||
			y < (float)0 ||
			y >= (float)all->map.height)
		return (FALSE);
	return (TRUE);
}

int		ft_key_isfordeplacement(int keycode)
{
	if (keycode == FRONT ||
			keycode == RIGHT ||
			keycode == BACK ||
			keycode == LEFT)
		return (TRUE);
	return (FALSE);
}

void	ft_deplacement_limitation(t_all *all)
{
	if (all->player.pos_x < (float)LIMIT_PRECISION)
		all->player.pos_x = (float)LIMIT_PRECISION;
	if (all->player.pos_x >= (float)all->map.width - LIMIT_PRECISION)
		all->player.pos_x = (float)all->map.width - LIMIT_PRECISION;
	if (all->player.pos_y < (float)LIMIT_PRECISION)
		all->player.pos_y = (float)LIMIT_PRECISION;
	if (all->player.pos_y >= (float)all->map.height - LIMIT_PRECISION)
		all->player.pos_y = (float)all->map.height - LIMIT_PRECISION;
}
