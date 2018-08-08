#include "ft_printf.h"

static t_flags 	*init_flags(void)
{
	t_flags		*flags;

	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (NULL);
	flags->flag_less = false;
	flags->flag_plus = false;
	flags->flag_sharp = false;
	flags->flag_sharp = false;
	flags->flag_zero = false;
	return (flags);
}

static t_type *init_type(void)
{
	t_type		*type;

	if (!(type = (t_type *)malloc(sizeof(t_type))))
		return (NULL);
	type->s = false;
	type->big_s = false;
	type->p = false;
	type->d = false;
	type->big_d = false;
	type->i = false;
	type->o = false;
	type->big_o = false;
	type->u = false;
	type->big_u = false;
	type->x = false;
	type->big_x = false;
	type->c = false;
	type->big_c = false;
	return (type);
}

static t_modifier *init_modifier(void)
{
	t_modifier *modifier;

	if (!(modifier = (t_modifier *)malloc(sizeof(t_modifier))))
		return (NULL);
	modifier->hh = false;
	modifier->h = false;
	modifier->l = false;
	modifier->ll = false;
	modifier->j = false;
	modifier->z = false;
	return (modifier);
}

t_core		*init_core(void)
{
	t_core *core;

	if (!(core = (t_core *)malloc(sizeof(t_core))))
		return (NULL);
	ft_bzero(core->buffer, BUFFER_SIZE);
	core->padding = false;
	core->precision = false;
	core->fd = 1;
	if (!(core->t_flags = init_flags()))
		return (NULL);
	if (!(core->t_type = init_type()))
		return (NULL);
	if (!(core->t_modifier = init_modifier()))
		return (NULL);
	return (core);
}
