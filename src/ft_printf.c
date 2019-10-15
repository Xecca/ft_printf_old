/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreik <dreik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:57:45 by dreik             #+#    #+#             */
/*   Updated: 2019/10/15 18:46:12 by dreik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// for (char *p = apFormat; *p; p++)
	char *p;

	p = apFormat;
	while (*p)
	{
	if (*p !='%')
	{
		putchar(*p);
	}
	else if (*p == 'd')
	{
		int ival = 0;
		ival = va_arg(ap, int);
		printf ("%d", ival);
	}
	else if (*p == 'f')
	{
	double  dval = 0.;
	dval = va_arg(ap, double);
	printf("%f", dval);
	}
	else if (*p == 's')
	{
	//for for rebuild
	
	for(char *sval = va_arg(ap, char *); *sval; sval++)
		putchar(*sval);
	}
	else
		putchar(*p);
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
	printf("\n");
	printf("%d %f %s \n", 11, 12.12f, "Hello");

    return (0);
}
