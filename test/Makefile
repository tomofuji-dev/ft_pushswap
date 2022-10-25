SRCS 			= test_sort.c ../intlist_to_tlist.c ../args_to_intlist.c \
				  ../swap.c ../push.c ../rotate.c ../rrotate.c ../list_add_remove.c \
				  ../sort_utils.c ../list_utils.c ../utils.c
HEADER			= push_swap.h
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

NAME			= push_swap

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

norm:
				norminette -R CheckForbiddenSourceHeader $(SRCS)
				norminette -R CheckDefine $(HEADER)

test:
				./push_swap
				./push_swap 1 2 three
				./push_swap 1
				./push_swap 1 2
				./push_swap 2 1
				./push_swap 1 2 3
				./push_swap 2 1 3
				./push_swap 3 2 1
				./push_swap 3 1 2
				./push_swap 1 3 2
				./push_swap 2 3 1
				./push_swap 1 2 3 4 5
				./push_swap 5 1 3 4 2
				./push_swap 5 1 3 4 2 0
				./push_swap 5 1 3 4 2 7 8 6 9 10 0

.PHONY:			all clean fclean re norm test