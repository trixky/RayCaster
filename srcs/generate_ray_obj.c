#include "ray_caster.h"

void	ft_init_length_object(t_all *all, t_obj *x_temp, t_obj *y_temp)
{
	if (x_temp != NULL)
		x_temp->length = sqrt(pow(all->player.pos_x - x_temp->pos_x, 2) +
		pow(x_temp->pos_y - all->player.pos_y, 2));
	if (y_temp != NULL)
		y_temp->length = sqrt(pow(all->player.pos_x - y_temp->pos_x, 2) +
		pow(y_temp->pos_y - all->player.pos_y, 2));
}

void	ft_generate_ray_obj(t_all *all)
{
	t_obj *x_temp;
	t_obj *y_temp;

	x_temp = all->fsc.x_obj;
	y_temp = all->fsc.y_obj;
	while (x_temp != NULL || y_temp != NULL)
	{
		ft_init_length_object(all, x_temp, y_temp);
		if (x_temp != NULL && (y_temp == NULL ||
				((float)x_temp->length > (float)y_temp->length)))
		{
			ft_x_object(all, x_temp);
			x_temp = x_temp->next;
		}
		else
		{
			ft_y_object(all, y_temp);
			y_temp = y_temp->next;
		}
	}
}
