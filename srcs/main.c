#include "cub3d.h"

int		ft_str_is_save(char *str)
{
	if (str[0] == '-' &&
		str[1] == '-' &&
		str[2] == 's' &&
		str[3] == 'a' &&
		str[4] == 'v' &&
		str[5] == 'e' &&
		str[6] == '\0')
		return (TRUE);
	return (FALSE);
}

int		ft_cub_ext(char *str)
{
	int	ret;

	if ((ret = ft_strlen(str)) > 5 &&
			str[ret - 1] == 'b' &&
			str[ret - 2] == 'u' &&
			str[ret - 3] == 'c' &&
			str[ret - 4] == '.')
		return (TRUE);
	return (FALSE);
}

int		ft_check_null(t_all *all)
{
	if (all->data.mlx == NULL || all->n_wall.sprite == NULL ||
			all->e_wall.sprite == NULL || all->s_wall.sprite == NULL ||
			all->o_wall.sprite == NULL || all->object.sprite == NULL)
		return (TRUE);
	return (FALSE);
}

void	ft_first_screen(t_all *all)
{
	ft_clean_screen(all);
	ft_frame(all);
	ft_put_gun(all);
	ft_put_vie(all);
	mlx_put_image_to_window(all->data.mlx, all->data.window,
	all->data.screen, 0, 0);
	if (all->data.window_height > 400 && all->data.window_width > 600)
		mlx_string_put(all->data.mlx, all->data.window, 20, 10, 100000,
		"ammo : 32 | loader : 6/6");
}

int		main(int argc, char **argv)
{
	t_all all;

	if ((argc != 2 || ft_cub_ext(argv[1]) == FALSE) &&
			!(argc == 3 && ft_str_is_save(argv[2]) == TRUE))
		ft_close(&all, 8);
	all.start_clock = clock();
	ft_start_init(&all);
	if (ft_parser(&all, argv[1]) == TRUE)
		ft_close(&all, 5);
	ft_check_parsing(&all);
	ft_check_all_path(&all);
	ft_recize_window(&all);
	ft_init_mlx(&all);
	if (ft_check_null(&all) == TRUE)
		ft_close(&all, 6);
	mlx_loop_hook(all.data.mlx, &ft_inifinit_hook, &all);
	ft_first_screen(&all);
	mlx_hook(all.data.window, 2, 0, &key_hook, &all);
	mlx_hook(all.data.window, 17, 0, &ft_close_by_red_cross, &all);
	if (!(argc == 3 && create_bmp(&all) == FALSE))
		mlx_loop(all.data.mlx);
	return (0);
}
