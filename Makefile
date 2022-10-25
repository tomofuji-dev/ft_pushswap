SRCS 			= intlist_to_tlist.c args_to_intlist.c swap.c push.c rotate.c rrotate.c list_add_remove.c sort_utils.c list_utils.c utils.c
HEADER			= push_swap.h
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= stack.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

norm:
				norminette -R CheckForbiddenSourceHeader $(SRCS)
				norminette -R CheckDefine $(HEADER)

test_arg:
				$(CC) $(CFLAGS) -g $(SRCS) test_arg.c
				./a.out
				./a.out 20
				./a.out 1 2 3 0 5 8 7 6 4 9
				./a.out 5 1 3 0 2147483647 -2147483647 -2147483648
				./a.out 2147483648
				./a.out -2147483649

test_sort:
				$(CC) $(CFLAGS) -g -fsanitize=address $(SRCS) test_sort.c
				./a.out
				./a.out 1 2 three
				./a.out 1
				./a.out 1 2
				./a.out 2 1
				./a.out 1 2 3
				./a.out 2 1 3
				./a.out 3 2 1
				./a.out 3 1 2
				./a.out 1 3 2
				./a.out 2 3 1
				./a.out 1 2 3 4 5
				./a.out 5 1 3 4 2
				./a.out 5 1 3 4 2 0
				./a.out 5 1 3 4 2 7 8 6 9 10 0

test_swap:
				$(CC) $(CFLAGS) -g $(SRCS) test_swap.c

test_push:
				$(CC) $(CFLAGS) -g $(SRCS) test_push.c

test_rotate:
				$(CC) $(CFLAGS) -g $(SRCS) test_rotate.c

test_rrotate:
				$(CC) $(CFLAGS) -g $(SRCS) test_rrotate.c

.PHONY:			all clean fclean re norm test_arg test_swap test_push test_rotate test_rrotate