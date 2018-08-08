#include "ft_printf.h"

/*
** @brief Reset buffer if size + len >= BUFFER_SIZE
** @param core
** @param len
*/

void			reset_buffer(t_core *core, size_t len)
{
	size_t		size;

	size = ft_strlen(core->buffer);
	if ((size + len) >= BUFFER_SIZE)
	{
		write(core->fd, core->buffer, ft_strlen(core->buffer));
		ft_bzero(core->buffer, BUFFER_SIZE);
	}
}

/*
** @brief
** @param core
** @param str
*/

void			ft_core(t_core *core, char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			reset_buffer(core, 1);
			ft_strcat(core->buffer, str + i);
			i++;
		}
		else
			ft_flag(str, &i, core);
	}
}
