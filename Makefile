NAME = push_swap

SOURCES = main.c \
	  get_elem.c \
	  is_error.c \
	  get_numbers.c \
	  fill_pile.c \
	  analyze_pile.c \
	  numbers_in_order.c \
	  sort_three.c \
	  requires_one_action.c \
	  sort_four_or_five.c \
	  algo_radix.c \
	  counting_sort.c \
	  initialize_stack.c \
	  sort_pile.c \
	  ft_swap.c \
	  ft_push.c \
	  ft_rotate.c \
	  ft_reverse_rotate.c \
	  utils.c \

OBJETS = ${SOURCES:.c=.o}

LIBFTPATH = ./Libft

LIBFTNAME = libft.a

HEADER = push_swap.h

CFLAGS = -Wall -Wextra -Werror


all: ${NAME}

${NAME}: ${LIBFTPATH}/${LIBFTNAME} ${OBJETS} ${HEADER}
	cc ${CFLAGS} -o $@ ${OBJETS} -L${LIBFTPATH} -lft

${LIBFTPATH}/${LIBFTNAME}:
	make -C ${LIBFTPATH}

clean:
	rm -f ${OBJETS}
	make clean -C ${LIBFTPATH}

fclean: clean
	rm -f ${NAME}
	rm -f ${LIBFTPATH}/${LIBFTNAME}

re: fclean all

.PHONY : all clean fclean re
