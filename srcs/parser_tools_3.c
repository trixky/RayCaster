#include "ray_caster.h"

int		ft_parse_color(char *str, int *index, int j)
{
	int i;
	int	part_color;

	i = 0;
	part_color = 0;
	while (i < 4)
	{
		if (str[i] == ',')
		{
			if (i == 0 || j == 0)
				return (-1);
			*index = *index + 1;
			return (part_color);
		}
		if (ft_is_number(str[i]) == FALSE && (j != 0 || i == 0))
			return (-1);
		if (ft_is_number(str[i]) == FALSE && (j == 0 && i != 0))
			return (part_color);
		part_color *= 10;
		part_color += str[i] - 48;
		i++;
		*index = *index + 1;
	}
	return (part_color);
}

int		ft_parse_f(char *line, t_all *all)
{
	int i;
	int j;
	int ret;
	int	final_color;

	i = 2;
	j = 2;
	final_color = 0;
	if (all->data.f_color != -1)
		return (TRUE);
	while (line[i] == ' ')
		i++;
	while (j >= 0)
	{
		if ((ret = ft_parse_color(line + i, &i, j)) < 0)
			return (TRUE);
		final_color += (ret << j * 8);
		j--;
	}
	all->data.f_color = final_color;
	return (FALSE);
}

int		ft_parse_c(char *line, t_all *all)
{
	int i;
	int j;
	int ret;
	int	final_color;

	i = 2;
	j = 2;
	final_color = 0;
	if (all->data.c_color != -1)
		return (TRUE);
	while (line[i] == ' ')
		i++;
	while (j >= 0)
	{
		if ((ret = ft_parse_color(line + i, &i, j)) < 0)
			return (TRUE);
		final_color += (ret << j * 8);
		j--;
	}
	all->data.c_color = final_color;
	return (FALSE);
}
