#include "ray_caster.h"

int	ft_close(t_all *all, int error_id)
{
	ft_print_error(error_id);
	if (error_id != 7 && error_id != 2)
		ft_free_map_array(all);
	if (error_id != 2)
	{
		ft_close_free_1(all);
		ft_close_free_2(all);
	}
	exit(0);
}
