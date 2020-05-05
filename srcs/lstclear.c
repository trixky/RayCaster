#include "ray_caster.h"

void	ft_lstclear(t_obj **lst)
{
	t_obj *temp;
	t_obj *next;

	if (lst == NULL || *lst == NULL)
		return ;
	next = *lst;
	while (next)
	{
		temp = next;
		next = temp->next;
		free(temp);
		temp = NULL;
	}
	*lst = NULL;
}
