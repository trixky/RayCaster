#include "ray_caster.h"

void	ft_print_error(int error_id)
{
	char c;

	if (error_id != 1)
	{
		write(1, "Error\n", 6);
		c = error_id + 48;
		write(1, "id error = ", 11);
		write(1, &c, 1);
		write(1, ".\n", 2);
	}
}

int		ft_close_by_red_cross(t_all *all)
{
	ft_close(all, 1);
	return (FALSE);
}

void	ft_free_map_array(t_all *all)
{
	int i;

	i = 0;
	if (all->map.array != NULL)
	{
		while (i <= all->map.height)
		{
			if (all->map.array[i] != NULL)
				free(all->map.array[i]);
			else
				break ;
			i++;
		}
		free(all->map.array);
	}
}

void	ft_close_free_1(t_all *all)
{
	if (all->data.mlx != NULL)
	{
		if (all->n_wall.sprite != NULL)
			mlx_destroy_image(all->data.mlx, all->n_wall.sprite);
		if (all->e_wall.sprite != NULL)
			mlx_destroy_image(all->data.mlx, all->e_wall.sprite);
		if (all->s_wall.sprite != NULL)
			mlx_destroy_image(all->data.mlx, all->s_wall.sprite);
		if (all->o_wall.sprite != NULL)
			mlx_destroy_image(all->data.mlx, all->o_wall.sprite);
		if (all->object.sprite != NULL)
			mlx_destroy_image(all->data.mlx, all->object.sprite);
		if (all->data.window != NULL)
		{
			mlx_clear_window(all->data.mlx, all->data.window);
			mlx_destroy_window(all->data.mlx, all->data.window);
		}
	}
}

void	ft_close_free_2(t_all *all)
{
	if (all->data.path_texture_no != NULL)
		free(all->data.path_texture_no);
	if (all->data.path_texture_so != NULL)
		free(all->data.path_texture_so);
	if (all->data.path_texture_ea != NULL)
		free(all->data.path_texture_ea);
	if (all->data.path_texture_we != NULL)
		free(all->data.path_texture_we);
	if (all->data.path_texture_s != NULL)
		free(all->data.path_texture_s);
}
