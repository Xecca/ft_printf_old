/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 19:56:27 by aponomar          #+#    #+#             */
/*   Updated: 2019/08/27 20:30:29 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	char	temp;
	int		b;
	int		i;

	b = 0;
	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= b)
	{
		temp = str[b];
		str[b] = str[i];
		str[i] = temp;
		b++;
		i--;
	}
	return (str);
}
