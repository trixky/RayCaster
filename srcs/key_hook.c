#include "ray_caster.h"

void	ft_kill_secret_door(t_all *all)
{
	int y;
	int x;

	y = (int)all->player.pos_y;
	x = (int)all->player.pos_x;
	if (all->map.array[y - 1][x - 1] == 4)
		all->map.array[y - 1][x - 1] = 0;
	if (all->map.array[y - 1][x] == 4)
		all->map.array[y - 1][x] = 0;
	if (all->map.array[y - 1][x + 1] == 4)
		all->map.array[y - 1][x + 1] = 0;
	if (all->map.array[y + 1][x - 1] == 4)
		all->map.array[y + 1][x - 1] = 0;
	if (all->map.array[y + 1][x] == 4)
		all->map.array[y + 1][x] = 0;
	if (all->map.array[y + 1][x + 1] == 4)
		all->map.array[y + 1][x + 1] = 0;
	if (all->map.array[y][x - 1] == 4)
		all->map.array[y][x - 1] = 0;
	if (all->map.array[y][x + 1] == 4)
		all->map.array[y][x + 1] = 0;
}

void	ft_kill_alien(t_all *all)
{
	int y;
	int x;

	y = (int)all->player.pos_y;
	x = (int)all->player.pos_x;
	if (all->map.array[y - 1][x - 1] == 3)
		all->map.array[y - 1][x - 1] = 0;
	if (all->map.array[y - 1][x] == 3)
		all->map.array[y - 1][x] = 0;
	if (all->map.array[y - 1][x + 1] == 3)
		all->map.array[y - 1][x + 1] = 0;
	if (all->map.array[y + 1][x - 1] == 3)
		all->map.array[y + 1][x - 1] = 0;
	if (all->map.array[y + 1][x] == 3)
		all->map.array[y + 1][x] = 0;
	if (all->map.array[y + 1][x + 1] == 3)
		all->map.array[y + 1][x + 1] = 0;
	if (all->map.array[y][x - 1] == 3)
		all->map.array[y][x - 1] = 0;
	if (all->map.array[y][x + 1] == 3)
		all->map.array[y][x + 1] = 0;
}

int		key_hook(int keycode, t_all *all)
{
	if (keycode == 53)
		ft_close(all, 1);
	else if (keycode == 124)
		all->player.direction += R_SPEED;
	else if (keycode == 123)
		all->player.direction -= R_SPEED;
	else if (ft_key_isfordeplacement(keycode))
		ft_deplacement(all, keycode);
	else if (keycode == 49)
		ft_kill_secret_door(all);
	else if (keycode == 40)
		ft_kill_alien(all);
	mlx_clear_window(all->data.mlx, all->data.window);
	ft_infinite_rotation_player(all);
	ft_first_screen(all);
	return (0);
}
