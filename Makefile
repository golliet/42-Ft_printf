NAME 		= 	libftprintf.a

NAMECOLOR 	= 	\x1b[31m
COLOR 		= 	\x1b[36m
COLOROK 		= 	\x1b[32m
COLORFILE	= 	\x1b[35m
COLORRESET 	= 	\x1b[0m

SRCSDIR 		= 	srcs
SRCSDIR1 	= 	lst
SRCSDIR2 	= 	core

OBJSDIR 	= 	objects
LIBD      =   libft/libft.a
LIBFTDIR		=	libft
LIB			=	libft.a
INCLUDES 	= 	includes
HEADERLIB    =       $(LIBFTDIR)/$(INCLUDES)/
CFLAGS 		= 	-g -Wall -Werror -Wextra
CC 			= 	gcc $(CFLAGS)
HEADER		=	ft_printf.h
HEADERS		=	$(addprefix $(INCLUDES)/, $(HEADER))

SRCLST     =  	ft_init_lst.c ft_free_lst.c
SRCCORE		=	ft_printf.c ft_core.c ft_flags.c ft_modifier.c ft_precision.c


SRCSLST		= 	$(addprefix $(SRCSDIR1)/, $(SRCLST))
SRCSCORE		= 	$(addprefix $(SRCSDIR2)/, $(SRCCORE))

SRC 		=	$(SRCSLST) $(SRCSCORE)
OBJ 		= 	$(SRC:%.c=%.o)

SRCS 		= 	$(addprefix $(SRCSDIR)/, $(SRC))
OBJS 		= 	$(addprefix $(OBJSDIR)/, $(OBJ))

all:  $(LIBD) $(NAME)

$(NAME): $(OBJSDIR) $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(LIBD):
	@make -C $(LIBFTDIR)/

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c $(HEADERS)
	@tput dl; tput cub 100; printf "$(NAMECOLOR)$(NAME): $(COLOR)Compiling: $(COLORFILE)$<... $(COLOROK)done!"
	@$(CC) -c -o $@ $< -I$(INCLUDES) -I$(LIBFTDIR)/$(INCLUDES)

$(OBJSDIR):
	@if [ ! -d "$(OBJSDIR)/" ]; then \
		tput dl; tput cub 100; printf "$(NAMECOLOR)$(NAME): $(COLOR)Create objects dir...$(COLORRESET)"; \
		mkdir -p $(OBJSDIR)/$(SRCSDIR1); \
		mkdir -p $(OBJSDIR)/$(SRCSDIR2); \
		mkdir -p $(OBJSDIR)/$(SRCSDIR3); \
		mkdir -p $(OBJSDIR)/$(SRCSDIR4); \
		mkdir -p $(OBJSDIR)/$(SRCSDIR5); \
		mkdir -p $(OBJSDIR)/$(SRCSDIR6); \
		mkdir -p $(OBJSDIR)/$(SRCSDIR7); \
		mkdir -p $(OBJSDIR)/$(SRCSDIR8); \
	fi

clean:
	@tput dl; tput cub 100; printf "$(NAMECOLOR)$(NAME): $(COLOR)Removing objects dir...$(COLORRESET)";
	@/bin/rm -rf $(OBJSDIR);
	@make clean -C $(LIBFTDIR)

fclean: clean
	@tput dl; tput cub 100; printf "$(NAMECOLOR)$(NAME): $(COLOR)Deleting...$(COLORRESET)"
	@/bin/rm -f $(NAME)
	@if [ -d $(LIBDIR) ]; then \
		/bin/rm -rf $(LIBDIR); \
	fi
	@make fclean -C $(LIBFTDIR)
	@rm -rf $(NAME).dSYM
	@rm -rf ft_printf.dSYM

re: fclean all

test:
	gcc -g3 -Wall -Werror -Wextra libftprintf.a libft/libft.a srcs/main.c \
	 -I$(INCLUDES) -I$(LIBFTDIR)/$(INCLUDES) -o ft_printf


.PHONY: all, clean, fclean, re, $(LIBD)

.SUFFIXES: .c .o
