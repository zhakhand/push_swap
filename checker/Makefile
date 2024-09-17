SRCS = actions.c actions_2.c helpers.c instructions.c push_swap.c\
 stack_methods.c utils.c arg_checker.c frees.c\
  sorting.c stack_info.c cmds.c quick_sort.c rotations.c\
   checker.c gnl/get_next_line.c gnl/get_next_line_utils.c

HEAD = push_swap.h 

BONUS = checker

CC = cc

RM = rm -f

OBJS = ${SRCS:%.c=%.o}

CFLAGS = -Wall -Werror -Wextra

all: ${BONUS}

%.o:	%.c
		@echo "Compiling $<..."
		${CC} ${CFLAGS} -Ilibft -Ift_printf -c $? -o $@

${BONUS}:	checker

checker:	checker.o
		${MAKE} -C libft
		${MAKE} -C ft_printf
		${CC} ${CFLAGS} ${SRCS} -g ./libft/libft.a ./ft_printf/libftprintf.a -o checker

libft:
		make -C libft

printf:
		make -C ft_printf

clean:
		make clean -C libft
		make clean -C ft_printf
		${RM} ${OBJS}

fclean: clean
		${RM} checker

re:		fclean all

.PHONY:	all clean fclean re