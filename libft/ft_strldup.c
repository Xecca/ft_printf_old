/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 19:13:53 by aponomar          #+#    #+#             */
/*   Updated: 2019/08/27 20:29:44 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strldup(void const *s, size_t l)
{
	void	*res;
	size_t	i;

	res = malloc(l);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (l > 0)
	{
		((char*)res)[i] = ((char*)s)[i];
		i++;
		l--;
	}
	return (res);
}
