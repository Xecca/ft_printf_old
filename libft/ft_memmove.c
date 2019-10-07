/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:40:51 by aponomar          #+#    #+#             */
/*   Updated: 2019/08/27 20:28:06 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*d;
	const char	*d1;
	char		*s;
	char		*s1;

	if (src == NULL && dst == NULL)
		return (NULL);
	s = dst;
	d = src;
	if (s < d)
	{
		while (len--)
			*s++ = *d++;
	}
	else
	{
		d1 = d + (len - 1);
		s1 = s + (len - 1);
		while (len--)
			*s1-- = *d1--;
	}
	return (dst);
}
