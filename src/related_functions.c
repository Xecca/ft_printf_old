/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   related_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:52:32 by Xecca             #+#    #+#             */
/*   Updated: 2019/11/18 16:52:44 by Xecca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		putstr_for_null_char(char *s)
{
	size_t i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == '@')
				ft_putchar('^');
			ft_putchar(s[i++]);
		}
	return (i);
}