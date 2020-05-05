#include "ray_caster.h"

int	ft_is_map_char(char c)
{
	if (c == 'N' ||
			c == 'S' ||
			c == 'E' ||
			c == 'W' ||
			c == '0' ||
			c == '1' ||
			c == '2' ||
			c == '3' ||
			c == '4' ||
			c == '5')
		return (TRUE);
	return (FALSE);
}

int	ft_is_pole(t_all *all, char c, int x, int y)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (all->player.direction != -2)
			return (TRUE);
		all->player.pos_x = x + 0.500000;
		all->player.pos_y = y + 0.500000;
	}
	if (c == 'N')
		all->player.direction = 90;
	else if (c == 'S')
		all->player.direction = 270;
	else if (c == 'E')
		all->player.direction = 0;
	else if (c == 'W')
		all->player.direction = 180;
	return (FALSE);
}

int	ft_set_line_map(t_all *all, char *str, int *line)
{
	static int	appel = 0;
	int			i;
	int			x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			if (ft_is_map_char(str[i]) == FALSE || (ft_is_pole(all,
					str[i], x, appel) && all->player.direction != -2))
				return (TRUE);
			if (str[i] == 'N' || str[i] == 'S' ||
					str[i] == 'E' || str[i] == 'W')
				line[x] = 0;
			else
				line[x] = (int)(str[i] - 48);
			x++;
		}
		i++;
	}
	appel++;
	return (FALSE);
}
