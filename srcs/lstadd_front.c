#include "ray_caster.h"

void	ft_lstadd_front(t_obj **alst, t_obj *new)
{
	if (new == NULL)
		return ;
	if (alst == NULL)
		new->next = NULL;
	else
		new->next = *alst;
	*alst = new;
}
