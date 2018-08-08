#include "ft_printf.h"

/*
** @brief
** @param c
** @param core
** @return true|false
*/

static bool		ft_is_flag(char c, t_core *core)
{
	if (c == ' ')
		core->t_flags->flag_space = true;
	else if (c == '+')
		core->t_flags->flag_plus = true;
	else if (c == '-')
		core->t_flags->flag_less = true;
	else if (c == '#')
		core->t_flags->flag_zero = true;
	else if (c == '0')
		core->t_flags->flag_sharp = true;
	else
		return (false);
	return (true);
}

/*
** @brief
** @param str
** @param i
** @param core
*/

void			ft_flag(char *str, int *i, t_core *core)
{
	while (str[*i])
	{
		if (ft_is_flag(str[*i], core) != 1)
		{
			ft_precision(str, i, core);
			return ;
		}
		(*i)++;
	}
}
