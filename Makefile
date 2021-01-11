# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 21:08:54 by hagoodwi          #+#    #+#              #
#    Updated: 2020/11/06 15:18:52 by hagoodwi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG				=	-g -Wall -Wextra -Werror

NAME_PUSH_SWAP		=	push_swap
NAME_CHECK			= 	checker

SRC_DIR_PUSH_SWAP	=	./src_push_swap/
OBJ_DIR_PUSH_SWAP	=	./obj_push_swap/
SRC_DIR_CHECK 		=	./src_checker/
OBJ_DIR_CHECK		=	./obj_checker/

HEAD_PUSH_SWAP		=	./src_push_swap/push_swap.h
HEAD_CHECK			=	./src_checker/checker.h

INC_PUSH_SWAP 		=	-I ./src_push_swap -I ./libft
INC_CHECK 			=	-I ./src_checker -I ./libft

LIB 				= 	-L ./libft -lft

SRC_PUSH_SWAP	=	calc_rotate.c\
						do_rotates.c\
						dop_functions_1.c\
						dop_functions_2.c\
						functions_1.c\
						functions_2.c\
						index.c\
						initialization.c\
						markup_1.c\
						markup_2.c\
						push_swap.c\
						rotations.c\
						terminate.c\
						work_a_stack_1.c\
						work_a_stack_2.c\
						work_bstack.c

SRC_CHECK 			= 	checker_commands.c\
						checker.c\
						dop_functions.c\
						functions_1.c\
						functions_2.c\
						initialization.c\
						terminate.c\
						reader.c

SRC_PUSH_SWAP_FULL	=	$(addprefix $(SRC_DIR_PUSH_SWAP), $(SRC_PUSH_SWAP))
SRC_CHECK_FULL		=	$(addprefix $(SRC_DIR_CHECK), $(SRC_CHECK))

OBJ_PUSH_SWAP		=	$(patsubst %.c, %.o, $(SRC_PUSH_SWAP))
OBJ_PUSH_SWAP_FULL	=	$(addprefix $(OBJ_DIR_PUSH_SWAP), $(OBJ_PUSH_SWAP))
OBJ_CHECK			=	$(patsubst %.c, %.o, $(SRC_CHECK))
OBJ_CHECK_FULL		=	$(addprefix $(OBJ_DIR_CHECK), $(OBJ_CHECK))

all: $(NAME_CHECK) $(NAME_PUSH_SWAP)

$(NAME_CHECK): $(OBJ_DIR_CHECK) $(OBJ_CHECK_FULL)
	make -C ./libft
	gcc $(FLAG) $(INC_CHECK) $(LIB) $(OBJ_CHECK_FULL) -o $(NAME_CHECK)

$(OBJ_DIR_CHECK):
	mkdir -p $(OBJ_DIR_CHECK)

$(OBJ_DIR_CHECK)%.o: $(SRC_DIR_CHECK)%.c $(HEAD_CHECK)
	gcc $(FLAG) $(INC_CHECK) -o $@ -c $<;

$(NAME_PUSH_SWAP): $(OBJ_DIR_PUSH_SWAP) $(OBJ_PUSH_SWAP_FULL)
	make -C ./libft
	gcc $(FLAG) $(INC_PUSH_SWAP) $(LIB) $(OBJ_PUSH_SWAP_FULL) -o $(NAME_PUSH_SWAP)

$(OBJ_DIR_PUSH_SWAP):
	mkdir -p $(OBJ_DIR_PUSH_SWAP)

$(OBJ_DIR_PUSH_SWAP)%.o: $(SRC_DIR_PUSH_SWAP)%.c $(HEAD_PUSH_SWAP)
	gcc $(FLAG) $(INC_PUSH_SWAP) -o $@ -c $<;


clean:
	make clean -C ./libft
	rm -rf $(OBJ_DIR_CHECK)
	rm -rf $(OBJ_DIR_PUSH_SWAP)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME_CHECK)
	rm -f $(NAME_PUSH_SWAP)

re: fclean all
