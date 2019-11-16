/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:57:59 by dreik             #+#    #+#             */
/*   Updated: 2019/11/17 00:27:48 by Xecca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct			s_iden
{
		unsigned char	ident;	/* format identifiers */
		unsigned char	h_spec;	/* %h specifier (short) */
		
}						t_iden;

#endif
