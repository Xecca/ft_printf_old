/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:02:09 by Xecca             #+#    #+#             */
/*   Updated: 2019/11/19 19:47:26 by Xecca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_flag(register char ch)
{
	if (ch == ' ' || ch == '#' || ch == '+'\
	|| ch == '-' || ch == '0')
		return (1);
	return (0);
}

static void		flag_analazer_first(t_spec *flags, const char *s)
{
	flags->asterisk = -1;
	while (is_flag(s[flags->stage]))
	{
		if (s[flags->stage] == '#')
			flags->hash = 1;
		if (s[flags->stage] == '-')
			flags->minus = 1;
		if (s[flags->stage] == ' ')
			flags->space = 1;
		if (s[flags->stage] == '+')
			flags->plus = 1;
		if (s[flags->stage] == '0')
			flags->null = 1;
		flags->stage++;
	}
	if (flags->minus)
		flags->null = 0;
	if (flags->plus)
		flags->space = 0;
	flags->filler = (flags->null) ? '0' : ' ';
}

static void		flag_analazer_second(t_spec *flags, const char *s)
{
	while (s[flags->stage] == 'l')
	{
		flags->l_mod = 1;
		flags->stage++;
	}
	while (s[flags->stage] == 'h')
	{
		flags->h_mod++;
		flags->stage++;
	}
	if (s[flags->stage] == 'L')
	{
		flags->ll_mod = 1;
		flags->stage++;
	}
	if (s[flags->stage] == 'j')
	{
		flags->j_mod = 1;
		flags->stage++;
	}
	if (s[flags->stage] == 'z')
	{
		flags->z_mod = 1;
		flags->stage++;
	}
}

t_spec          check_allflags(const char *s)
{
    t_spec flags;

	ft_bzero(&flags, sizeof(t_spec));
	if (*s == '\0')
		return (flags);
	flag_analazer_first(&flags, s);
	if (s[flags.stage] >= '1' && s[flags.stage] <= '9')
	{
		flags.asterisk = ft_atoi(&s[flags.stage]);
		while (s[flags.stage] >= '0' && s[flags.stage] <= '9')
			flags.stage++;
	}
	if (s[flags.stage] == '.')
	{
		flags.stage += (s[flags.stage] == '.') ? 1 : 0;
		flags.asterisk = ft_atoi(&s[flags.stage]);
		while (s[flags.stage] >= '0' && s[flags.stage] <= '9')
			flags.stage++;
	}
	flag_analazer_second(&flags, s);
	flags.spec = s[flags.stage++];
	return (flags);
}