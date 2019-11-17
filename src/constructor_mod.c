/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor_mod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:32:04 by Xecca             #+#    #+#             */
/*   Updated: 2019/11/17 21:08:06 by Xecca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*asterisk_constr(char *arg, char *dash, t_spec flags)
{
	char	*prec;	// .number (precision)
	int		aster;	// .* (precision)
	char	*str;

	prec = ft_strchr(arg, '.');
	if (flags.spec != 'f' || !prec)
	{
		aster = ft_strlen(arg);
		aster = (dash) ? aster - 1 : aster;
	}
	else
		aster = ft_strlen(prec) - 1;
	if (flags.asterisk > aster)
	{
		str = ft_strnew(flags.asterisk - aster);
		ft_memset(str, '0', flags.asterisk - aster);
		str = (flags.spec != 'f') ? ft_strjoin_free(str, arg, 3)\
		: ft_strjoin_free(arg, str, 3);
		if (dash)
			ft_swap(ft_strchr(str, '-'), str);
		return (str);
	}
	return (arg);
}

char		*int_constr(char *arg, t_spec flags, register char spec)
{
	char	*dash;

	flags.spec = spec;
	dash = ft_strchr(arg, '-');
	arg = asterisk_constr(arg, dash, flags);
	if (flags.hash || spec == 'p')
		arg = hash_constr(spec, arg, flags.asterisk);
	if (!flags.asterisk && !ft_strcmp(arg, "0") && (spec == 'x' || spec == 'o' || spec == 'd') && !(flags.hash && spec == 'o'))
		arg[0] = '\0';
	if (!dash && flags.plus && (spec == 'd' || spec == 'f'))
		arg = ft_strjoin_free("+", arg, 2);
	flags.filler = (flags.asterisk != -1 && spec != 'f') ? ' ' : flags.filler;
	arg = number_constr(arg, flags, ft_strlen(arg));
	return (arg);
}