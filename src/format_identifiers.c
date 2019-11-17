/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_identifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:47:24 by Xecca             #+#    #+#             */
/*   Updated: 2019/11/17 21:24:14 by Xecca            ###   ########.fr       */
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

static char	*ident_d_i(register t_spec flags, va_list *ap)
{
	char	*s;

	s = NULL;
	if (flags.spec == 'd' || flags.spec == 'i')
	{
		if (flags.h_mod == 1)
			s = ft_itoa((short)va_arg(*ap, int));
		else if (flags.h_mod == 2)
			s = ft_itoa((signed char)va_arg(*ap, int));
		else if (flags.l_mod || flags.j_mod || flags.z_mod)
			s = ft_itoa_long(va_arg(*ap, long));
		else
			s = ft_itoa(va_arg(*ap, int));
		s = int_constr(s, flags, 'd');
	}
	return (s);
}

char		*form_ident(t_spec *flags, va_list *ap)
{
	char	*s;

	s = NULL;
	if (flags->spec == 'd' || flags->spec == 'i')
		s = ident_d_i(*flags, ap);
}