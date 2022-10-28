SRCS 			= push_swap.c intlist_to_tlist.c args_to_intlist.c \
				  swap.c push.c rotate.c rrotate.c list_add_remove.c \
				  sort_utils.c list_utils.c utils.c
HEADER			= push_swap.h
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

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

.PHONY:			all clean fclean re norm