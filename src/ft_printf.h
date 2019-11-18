/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:57:59 by dreik             #+#    #+#             */
/*   Updated: 2019/11/18 16:18:53 by Xecca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct		s_spec
{
	unsigned char	spec;		/* format specifiers */
	// *Start* The length sub-specifier modifies the length of the data type.
	unsigned char	h_mod;		/* %h modifier: with d, i (short int); with u o x X (unsigned short int); with n (short int*) */
	unsigned char	l_mod;		/* A following integer conversion corresponds to a long int or unsigned long int argument, or a following n conversion corresponds to a pointer to a long int argument, or a following c conversion corresponds to a wint_t argument, or a following s conversion corresponds to a pointer to wchar_t argument. */
	unsigned char	j_mod;		/* A following integer conversion corresponds to an intmax_t or uintmax_t argument */
	unsigned char	z_mod;		/* A following integer conversion corresponds to a size_t or ssize_t argument. */
	unsigned char	hh_mod;		/* signed char	 / unsigned char */
	unsigned char	ll_mod;		/* long long int / unsigned long long int */
	// *End* sub-specifier modifies
	//	flags start
	unsigned char	minus;		// Left-justify within the given field width; Right justification is the default (see width sub-specifier).
	unsigned char	plus;		// Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers.
	unsigned char	space;		// If no sign is going to be written, a blank space is inserted before the value.
	unsigned char	hash;		// Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.
	unsigned char	null;		// Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).
	//	flags end
	unsigned char	filler; 	
	//	width start
	unsigned char	number;		// Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.
	unsigned char	asterisk;	// The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.
	//	width end
	
}					t_spec;

static char			*asterisk_constr(char *arg, char *dash, t_spec flags);
t_spec          	check_flags(const char *s);
char				*form_ident(t_spec *flags, va_list *ap);
static char			*ident_d_i(register t_spec flags, va_list *ap);
char				*int_constr(char *arg, t_spec flags, register char spec);
char				*str_constr(char *arg, register t_spec flags);

#endif
