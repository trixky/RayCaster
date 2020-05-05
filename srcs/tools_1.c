#include "cub3d.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

float	ft_degree_to_rad(float degree)
{
	float	rad;

	rad = degree * (M_PI / (float)180);
	return (rad);
}

float	ft_rad_to_degree(float rad)
{
	float	degree;

	degree = rad / (M_PI / (float)180);
	return (degree);
}

float	ft_next_block_distance(float position, int mod)
{
	if (mod == INF)
	{
		if (position == (float)((int)position))
			return (1);
		return (position - (int)position);
	}
	if (mod == SUP)
	{
		if (position == (float)((int)position))
			return (1);
		return (1 - (position - (int)position));
	}
	return (333);
}

float	ft_cut_float(float nbr)
{
	int cutter;

	cutter = (int)nbr;
	return (float)(cutter);
}
