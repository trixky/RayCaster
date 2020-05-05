#include "ray_caster.h"

int		ft_atoi(char *str)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		nbr *= 10;
		nbr += str[i] - 48;
		i++;
	}
	return (nbr);
}

int		ft_free_and_return(void **ptr_1, void **ptr_2,
		void **ptr_3, void **ptr_4)
{
	if (ptr_1 != NULL && *ptr_1 != NULL)
	{
		free(*ptr_1);
		*ptr_1 = NULL;
	}
	if (ptr_2 != NULL && *ptr_2 != NULL)
	{
		free(*ptr_2);
		*ptr_2 = NULL;
	}
	if (ptr_3 != NULL && *ptr_3 != NULL)
	{
		free(*ptr_3);
		*ptr_3 = NULL;
	}
	if (ptr_4 != NULL && *ptr_4 != NULL)
	{
		free(*ptr_4);
		*ptr_4 = NULL;
	}
	return (TRUE);
}

int		ft_antiseg_leave_window(int nbr, int limit)
{
	if (nbr > limit)
		return (limit);
	if (nbr < 0)
		return (0);
	return (nbr);
}

void	ft_clean_screen(t_all *all)
{
	int x;
	int y;

	y = 0;
	while (y < all->data.window_height)
	{
		x = 0;
		while (x < all->data.window_width)
		{
			if (y > all->data.window_height / 2)
				all->data.screen_data[x + y * all->data.window_width] =
				all->data.f_color;
			else
				all->data.screen_data[x + y * all->data.window_width] =
				all->data.c_color;
			x++;
		}
		y++;
	}
}

void	infinit_rot_player(t_all *all, int dir_dep)
{
	all->fsc.direction = ft_degree_to_rad(dir_dep);
	if (ft_shot_faisceau(all) == TRUE && all->fsc.y_lenght > W_SPEED * 1.1 &&
	all->fsc.x_lenght > W_SPEED * 1.1 && all->fsc.closest_lenght_obj > 0.7)
	{
		if (dir_dep < 90)
		{
			all->player.pos_x += cos(ft_degree_to_rad(dir_dep)) * W_SPEED;
			all->player.pos_y += sin(ft_degree_to_rad(dir_dep)) * W_SPEED;
		}
		else if (dir_dep < 180)
		{
			all->player.pos_x -= sin(ft_degree_to_rad(dir_dep - 90)) * W_SPEED;
			all->player.pos_y += cos(ft_degree_to_rad(dir_dep - 90)) * W_SPEED;
		}
		else if (dir_dep < 270)
		{
			all->player.pos_x -= cos(ft_degree_to_rad(dir_dep - 180)) * W_SPEED;
			all->player.pos_y -= sin(ft_degree_to_rad(dir_dep - 180)) * W_SPEED;
		}
		else if (dir_dep <= 360)
		{
			all->player.pos_x += sin(ft_degree_to_rad(dir_dep - 270)) * W_SPEED;
			all->player.pos_y -= cos(ft_degree_to_rad(dir_dep - 270)) * W_SPEED;
		}
	}
}
