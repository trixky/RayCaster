#include "cub3d.h"

void	ft_init_gun(t_all *all, t_gun *gun)
{
	gun->x_start = (all->data.window_width / 8) * 3;
	gun->x_index = gun->x_start;
	gun->x_end = gun->x_start + (all->data.window_width / 8) * 2;
	gun->y_start = (all->data.window_height / 8) * 6;
	gun->y_index = gun->y_start;
	gun->y_end = all->data.window_height;
}

void	ft_put_gun(t_all *all)
{
	t_gun	gun;

	ft_init_gun(all, &gun);
	while (gun.y_index < gun.y_end)
	{
		gun.x_index = gun.x_start;
		while (gun.x_index < gun.x_end)
		{
			gun.color = all->gun.sprite_data[(int)((((float)(gun.x_index -
			gun.x_start) / (float)(gun.x_end - gun.x_start)) * all->gun.width) +
			((((gun.y_index - gun.y_start) * all->gun.height) / (gun.y_end -
			gun.y_start))) * all->gun.width)];
			if (gun.color == 0)
			{
				gun.x_index++;
				continue;
			}
			else
				all->data.screen_data[ft_antiseg_leave_window(gun.x_index +
				gun.y_index * all->data.window_width,
				all->data.max_screen_pix)] = gun.color;
			gun.x_index++;
		}
		gun.y_index++;
	}
}
