/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:24:38 by Xecca             #+#    #+#             */
/*   Updated: 2019/11/17 11:23:42 by Xecca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_unsigned(size_t n)
{
	char 	ch;
	char	*str;

	str = NULL;
	if (n >= 10)
		str = ft_itoa_unsigned(n / 10);
	ch = n % 10 + '0';
	return (ft_straddchar(str, ch));
}

char	*ft_itoa_long(long n)
{
	
	if (n < 0)
	{
		n = -n;
		return (ft_strjoin_free("-", ft_itoa_unsigned(n), 2));
	}
	else
		return (ft_itoa_unsigned(n));
}