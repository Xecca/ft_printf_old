/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constr_mod_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:14:28 by Xecca             #+#    #+#             */
/*   Updated: 2019/11/18 16:18:45 by Xecca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_constr(char *arg, register t_spec flags)
{
	char	*str;
	int		length;

	length = ft_strlen(arg);
	if (flags.asterisk != -1 && flags.asterisk < length && flags.spec != '%')
	{
		arg[flags.asterisk] = '\0';
		length = flags.asterisk;
	}
	if (length < flags.number)
	{
		str = ft_strnew(flags.number - length);
		ft_memset(str, flags.filler, flags.number - length);
		arg = (flags.minus) ?\
		ft_strjoin_free(arg, str, 3) : ft_strjoin_free(str, arg, 3);
	}
	return (arg);
}