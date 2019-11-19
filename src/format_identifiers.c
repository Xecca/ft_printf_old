/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_identifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:47:24 by Xecca             #+#    #+#             */
/*   Updated: 2019/11/18 19:06:24 by Xecca            ###   ########.fr       */
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

// %s and %c
static char	*ident_s_c(t_spec *flags, va_list *ap)
{
	char *s;
	char ch;

	s = NULL;
	if (flags->spec == 's')
	{
		s = va_arg(*ap, char *);
		s = (s) ? str_constr(ft_strdup(s), *flags) :\
		str_constr(ft_strdup("(null)"), *flags);
	}
	else if (flags->spec == 'c')
	{
		ch = (char)va_arg(*ap, int);
		if (ch)
			s = str_constr(ft_straddchar(NULL, ch), *flags);
		else
		{
			s = str_constr(ft_strdup("@"), *flags);
			flags->spec = 'N';
		}
	}
	return (s);
}

// %f, %x and %X
static char *ident_f_xX(t_spec flags, va_list *ap)
{
	char *s;

	s = NULL;
	if (flags.spec == 'f')
	{
		flags.asterisk = (flags.asterisk == -1) ? 6 : flags.asterisk;
		if (flags.ll_mod)
			s = int_constr(ft_ftoa_long(va_arg(*ap, long double),\
			flags.asterisk), flags, 'f');
		else
			s = int_constr(ft_ftoa(va_arg(*ap, double), flags.asterisk), flags, 'f');
	}
	else if (flags.spec == 'X' || flags.spec == 'x')
	{
		s = (flags.j_mod || flags.l_mod) ?\
		int_constr(ft_itoa_base_unsigned(va_arg(*ap, size_t), 16), flags, 'x')\
		: int_constr(ft_itoa_base(va_arg(*ap, int), 16), flags, 'x');
		if (flags.spec == 'X')
			ft_strupper(s);
	}
	return (s);
}

// %u
static char	*ident_u_U(register t_spec flags, va_list *ap)
{
	char	*s;
	
	s = NULL;
	if (flags.spec == 'u' || flags.j_mod || flags.l_mod || flags.z_mod)
		s = ft_itoa_unsigned(va_arg(*ap, unsigned int));
	else if (flags.spec == 'U' || flags.j_mod || flags.l_mod || flags.z_mod)
		s = ft_itoa_unsigned(va_arg(*ap, unsigned long));
	s = int_constr(s, flags, 'u');
	return (s);
}

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
	else if (flags->spec == 'o')
		s = int_constr(ft_itoa_base(va_arg(*ap, int), 8), *flags, 'o');
	else if (flags->spec == 'X' || flags->spec == 'x' || flags->spec == 'f')
		s = ident_f_xX(*flags, ap);
	else if (flags->spec == 'u')
		s = ident_u_U(*flags, ap);
	else if (flags->spec == 's' || flags->spec == 'c')
		s = ident_s_c(flags, ap);
	else if (flags->spec == 'p')
		s = int_constr(ft_itoa_base_unsigned(va_arg(*ap, size_t), 16),\
		*flags, 'p');
	else if (flags->spec == '%')
		s = str_constr(ft_strdup("%"), *flags);
	else if (flags->spec == 'b')
		s = int_constr(ft_itoa_base(va_arg(*ap, int), 2), *flags, 'o');
	else if (flags->spec == '\0')
		return (NULL);
	else
		s = str_constr(ft_strdup(""), *flags);
	return (s);
}