#include "ft_printf.h"

/*
** @brief
** @param str
** @param ...
** @return
*/

int		ft_printf(const char *str, ...)
{
	str = NULL;
	return (true);
}

/*
** @brief
** @param fd
** @param str
** @param ...
** @return
*/

int		ft_dprintf(int fd, const char *str, ...)
{
	str = NULL;
	if (fd >= 0 && fd <= 2)
		return (true);
	return (false);
}
