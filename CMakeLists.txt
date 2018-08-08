cmake_minimum_required(VERSION 3.9)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)
include_directories(includes)
include_directories(libft/includes)
add_executable(ft_printf srcs/lst/ft_init_lst.c srcs/lst/ft_free_lst.c srcs/core/ft_printf.c srcs/core/ft_core.c srcs/core/ft_flags.c srcs/core/ft_precision.c srcs/core/ft_modifier.c)