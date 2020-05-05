#include "ray_caster.h"

t_obj	*ft_lstnew(t_all *all, float x, float y, char c)
{
	int		d;
	float	temp_len;
	t_obj	*new_element;

	if ((new_element = malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	new_element->pos_x = x;
	new_element->pos_y = y;
	d = (double)(clock() - all->start_clock) / 100000;
	if (c == '2')
		new_element->w_ob = &all->object;
	else if (c == '5')
		new_element->w_ob = &all->object_2;
	else if (d % 2 == 0)
		new_element->w_ob = &all->object_b;
	else
		new_element->w_ob = &all->object_bb;
	temp_len = sqrt(pow(all->player.pos_x - x, 2) +
		pow(y - all->player.pos_y, 2));
	if (temp_len < all->fsc.closest_lenght_obj)
		all->fsc.closest_lenght_obj = temp_len;
	new_element->next = NULL;
	return (new_element);
}
