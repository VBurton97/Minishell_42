# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasha <sasha@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 11:49:10 by hsliu             #+#    #+#              #
#    Updated: 2023/02/07 15:42:14 by sasha            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

MAKE	=	make

SRC_DIR	=	./src/

OBJ_DIR	=	./.obj/

INC_DIR	=	./include/

LIST_SRC	=	token_utils.c line_to_token_utils.c \
				ft_line_to_token.c ft_set_pipe.c \
				dollar_exp_utils.c ft_dollar_exps.c\
				ft_get_env.c\
				parsing.c\
				test.c

LIST_OBJ	=	$(LIST_SRC:.c=.o) 

LIST_INC	=	parsing.h 

SRC		=	$(addprefix $(SRC_DIR), $(LIST_SRC))

OBJ		=	$(addprefix $(OBJ_DIR), $(LIST_OBJ))

INC		=	$(addprefix $(INC_DIR), $(LIST_INC))

LIB_DIR	=	libftprintf

LIB		=	libftprintf/libftprintf.a

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME)	:	$(OBJ_DIR) $(OBJ) $(INC) $(LIB) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) -lreadline

$(LIB): $(LIB_DIR)
	$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) 

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

clean : 
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: clean fclearn re all
