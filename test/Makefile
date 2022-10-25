SRCS 			= test_sort.c ../intlist_to_tlist.c ../args_to_intlist.c \
				  ../swap.c ../push.c ../rotate.c ../rrotate.c ../list_add_remove.c \
				  ../sort_utils.c ../list_utils.c ../utils.c
HEADER			= push_swap.h
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

NAME			= pushswap

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
				./pushswap
				./pushswap 1 2 three
				./pushswap 1
				./pushswap 1 2
				./pushswap 2 1
				./pushswap 1 2 3
				./pushswap 2 1 3
				./pushswap 3 2 1
				./pushswap 3 1 2
				./pushswap 1 3 2
				./pushswap 2 3 1
				./pushswap 1 2 3 4 5
				./pushswap 5 1 3 4 2
				./pushswap 5 1 3 4 2 0
				./pushswap 5 1 3 4 2 7 8 6 9 10 0

.PHONY:			all clean fclean re norm test