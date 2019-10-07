/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:52:27 by aponomar          #+#    #+#             */
/*   Updated: 2019/08/27 20:27:13 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *swap;

	if (!lst)
		return (NULL);
	new_lst = f(lst);
	swap = new_lst;
	while (lst->next)
	{
		lst = lst->next;
		if ((new_lst->next = f(lst)) == NULL)
		{
			free(new_lst);
			return (NULL);
		}
		new_lst = new_lst->next;
	}
	return (swap);
}
