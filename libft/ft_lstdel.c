/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:51:48 by aponomar          #+#    #+#             */
/*   Updated: 2019/08/27 20:27:01 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *ch;

	lst = *alst;
	ch = *alst;
	while (ch != NULL)
	{
		(*del)(lst->content, lst->content_size);
		lst = ch->next;
		free(ch);
		ch = lst;
	}
	*alst = NULL;
}
