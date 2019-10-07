/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:49:11 by aponomar          #+#    #+#             */
/*   Updated: 2019/08/27 20:26:53 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		count;
	int		len_n;

	count = 0;
	sign = 0;
	str = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < -2147483648 || n > 2147483647)
		return (str = "0");
	if (n == 0)
	{
		count++;
		len_n = 1;
	}
	if (n < 0)
		sign = -1;
	len_n = ft_intlen(n);
	if (n != 0)
		count = count + len_n;
	str = ft_intrevstr(n, count, sign);
	return (str);
}
