NAME = push_swap

SOURCES = main.c \
	  get_elem.c \
	  get_numbers.c \
	  in_order.c \
	  fill_pile.c \
	  print_lists.c \
	  ft_swap.c \
	  ft_push.c \
	  ft_rotate.c \
	  ft_reverse_rotate.c \
	  analyze_elem.c \
	  radix_sort.c \
	  counting_sort.c \
	  initialize_stack.c \
	  sort_pile.c \
	  sort_three.c \
	  sort_four.c \
	  utils.c \
	  random_generator.c \

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
	make fclean -C ${LIBFTPATH}

re: fclean all

.PHONY : all clean fclean re
