NAME = push_swap

SRCS = srcs/main.c \
	  srcs/operations.c \
	  srcs/utils.c \
	  srcs/further_utils.c \
	  srcs/sorts.c \
	  srcs/small_sorts.c \
	  srcs/operations_a.c \
	  srcs/operations_b.c \
	  srcs/operations_both.c \
	  srcs/check_args.c \
	  srcs/utils3.c \

OBJS = $(SRCS:.c=.o)

HEADERS = includes

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft/
	$(CC) -o $(NAME) $(OBJS) ./libft/libft.a

%.o : %.c
	$(CC) ${CFLAGS} -I ${HEADERS} -o $@ -c $<

clean :
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all
