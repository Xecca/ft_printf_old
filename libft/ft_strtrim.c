/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:36:11 by aponomar          #+#    #+#             */
/*   Updated: 2019/08/27 20:30:45 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	if ((ft_strlen(s) - ft_trimlen(s)) > 0)
	{
		str = ft_malloclen(s);
	}
	else
		str = ft_strdup(s);
	return (str);
}
