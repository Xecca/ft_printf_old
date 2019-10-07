/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aponomar <aponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:06:27 by aponomar          #+#    #+#             */
/*   Updated: 2019/08/27 20:28:47 by aponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sfill(char const *s, char **str, int wdcount, char c)
{
	int	j;
	int	r;
	int	ch_count;

	r = 0;
	while (wdcount--)
	{
		ch_count = ft_chcount(s, c);
		while (*s == c)
			s++;
		while (ch_count > 0)
		{
			j = 0;
			str[r] = (char*)malloc(ch_count + 1);
			while (ch_count--)
			{
				str[r][j++] = *s;
				s++;
			}
			str[r][j] = '\0';
			r++;
		}
	}
	str[r] = NULL;
	return (str);
}
