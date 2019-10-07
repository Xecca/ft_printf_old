/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:40:38 by aponomar          #+#    #+#             */
/*   Updated: 2019/08/27 20:27:30 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		*(unsigned char*)dest = *(unsigned char*)src;
		if (*(unsigned char*)src == (unsigned char)c)
			return (++dest);
		dest++;
		src++;
		n--;
	}
	return (NULL);
}
