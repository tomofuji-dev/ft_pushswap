SRCS 			= swap.c push.c rotate.c rrotate.c list_add_remove.c list_utils.c utils.c
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

test_swap:
				$(CC) $(CFLAGS) -g $(SRCS) test_swap.c

test_push:
				$(CC) $(CFLAGS) -g $(SRCS) test_push.c

test_rotate:
				$(CC) $(CFLAGS) -g $(SRCS) test_rotate.c

test_rrotate:
				$(CC) $(CFLAGS) -g $(SRCS) test_rrotate.c

.PHONY:			all clean fclean re norm test_swap test_push test_rotate test_rrotate