#include "ft_printf.h"

/*
** @brief
** @param nb
** @return [int] rank
*/

int				ft_return_rank(int nb)
{
	int			rank;

	rank = 0;
	while (nb > 0)
	{
		nb /= 10;
		rank++;
	}
	return (rank);
}

/*
** @brief
** @param str
** @param i
** @param core
** Ouaip ya trop moyen de l'optimiser mais je l'ai fait en one shot xD
*/

void			ft_precision(char *str, int *i, t_core *core)
{
	int			tmp;
	int			jump;

	tmp = ft_atoi(str + *i + 1);
	jump = ft_return_rank(tmp);
	*i += jump;
	if (jump == 0 && str[*i + 1] && str[*i] == '.')
		core->padding = 0;
	else if (jump > 0 && str[*i + jump] && str[*i + jump] == '.')
		core->padding = tmp;
	if ((jump > 0 && str[*i + jump] && str[*i + jump] == '.') \
	|| (jump == 0 && str[*i + 1] && str[*i] == '.'))
	{
		tmp = ft_atoi(str + *i + 1);
		core->precision = tmp;
		jump = ft_return_rank(tmp);
		*i += 1 + jump;
		ft_modifier(str, i, core);
	}
	else if (jump > 0 && str[*i + jump] && str[*i + jump] != '.')
		ft_modifier(str, i, core);
	else if (jump == 0 && str[*i] != '.')
		ft_modifier(str, i, core);
	else
		; //TODO fin de la chaine donc on remonte.
}
