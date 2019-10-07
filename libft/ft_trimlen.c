/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:30:50 by aponomar          #+#    #+#             */
/*   Updated: 2019/08/27 20:30:58 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_trimlen(const char *s)
{
	size_t	count;
	size_t	i;
	int		trim_len;

	count = 0;
	i = 0;
	if (ft_strlen(s) == 0)
		return (0);
	trim_len = ft_strlen(s) - 1;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		count++;
		i++;
	}
	i = trim_len;
	if (count == ft_strlen(s))
		return (0);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > 0)
	{
		count++;
		i--;
	}
	return (ft_strlen(s) - count);
}
