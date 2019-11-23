# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 15:46:00 by pguitar           #+#    #+#              #
#    Updated: 2019/11/23 16:31:14 by obanshee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

### PATH ###
SRCS_PATH = srcs/
OBJ_PATH  = obj/
LIBFT_PATH = libft/

FLAGS = #-Wall -Werror -Wextra

INC = -I ./includes/ft_printf.h -I ./$(LIBFT_PATH)includes/libft.h

SRCS_NAME = ft_printf.c format.c pars_1.c pars_2.c size.c chars.c floats.c \
	ft_d.c ft_u.c ft_o.c ft_x.c ft_p.c ft_s.c color.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(OBJ) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAGS) $(INC) $< -o $@
	@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"

clean:
	@make -C $(LIBFT_PATH)/ clean
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re