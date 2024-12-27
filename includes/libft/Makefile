CC		=	cc

CFlags	=	-Wall -Wextra -Werror

NAME	=	libft.a

CFILES	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
			ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line.c ft_putchr_printf.c \
			ft_printf.c ft_printarg.c ft_strlen_printf.c  ft_putstr_printf.c ft_putnbr_unsigned_printf.c \
			ft_putnbr_printf.c ft_puthex_printf.c ft_putchr_printf.c

OFILES	=	${CFILES:.c=.o}

all		:	${NAME}

%.o		:	%.c
	${CC} ${CFlags} -c $< -o $@

${NAME}	:	${OFILES}
	@ar rcs ${NAME} ${OFILES}

clean	:
	@rm -f ${OFILES} ${BONUS_O}

fclean	:	clean
	@rm -f ${NAME}

re		:	fclean all

scancppcheck:
	cppcheck --enable=all --inconclusive --quiet ${CFILES}

scangcc:
	gcc-14 -Wall -Wextra -Werror -fanalyzer -fstack-protector-all -Wformat=2 -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wswitch-default -Wunreachable-code -Wundef -Wfloat-equal -Wconversion -Wsign-conversion -Wredundant-decls -Wdisabled-optimization -Winline -Wlogical-op -Wmissing-include-dirs -Woverlength-strings -Wpacked -Wstack-usage=1024 -Wstrict-overflow=5 -Wswitch-enum -Wsync-nand -Wunsafe-loop-optimizations -Wvariadic-macros -Wvector-operation-performance -Wwrite-strings --analyzer -D_FORTIFY_SOURCE=3 -O3 ${CFILES}

scanbuild:
	scan-build-19 --use-analyzer=/usr/bin/clang-19 ${CC} ${CFlags} ${CFILES}

scantidy:
	clang-tidy-19 ${CFILES} -checks=security*,performance*,clang-analyzer*,bugprone*,misc*

.PHONY	:	all clean fclean re scancppcheck scangcc scanbuild scantidy
