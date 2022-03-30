SRCS	=	srcs/stack.c srcs/get_params.c srcs/stacks_operations.c \
			srcs/stacks_operations2.c srcs/radix_sort.c srcs/check_errors.c \
			main.c srcs/sort_small.c


OBJS	=	$(SRCS:.c=.o)

GCC		=	gcc

RM		=	rm -f

FLAGS	=	-Wall -Wextra -Werror

NAME	=	push_swap

.c.o:
		@$(GCC) $(FLAGS) -c -I./includes $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
			@$(MAKE) -C ./libft
			@mv ./libft/libft.a .
			@$(GCC) $(FLAGS) $(OBJS) libft.a -o $(NAME)
			@echo '\033[1;35mPush_swap created! 🥳';

all:		$(NAME)

clean:
			@$(RM) $(OBJS) libft.a
			@$(MAKE) clean -C ./libft

fclean:		clean
			@$(RM) $(NAME)
			@$(MAKE) fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re
