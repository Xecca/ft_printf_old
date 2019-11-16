/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_identifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:47:24 by Xecca             #+#    #+#             */
/*   Updated: 2019/11/17 00:31:05 by Xecca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// printf formatting is controlled by 'format identifiers' which, are shown below in their simplest form:

//  %d %i		Decimal signed integer.
//     %o		Octal integer.
//     %x %X	Hex integer.
//     %u		Unsigned integer.
//     %c		Character.
//     %s		String. See below.
//     %f		double
//     %e %E	double.
//     %g %G	double.
//     %p		pointer.
//     %n		Number of characters written by this printf.
//              No argument expected.
//     %%		%. No argument expected.

// %d and %i

static char	*ident_d_i(register t_iden flags, va_list *ap)
{
	char	*s;

	s = NULL;
	if (flags.ident == 'd' || flags.ident == 'i')
	{
		if (flags.h_spec == 1)
			ft_itoa((short)va_arg(*ap, int));
		else if (flags.h_spec == 2)
			s = ft_itoa((signed int)va_arg(*ap, int));
		
			
	}
		
	{}
	return (s);
}

char		*form_ident(t_iden *flags, va_list *ap)
{
	char	*s;

	s = NULL;
	if (flags->ident == 'd' || flags->ident == 'i')
		s = ident_d_i(*flags, ap);
}