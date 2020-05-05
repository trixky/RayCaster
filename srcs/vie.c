#include "ray_caster.h"

void	ft_init_vie(t_all *all, t_vie *vie)
{
	vie->x_start = (all->data.window_width / 8) * 3;
	vie->x_index = vie->x_start;
	vie->x_end = vie->x_start + (all->data.window_width / 8) * 2;
	vie->y_start = (all->data.window_height / 12);
	vie->y_index = vie->y_start;
	vie->y_end = vie->y_start + (all->data.window_height / 12);
	vie->color = LIFE_COLOR;
}

void	ft_put_vie(t_all *all)
{
	t_vie	vie;

	ft_init_vie(all, &vie);
	while (vie.y_index < vie.y_end)
	{
		vie.x_index = vie.x_start;
		while (vie.x_index < vie.x_end)
		{
			all->data.screen_data[ft_antiseg_leave_window(vie.x_index +
			vie.y_index * all->data.window_width,
			all->data.max_screen_pix)] = vie.color;
			vie.x_index++;
		}
		vie.y_index++;
	}
}
