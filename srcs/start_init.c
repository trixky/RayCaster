#include "ray_caster.h"

void	ft_start_init(t_all *all)
{
	all->player.direction = -2;
	all->data.c_color = -1;
	all->data.f_color = -1;
	all->data.window_width = 0;
	all->data.window_height = 0;
	all->map.array = NULL;
	all->fsc.x_obj = NULL;
	all->fsc.y_obj = NULL;
	all->data.path_texture_no = NULL;
	all->data.path_texture_so = NULL;
	all->data.path_texture_we = NULL;
	all->data.path_texture_ea = NULL;
	all->data.path_texture_s = NULL;
	all->data.mlx = NULL;
	all->n_wall.sprite = NULL;
	all->e_wall.sprite = NULL;
	all->s_wall.sprite = NULL;
	all->o_wall.sprite = NULL;
	all->object.sprite = NULL;
	all->data.window = NULL;
}

void	ft_init_mlx_cut_1(t_all *all)
{
	all->data.mlx = mlx_init();
	all->data.window = mlx_new_window(all->data.mlx, all->data.window_width,
	all->data.window_height, WINDOW_TITLE);
	all->object.sprite = mlx_xpm_file_to_image(all->data.mlx,
	all->data.path_texture_s, &all->object.width, &all->object.height);
	all->object.sprite_data = (int *)mlx_get_data_addr(all->object.sprite,
	&all->object.sprite_bpp, &all->object.sprite_size_line,
	&all->object.sprite_endian);
	all->object.size = (all->object.height * all->object.height) - 1;
	all->gun.sprite = mlx_xpm_file_to_image(all->data.mlx,
	GUN_PATH, &all->gun.width, &all->gun.height);
	all->gun.sprite_data = (int *)mlx_get_data_addr(all->gun.sprite,
	&all->gun.sprite_bpp, &all->gun.sprite_size_line,
	&all->gun.sprite_endian);
	all->gun.size = (all->gun.height * all->gun.height) - 1;
	all->n_wall.sprite = mlx_xpm_file_to_image(all->data.mlx,
	all->data.path_texture_so, &all->n_wall.width, &all->n_wall.height);
	all->n_wall.sprite_data = (int *)mlx_get_data_addr(all->n_wall.sprite,
	&all->n_wall.sprite_bpp, &all->n_wall.sprite_size_line,
	&all->n_wall.sprite_endian);
	all->e_wall.sprite = mlx_xpm_file_to_image(all->data.mlx,
	all->data.path_texture_ea, &all->e_wall.width, &all->e_wall.height);
	all->e_wall.sprite_data = (int *)mlx_get_data_addr(all->e_wall.sprite,
	&all->e_wall.sprite_bpp, &all->e_wall.sprite_size_line,
	&all->e_wall.sprite_endian);
}

void	ft_init_mlx_cut_2(t_all *all)
{
	all->object_2.sprite = mlx_xpm_file_to_image(all->data.mlx,
	B_M_O_3_PATH, &all->object_2.width, &all->object_2.height);
	all->object_2.sprite_data = (int *)mlx_get_data_addr(all->object_2.sprite,
	&all->object_2.sprite_bpp, &all->object_2.sprite_size_line,
	&all->object_2.sprite_endian);
	all->object_2.size = (all->object_2.height * all->object_2.height) - 1;
	all->object_b.sprite = mlx_xpm_file_to_image(all->data.mlx,
	B_M_O_1_PATH, &all->object_b.width, &all->object_b.height);
	all->object_b.sprite_data = (int *)mlx_get_data_addr(all->object_b.sprite,
	&all->object_b.sprite_bpp, &all->object_b.sprite_size_line,
	&all->object_b.sprite_endian);
	all->object_b.size = (all->object_b.height * all->object_b.height) - 1;
	all->object_bb.sprite = mlx_xpm_file_to_image(all->data.mlx,
	B_M_O_2_PATH, &all->object_bb.width, &all->object_bb.height);
	all->object_bb.sprite_data = (int *)mlx_get_data_addr(all->object_bb.sprite,
	&all->object_bb.sprite_bpp, &all->object_bb.sprite_size_line,
	&all->object_bb.sprite_endian);
	all->object_bb.size = (all->object_bb.height * all->object_bb.height) - 1;
	all->poing.sprite = mlx_xpm_file_to_image(all->data.mlx,
	B_M_O_2_PATH, &all->poing.width, &all->poing.height);
	all->poing.sprite_data = (int *)mlx_get_data_addr(all->poing.sprite,
	&all->poing.sprite_bpp, &all->poing.sprite_size_line,
	&all->poing.sprite_endian);
	all->poing.size = (all->poing.height * all->poing.height) - 1;
}

void	ft_init_mlx(t_all *all)
{
	ft_init_mlx_cut_1(all);
	ft_init_mlx_cut_2(all);
	all->s_wall.sprite = mlx_xpm_file_to_image(all->data.mlx,
	all->data.path_texture_no, &all->s_wall.width, &all->s_wall.height);
	all->s_wall.sprite_data = (int *)mlx_get_data_addr(all->s_wall.sprite,
	&all->s_wall.sprite_bpp, &all->s_wall.sprite_size_line,
	&all->s_wall.sprite_endian);
	all->o_wall.sprite = mlx_xpm_file_to_image(all->data.mlx,
	all->data.path_texture_we, &all->o_wall.width, &all->o_wall.height);
	all->o_wall.sprite_data = (int *)mlx_get_data_addr(all->o_wall.sprite,
	&all->o_wall.sprite_bpp, &all->o_wall.sprite_size_line,
	&all->o_wall.sprite_endian);
	all->ptr_wall_x = &all->n_wall;
	all->ptr_wall_y = &all->n_wall;
	all->data.screen = mlx_new_image(all->data.mlx, all->data.window_width,
	all->data.window_height);
	all->data.screen_data = (int *)mlx_get_data_addr(all->data.screen,
	&all->data.screen_bpp, &all->data.screen_size_line,
	&all->data.screen_endian);
	all->data.max_screen_pix = (all->data.window_width *
	all->data.window_height) - 1;
}
