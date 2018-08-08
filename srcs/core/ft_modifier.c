#include "ft_printf.h"

/*
** @brief
** @param core
** @param i
*/

void			ft_jump_i_to_next(t_core *core, int *i)
{
	if (core->t_modifier->hh == true)
		*i += 2;
	else if (core->t_modifier->h == true)
		*i += 1;
	else if (core->t_modifier->ll == true)
		*i += 2;
	else if (core->t_modifier->l == true)
		*i += 1;
	else if (core->t_modifier->j == true)
		*i += 1;
	else if (core->t_modifier->z == true)
		*i += 1;
}

/*
** @brief
** @param str
** @param core
** @param i
** @return true|false
** strncmp return 0 si str est a la fin
*/

bool			ft_is_a_modifier(char *str, t_core *core, int i)
{
	if (str[i + 2])
	{
		if (ft_strncmp(str, "hh", 2) == 0)
			core->t_modifier->hh = true;
		else if (ft_strncmp(str, "ll", 2) == 0)
			core->t_modifier->ll = true;
	}
	else if (str[i + 1])
	{
		if (ft_strncmp(str, "h", 1) == 0)
			core->t_modifier->h = true;
		else if (ft_strncmp(str, "l", 1) == 0)
			core->t_modifier->l = true;
		else if (ft_strncmp(str, "j", 1) == 0)
			core->t_modifier->j = true;
		else if (ft_strncmp(str, "z", 1) == 0)
			core->t_modifier->z = true;
	}
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

void			ft_modifier(char *str, int *i, t_core *core)
{
	if (ft_is_a_modifier(str, core, *i) == 0)
		return ;
	ft_jump_i_to_next(core, i);
	//TODO appeler ft_type
}
