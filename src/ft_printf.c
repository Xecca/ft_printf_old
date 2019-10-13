/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreik <dreik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:57:45 by dreik             #+#    #+#             */
/*   Updated: 2019/10/13 09:57:20 by dreik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void minprintf(char *fmt, ...)
{
    va_list ар;
    char *p;
	char *sval;
    int ival;
    double dval;
	
    va_start(ap, fmt);
    for (p = fmt; *р; р++) 
    {
        if (*p != '%') 
        {
            putchar(*p);
    		continue;
		}
    	switch (*++р) 
		{
            case 'd':
                ival = va_arg(ap, int);
                printf ("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
                break;
            default:
                putchar(*p);
    	break;
		}
	}
    va_end(ap); /* очистка, когда все сделано */
}

int main()
{
	char *str = "sdfsfsd \n";
	char *str2;
	int i = 10;
	int j = 5;
	minprintf(str, i);
	printf(str, i);

    return (0);
}
