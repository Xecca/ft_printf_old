/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:48:35 by aponomar          #+#    #+#             */
/*   Updated: 2019/11/18 20:25:51 by Xecca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*str_sum;
	size_t	sum_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	sum_len = ft_strlen(s1) + ft_strlen(s2);
	if ((str = (char*)malloc((sum_len) + 1)) == NULL)
		return (NULL);
	str_sum = str;
	while (*s1 != '\0')
	{
		*str = *s1;
		str++;
		s1++;
	}
	while (*s2)
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = '\0';
	return (str_sum);
}
