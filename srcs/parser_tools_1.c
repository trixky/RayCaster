#include "cub3d.h"

void	ft_init_is_readed(int is_readed[8])
{
	int i;

	i = 0;
	while (i < 8)
	{
		is_readed[i] = 0;
		i++;
	}
}

int		ft_exit_parser(int fd, char ***line)
{
	close(fd);
	if (line != NULL)
		if (*line != NULL)
		{
			if (**line != NULL)
				free(**line);
			free(*line);
		}
	return (TRUE);
}

int		ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int		ft_is_whitespace(char c)
{
	if (c >= 9 && c <= 13)
		return (TRUE);
	return (FALSE);
}
