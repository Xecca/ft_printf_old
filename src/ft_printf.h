/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:57:59 by dreik             #+#    #+#             */
/*   Updated: 2019/11/16 22:41:02 by Xecca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_flag
{
		void		*ap;
		char		*fmt;
}				t_flag;

#endif
