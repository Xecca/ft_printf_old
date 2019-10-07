/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intrevstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:46:28 by aponomar          #+#    #+#             */
/*   Updated: 2019/08/27 20:26:29 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_intrevstr(int n, int count, int sign)
{
	int		len_n;
	char	*str;
	int		i;

	i = 0;
	if (sign == -1)
		n = n * sign;
	len_n = n;
	str = (char*)malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	while (count + sign > 0)
	{
		n = n % 10;
		len_n = len_n / 10;
		str[i] = (n + 48);
		i++;
		count--;
		n = len_n;
	}
	if (sign == -1)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
