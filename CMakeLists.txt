cmake_minimum_required(VERSION 3.12)
project(gnl C)

set(CMAKE_C_STANDARD 99)

add_executable(gnl get_next_line.c libft/ft_putendl.c libft/ft_strjoin.c libft/ft_strsub.c libft/ft_putchar.c libft/ft_strcpy.c libft/ft_strlen.c libft/ft_strcat.c libft/ft_bzero.c libft/ft_memmove.c libft/ft_strnew.c libft/ft_memalloc.c libft/ft_strdel.c libft/ft_strchr libft/ft_strdup.c libft/ft_memdel.c libft/ft_memset.c libft/ft_strncat.c libft/ft_memcpy.c)