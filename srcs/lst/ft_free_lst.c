#include <ft_printf.h>

void		free_all_struct(t_core *core)
{
	free(core->t_flags);
	free(core->t_type);
	free(core->t_modifier);
	ft_bzero(core->buffer, BUFFER_SIZE);
	free(core);
}