#include "stdio.h"
#include "libft.h"

int ft_printf(char *str, ...)
{
	va_list ap;

	va_start(ap, str);
	va_arg(ap, str[0]);
	va_arg(ap, str[0]);
	va_arg(ap, str[0]);
	va_end(ap);
	return 0;
}

int main()
{
	ft_printf("%s", "fhfu");
}