/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:27:11 by Xecca             #+#    #+#             */
/*   Updated: 2019/11/18 15:18:38 by Xecca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	aux(int i)
{
	char *numb;

	numb = "0123456789abcdef";
	return (numb[i]);
}

char		*ft_itoa_base(unsigned int n, int base)
{
	char ch;
	char *str;

	str = NULL;
	if (n >= (unsigned int)base)
		str = ft_itoa_base(n / base, base);
	ch = aux((n % base));
	return (ft_straddchar(str, ch));
}

char		*ft_itoa_base_unsigned(size_t n, int base)
{
	char ch;
	char *str;

	str = NULL;
	if (n >= (size_t)base)
		str = ft_itoa_base_unsigned(n / base, base);
	ch = aux(n % base);
	return (ft_straddchar(str, ch));
}