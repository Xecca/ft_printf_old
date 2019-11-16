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

int ft_printf(char *apFormat, ...)	/* Function return quantity characters (int), which was output. Function take undefined number of parameters. */
{
	va_list ap;             /* point on next unnamed argument.  */
	va_start(ap, apFormat); /* set 'ap' on 1-st unnamed argument */
	// int		flags;
	int		count;

	// flags = 0;
	count = 0;
// for (char *p = apFormat; *p; p++)
	// char *p;

	// p = apFormat;
	while (*apFormat != '\0')
	{
		if (*apFormat != '%')
		{
			ft_putchar(*apFormat);
			count++;
		}	
		apFormat++;
		if (*apFormat == 'd')
		{
			int ival = 0;
			ival = va_arg(ap, int);
			// printf ("%d", ival);
			ft_putnbr(ival);
			// flags = 0;
		}
		else if (*apFormat == 'f')
		{
			double dval = 0.;
			dval = va_arg(ap, double);
			ft_putnbr(dval);
			// printf("%f", dval);
			// ft_putdouble(dval);
			// flags = 0;
		}
		else if (*apFormat == 's')
		{
			char *sval = va_arg(ap, char *);
			ft_putstr(sval);
		}
		else if (*apFormat != '\0' && *apFormat != '%')
			ft_putchar(*apFormat);
		if (*apFormat != '%')
			apFormat++;
		count++;
	}
	va_end(ap); /* clean all */
	return (count);
}

// void example_b()
// {
// 	ft_printf("%d %f %s \n", 11, 12.12f, "Hello");
// }


// int main()
// {
// 	// char *str = "sdfsfsd";
// 	//char *str2;
// 	// int i = 10;
// 	// int j = 5;
// 	//print_numbers(2, i, j);
// 	// minprintf(str, i);
// 	example_b();
// 	printf("%d %f %s \n", 11, 12.12f, "Hello");

// 	printf("ostatok ot deleniya = %f", (13.64 / 10));

//     return (0);
// }
