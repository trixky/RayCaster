#include "ray_caster.h"

void	ft_deplacement(t_all *all, int mod)
{
	int dir_dep;

	dir_dep = all->player.direction;
	if (mod == RIGHT)
		dir_dep += 90;
	else if (mod == BACK)
		dir_dep += 180;
	else if (mod == LEFT)
		dir_dep += 270;
	if (dir_dep < 0)
		dir_dep += 360;
	else if (dir_dep > 360)
		dir_dep -= 360;
	infinit_rot_player(all, dir_dep);
	ft_deplacement_limitation(all);
}

float	ft_absolute_float(float nbr)
{
	if (nbr < (float)0)
		nbr = -nbr;
	return (nbr);
}

int		ft_limit(int nbr, int limit)
{
	if (nbr >= limit)
		return (limit);
	if (nbr < 0)
		return (0);
	return (nbr);
}

void	*ft_free(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	return (NULL);
}

char	*ft_generate_empty_str(void)
{
	char *str;

	if ((str = malloc(sizeof(char) * 1)) == NULL)
		return (NULL);
	*str = '\0';
	return (str);
}
