#include <stdio.h>
#include "functions.h"

int main()
{
	int i;

	i = 7;
	print_hello();
	printf("The factorial of %d is %d", i, factorial(i));
	
	return (0);
}
