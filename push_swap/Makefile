NAME = push_swap

LIBFT_DIR = ./libft
LIBFTFLAGS = -L$(LIBFT_DIR) -lft

CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES_DIR = ./sources/
SOURCES_LIST = main.c utils.c error_validation.c stack_utils.c stack_do_a.c stack_do_b.c stack_do_ab.c\
			   stack_sort.c 
SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

OBJECTS_DIR = ./objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

D_FILES_DIR = ./objects/
D_FILES_LIST = $(patsubst %.c, %.d, $(SOURCES_LIST))
D_FILES = $(addprefix $(D_FILES_DIR), $(D_FILES_LIST))

all: libft $(NAME)

$(NAME): $(OBJECTS_DIR) $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBFTFLAGS) -o $(NAME)

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -MMD

include $(wildcard $(D_FILES_DIR)*.d)

.PHONY: all libft clean fclean re

libft:
	@make -s -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJECTS_DIR)
	@make clean -s -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIBFT_DIR)

re: fclean all



