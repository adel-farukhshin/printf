
NAME = libftprintf.a

SRCS =	ft_printf.c ft_pnb.c ft_put_utils.c ft_put_utils2.c \
		ft_put_hx.c ft_putstr.c ft_putchar.c ft_put_u.c \
		ft_put_ad.c ft_printf_utils.c ft_conversion_check.c

SRCSB = ft_printf_bonus.c ft_pnb_bonus.c ft_put_utils_bonus.c ft_put_utils2_bonus.c \
		ft_put_hx_bonus.c ft_putstr_bonus.c ft_putchar_bonus.c ft_put_u_bonus.c \
		ft_put_ad_bonus.c ft_printf_utils_bonus.c ft_conversion_check_bonus.c

OBJS = ${patsubst %.c,%.o,${SRCS}}
OBJSB = ${patsubst %.c,%.o,${SRCSB}}

D_FILES = ${patsubst %.c,%.d,${SRCS}}
D_FILESB = ${patsubst %.c,%.d,${SRCSB}}

FLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

%.o : %.c
	cc ${FLAGS} -c $< -o $@ -MMD

all : ${NAME}

bonus : ${OBJSB}
	ar rc ${NAME} $?

${NAME} : ${OBJS} 
	ar rc ${NAME} $?



include ${wildcard ${D_FILES}}
include ${wildcard ${D_FILESB}}

clean :
	rm -f ${OBJS} ${D_FILES}
	rm -f ${OBJSB} ${D_FILESB}
	
fclean : clean
	rm -f ${NAME}
		
re: fclean all

.PHONY: all clean fclean re bonus
