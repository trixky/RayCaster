#include "cub3d.h"

int		ft_parse_no(char *line, t_all *all)
{
	int		i;
	char	*path_texture_no;

	i = 2;
	while (line[i] == ' ')
		i++;
	path_texture_no = NULL;
	while (line[i] && ft_is_whitespace(line[i]) == FALSE)
	{
		ft_add_char(&path_texture_no, line[i]);
		i++;
	}
	all->data.path_texture_no = path_texture_no;
	return (FALSE);
}

int		ft_parse_so(char *line, t_all *all)
{
	int		i;
	char	*path_texture_so;

	i = 2;
	while (line[i] == ' ')
		i++;
	path_texture_so = NULL;
	while (line[i] && ft_is_whitespace(line[i]) == FALSE)
	{
		ft_add_char(&path_texture_so, line[i]);
		i++;
	}
	all->data.path_texture_so = path_texture_so;
	return (FALSE);
}

int		ft_parse_we(char *line, t_all *all)
{
	int		i;
	char	*path_texture_we;

	i = 2;
	while (line[i] == ' ')
		i++;
	path_texture_we = NULL;
	while (line[i] && ft_is_whitespace(line[i]) == FALSE)
	{
		ft_add_char(&path_texture_we, line[i]);
		i++;
	}
	all->data.path_texture_we = path_texture_we;
	return (FALSE);
}

int		ft_parse_ea(char *line, t_all *all)
{
	int		i;
	char	*path_texture_ea;

	i = 2;
	while (line[i] == ' ')
		i++;
	path_texture_ea = NULL;
	while (line[i] && ft_is_whitespace(line[i]) == FALSE)
	{
		ft_add_char(&path_texture_ea, line[i]);
		i++;
	}
	all->data.path_texture_ea = path_texture_ea;
	return (FALSE);
}

int		ft_parse_s(char *line, t_all *all)
{
	int		i;
	char	*path_texture_s;

	i = 1;
	while (line[i] == ' ')
		i++;
	path_texture_s = NULL;
	while (line[i] && ft_is_whitespace(line[i]) == FALSE)
	{
		ft_add_char(&path_texture_s, line[i]);
		i++;
	}
	all->data.path_texture_s = path_texture_s;
	return (FALSE);
}
