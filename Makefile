NAME = philo

SOURCES_FILES = errors.c \
				main.c \
				threads.c

SRCS_P_DIR = src

SRCS_P = $(addprefix $(SRCS_P_DIR)/, $(SOURCES_FILES))

SRCO_P = $(SRCS_P:.c=.o)

MAKE_LIBFT = $(MAKE) -C ./libft
LIBFT = ./libft/libft.a

FLAG = -Wall -Wextra #-Werror
INC = -I includes/

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NO_COLOR = \033[0m

all : $(NAME)

$(LIBFT):
	$(MAKE_LIBFT)

$(NAME) : $(SRCO_P) | $(LIBFT)
	@cc $(FLAG) -o $(NAME) $(SRCO_P) $(INC) $(LIBFT)
	@echo "$(GREEN)Philo created!$(NO_COLOR)"

%.o : %.c
	@cc $(FLAG) -c -o $@ $< $(INC)

clean :
	@/bin/rm -f $(SRCO_P)
	@$(MAKE_LIBFT) clean
	@echo "$(YELLOW)Make clean done! $(NO_COLOR)"
        

fclean : clean
	@/bin/rm -f $(NAME)
	@$(MAKE_LIBFT) fclean
	@echo "$(RED)Make fclean done! $(NO_COLOR)"

re :
	@make fclean
	@make all

.PHONY : all clean fclean re
