NAME = ft_minishell1

LIB = libft.a
LIBDIR = libft/

COLOR = \x1b[33;01m
COMPCOLOR = \x1b[32;01m
DELCOLOR = \x1b[31;01m
SRCS = main.c \
	   errors.c \
	   errors2.c
OBJS = $(addprefix srcs/, $(SRCS:.c=.o))
FLAGS = -Wall -Wextra -Werror
CC = cc

all: $(LIB) $(NAME)

$(LIB):
	@make -C $(LIBDIR)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) -I includes $(FLAGS) $(addprefix $(LIBDIR), $(LIB))
	@echo "\033[33m"$(NAME) compiled ! "\033[32m"Success

%.o: %.c
	@$(CC) -o $@ -c $< -I includes $(FLAGS)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean
	@echo "\033[33m"$(NAME) deleted ! "\033[32m"Success

re: fclean all

.PHONY : fclean re
