#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# define error	-1
# define BUFFER_SIZE 4096

typedef struct				s_flags
{
	bool					flag_plus;
	bool					flag_less;
	bool					flag_space;
	bool					flag_zero;
	bool					flag_sharp;
}							t_flags;

typedef struct				s_modifier
{
	bool					hh;
	bool					h;
	bool					l;
	bool					ll;
	bool					j;
	bool					z;
}							t_modifier;

typedef struct				s_type
{
	bool					s;
	bool					big_s;
	bool					p;
	bool					d;
	bool					big_d;
	bool					i;
	bool					o;
	bool					big_o;
	bool					u;
	bool					big_u;
	bool					x;
	bool					big_x;
	bool					c;
	bool					big_c;
}							t_type;

typedef struct				s_core
{
	char					buffer[BUFFER_SIZE];
	int						padding;
	int						precision;
	int						fd;
	struct s_flags			*t_flags;
	struct s_modifier		*t_modifier;
	struct s_type			*t_type;
}							t_core;
/*
** MODIFIER function
*/
void						ft_jump_i_to_next(t_core *core, int *i);
bool						ft_is_a_modifier(char *str, t_core *core, int i);
void						ft_modifier(char *str, int *i, t_core *core);
/*
** PRECISION function
*/
int							ft_return_rank(int nb);
void						ft_precision(char *str, int *i, t_core *core);
/*
** FLAGS function
*/
void						ft_flag(char *str, int *i, t_core *core);
/*
** CORE function
*/
void						ft_core(t_core *core, char *str);
void						reset_buffer(t_core *core, size_t len);
/*
** printf & dprinf function
*/
int							ft_printf(const char *str, ...);
int							ft_dprintf(int fd, const char *str, ...);
#endif
