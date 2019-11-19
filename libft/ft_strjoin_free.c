/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:38:08 by Xecca             #+#    #+#             */
/*   Updated: 2019/11/18 20:16:56 by Xecca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// det - free's detector:
// 0 - none of the strings are freed
// 1 - s1 must be free
// 2 - s2 must be free
// 3 - must be free s1 and s2

#include "libft.h"

char    *ft_strjoin_free(char *s1, char *s2, int det)
{
    char    *str;
    size_t  length;
    
    if (s1 == NULL || s2 == NULL)
        return (NULL);
    length = ft_strlen(s1) + ft_strlen(s2);
    if (!(str = ft_strnew(length)))
        return (NULL);
    ft_strcat(str, s1);
    ft_strcat(str, s2);
    if (det == 1 || det == 3)
        free(s1);
    if (det == 2 || det == 3)
        free(s2);
    return (str);
}
