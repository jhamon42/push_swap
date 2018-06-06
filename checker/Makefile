# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 14:53:08 by jhamon            #+#    #+#              #
#    Updated: 2018/06/06 16:51:27 by jhamon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
AUTEUR = "jhamon"

CC = gcc

FLAG = -Wall -Werror -Wextra
G3 = -fsanitize=address -g3

#path
INC = -I ./includes/
SRC_PATH = src/
OBJ_PATH  = obj/

#srcs
SRC_CK = ft_op_rotate.c ft_fill_struct.c ft_tools.c ft_op_swap_push.c main_checker.c ft_apply_op.c ft_double_op.c

SRC = $(addprefix $(SRC_PATH), $(SRC_CK))
OBJ = $(addprefix $(OBJ_PATH), $(SRC_CK:.c=.o))

DIRLB =  ../libft/
LIB = -L $(DIRLB) -lft

# Utile
_END=tput sgr0
_BOLD=tput bold
_UNDER=tput smul
_REV=tput smso
_DAFUK=tput smacs

# Colors
_GREY=tput setaf 250
_RED=tput setaf 160
_GREEN=tput setaf 10
_YELLOW=tput setaf 11
_BLUE=tput setaf 27
_PURPLE=tput setaf 92
_CYAN=tput setaf 50
_WHITE=tput setaf 255

# Inverted
_IGREY=tput setab 250
_IRED=tput setab 160
_IGREEN=tput setab 10
_IYELLOW=tput setab 11
_IBLUE=tput setab 27
_IPURPLE=tput setab 92
_ICYAN=tput setab 50
_IWHITE=tput setab 255

define OK
	@$(call _GREEN) && printf "[Ok]	"
	@$(call _UNDER)
	@$(call _YELLOW) && printf "$1\n"
	@$(call _END)
endef

define FOK
	@$(call _GREEN) && printf "\n[Compiled]	"
	@$(call _CYAN) && printf "$1\n"
	@$(call _END)
endef

define CLNOK
	@$(call _GREEN) && printf "[clean]	"
	@$(call _GREY) && printf "$1\n"
	@$(call _END)
endef

define CLNOBJOK
	@$(call _GREEN) && printf "[clean]	"
	@$(call _GREY) && printf "Obj_$(NAME)\n"
	@$(call _END)
endef

define BULSHIT
	@$(call _PURPLE) && printf "auteur :	"
	@$(call _RED) && printf "$(AUTEUR)\n"
	@$(call _END)
endef

all : $(NAME)
	@make -C $(DIRLB)
	@:

$(NAME) : $(OBJ)
	@make -C $(DIRLB)
ifeq ($(DB),1)
	@$(CC) -o $@ $(SRC) $(INC) $(LIB) $(G3)
else
	@$(CC) -o $@ $(SRC) $(INC) $(LIB) $(FLAG)
endif
	@make auteur
	$(call FOK,$@)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p `dirname $@`
ifeq ($(DB),1)
	@$(CC) -c $(G3) $(INC) $< -o $@
else
	@$(CC) -c $(FLAGS) $(INC) $< -o $@
endif
	$(call OK,$*)

clean :
	@rm -rf $(OBJ_PATH)
	$(call CLNOBJOK,$(OBJ))

fclean : clean
	@rm -rf $(NAME)
	$(call CLNOK,$(NAME))

re : fclean all

debug :
	@make DB=1

auteur :
	@touch $@ && echo $(AUTEUR) > $@
	$(call BULSHIT,$(AUTEUR))

norme :
	@norminette $(SRC)

.PHONY : all clean fclean re debug auteur
