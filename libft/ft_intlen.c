/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:00:56 by aponomar          #+#    #+#             */
/*   Updated: 2019/08/27 20:26:25 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n)
{
	int		count;
	int		len_n;

	count = 0;
	len_n = n;
	if (len_n < 0)
	{
		len_n = len_n * -1;
		count++;
	}
	if (len_n == 0)
	{
		count++;
		len_n = 1;
	}
	while (len_n > 0)
	{
		len_n = len_n / 10;
		count++;
	}
	return (count);
}
