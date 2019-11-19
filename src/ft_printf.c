/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:53:13 by Xecca             #+#    #+#             */
/*   Updated: 2019/10/18 15:53:14 by Xecca            ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

// change my email

#include "ft_printf.h"

int			ft_printf(const char *apFormat, ...)	/* Function return quantity characters (int), which was output. Function take undefined number of parameters. */
{
	va_list ap;             /* point on next unnamed argument.  */
	int		count;
	t_spec	flags;
	char	*p;

	count = 0;
	va_start(ap, apFormat); /* set 'ap' on 1-st unnamed argument */
	while (*apFormat != '\0')
	{
		if (*apFormat != '%' && *apFormat != '\0')
		{
			ft_putchar(*apFormat++);
			count++;
			continue;
		}	
		flags = (*apFormat) ? check_allflags(++apFormat) : check_allflags(apFormat);
		if (!(p = form_ident(&flags, &ap)))
			continue;
		apFormat += flags.stage;
		count += (flags.spec != 'N') ? ft_putstr(p) : putstr_for_null_char(p);
		ft_strdel(&p);
	}
	va_end(ap); /* clean all */
	return (count);
}
