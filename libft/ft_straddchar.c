/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:12:02 by Xecca             #+#    #+#             */
/*   Updated: 2019/11/17 11:29:13 by Xecca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char        *ft_straddchar(char *str, char ch)
{
    int     length;
    char    *new;

    length = 0;
    if (str)
    {
        length = ft_strlen(str);
		if ((new = (char*)ft_strnew(length + 1)) == NULL)
			return (NULL);
        ft_strcat(new, str);
        ft_strdel(&str);
    }
    else
        new = ft_strnew(1);
    new[length] = ch;
    new[length + 1] = '\0';
    return (new);
}
