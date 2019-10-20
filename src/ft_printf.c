/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:53:13 by Xecca             #+#    #+#             */
/*   Updated: 2019/10/18 15:53:14 by Xecca            ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

// change my email

#include "ft_printf.h"
#include <stdarg.h>

// void print_numbers( size_t amount, ... ) {

//     va_list ap;
//     int number;
//     va_start( ap, amount );

//     printf( "Total numbers: %zu, let's go! ", amount );
//     while(amount--) {
//         number = va_arg( ap, int );
// 		ft_putnbr(number);
//         //printf( " [%d]", number );
//     }

//     va_end( ap );
// }

void ft_printf(char *apFormat, ...)
{
	va_list ap;             /* point on next unnamed argument */
	va_start(ap, apFormat); /* set 'ap' on 1-st unnamed argument */
	int		flag;

	flag = 0;
// for (char *p = apFormat; *p; p++)
	char *p;

	p = apFormat;
	while (*p != '\0')
	{
		if (*p == '%')
			flag = 1;
		else
			ft_putchar(*p);
		p++;
		if (*p == 'd' && flag == 1)
		{
			int ival = 0;
			ival = va_arg(ap, int);
			// printf ("%d", ival);
			ft_putnbr(ival);
			flag = 0;
		}
		else if (*p == 'f' && flag == 1)
		{
			double dval = 0.;
			dval = va_arg(ap, double);
			ft_putnbr(dval);
			// printf("%f", dval);
			// ft_putdouble(dval);
			flag = 0;
		}
		else if (*p == 's' && flag == 1)
		{
			char *sval = va_arg(ap, char *);
			ft_putstr(sval);
		}
		else if (*p != '\0' && *p != '%')
			ft_putchar(*p);
		if (*p != '%')
			p++;
	}
	va_end(ap); /* clean all */
}

void example_b()
{
	ft_printf("%d %f %s \n", 11, 12.12f, "Hello");
}


int main()
{
	// char *str = "sdfsfsd";
	//char *str2;
	// int i = 10;
	// int j = 5;
	//print_numbers(2, i, j);
	// minprintf(str, i);
	example_b();
	printf("%d %f %s \n", 11, 12.12f, "Hello");

    return (0);
}
