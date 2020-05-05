#include "cub3d.h"

int		ft_parse_r_init(t_all *all, int *i, char **width_str, char **height_str)
{
	*width_str = NULL;
	*height_str = NULL;
	*i = 2;
	if (all->data.window_width != 0 || all->data.window_height != 0)
		return (TRUE);
	return (FALSE);
}

void	ft_parse_r_finish(t_all *all, char **width_str, char **height_str)
{
	if (*width_str != NULL)
		all->data.window_width = ft_atoi(*width_str);
	if (*height_str != NULL)
		all->data.window_height = ft_atoi(*height_str);
	ft_free_and_return((void **)width_str, (void **)height_str, NULL, NULL);
}

int		ft_parse_r(char *line, t_all *all, char *width_str, char *height_str)
{
	int		i;

	if (ft_parse_r_init(all, &i, &width_str, &height_str) == TRUE)
		return (TRUE);
	while (line[i] == ' ')
		i++;
	while (line[i] && line[i] != ' ')
	{
		if (ft_is_number(line[i]) == FALSE)
			return (ft_free_and_return((void **)&width_str, NULL, NULL, NULL));
		ft_add_char(&width_str, line[i]);
		i++;
	}
	while (line[i] == ' ')
		i++;
	while (line[i] && line[i] != ' ')
	{
		if (ft_is_number(line[i]) == FALSE)
			return (ft_free_and_return((void **)&width_str,
			(void **)&height_str, NULL, NULL));
			ft_add_char(&height_str, line[i]);
		i++;
	}
	ft_parse_r_finish(all, &width_str, &height_str);
	return (FALSE);
}

int		ft_im_last_readed(t_all *all)
{
	if (all->data.window_width == 0 || all->data.window_height == 0 ||
	all->data.c_color == -1 || all->data.f_color == -1)
		return (FALSE);
	if (all->data.path_texture_no == NULL ||
			all->data.path_texture_so == NULL ||
			all->data.path_texture_we == NULL ||
			all->data.path_texture_ea == NULL ||
			all->data.path_texture_s == NULL)
		return (FALSE);
	return (TRUE);
}

void	ft_init_array(t_all *all)
{
	int i;

	i = 0;
	while (i < all->map.height)
	{
		all->map.array[i] = NULL;
		i++;
	}
}
