# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 21:11:50 by tmanuel           #+#    #+#              #
#    Updated: 2018/02/09 11:20:09 by tmanuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	srcs/ft_z.c \
		srcs/main.c \
		srcs/ft_init.c \
		srcs/ft_print.c \
		srcs/ft_intro.c \
		srcs/ft_intro2.c \
		srcs/ft_key_hook.c \
		srcs/ft_exit_fdf.c \
		srcs/ft_draw_fdf.c \
		srcs/ft_draw_fdf2.c \
		srcs/ft_key_hook3.c \
		srcs/ft_key_hook4.c \
		srcs/ft_draw_fdf3.c \
		srcs/ft_pixel_put.c \
		srcs/ft_check_map.c \
		srcs/ft_init_view.c \
		srcs/ft_put_color.c \
		srcs/ft_intro_sound.c \
		srcs/ft_change_color.c \

OBJ = $(patsubst srcs/%.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

INC = -I includes

LIB =  -L libft/ -lft

LIBX = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

ifndef ECHO
	T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
		-nrRf $(firstword $(MAKEFILE_LIST)) \
		ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
	N := x
	C = $(words $N)$(eval N := x $N)
	ECHO = echo -ne "\r [`expr $C '*' 100 / $T`%]"
endif

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc -c -g $(FLAGS) $(INC) $(SRC)
	@gcc -g $(FLAGS) $(INC) -o $(NAME) $(OBJ) $(LIB) $(LIBX)
	@echo "\033[96;5;106m''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[96;5;106m''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[96;5;106m'''''''''''''\033[30;40;5m.:oooooooooooooooooooo+:.\033[96;5;106m''''''''''''''''''\033[30;40;5m-oooooooooooo+:'\033[96;5;106m''''''''''''''''''''''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[96;5;106m''''''''''\033[30;40;5m.:oyddh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyy\033[30;40;5m.hhdmho-\033[96;5;106m'''''''''\033[30;40;5m-:mdh\033[38;5;70m\033[48;5;70myyyyyyyyyy\033[30;40;5m.hhdmy+/.\033[96;5;106m''''''''''''''''''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[96;5;106m''''''''\033[30;40;5m.:ddh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5m.hmh-\033[96;5;106m''''\033[30;40;5m--+omh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyy\033[30;40;5m.hhdmy\033[96;5;106m'''''''''''''''''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[96;5;106m''''''\033[30;40;5m./mdh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5m.dmoyhddh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyy\033[30;40;5m.hdd/\033[96;5;106m''''''''''''''''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[96;5;106m''''\033[30;40;5m./dmh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5m.hNm\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5m.hmy-\033[96;5;106m''''''''''''''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[96;5;106m''\033[30;40;5m.:ddh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5m.Nd\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5m.dmo\033[96;5;106m'''''''''''''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[96;5;106m'\033[30;40;5m./mh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5m.hN\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5m.hmy\033[96;5;106m''''''''''''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[30;40;5m.+mh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyy\033[30;40;5mhhhhddddddddddddddddddhN\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mmh.\033[96;5;106m''''''''''''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[30;40;5mdh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyy\033[30;40;5mhhmddddhhhhh\033[38;5;70m\033[48;5;70myyyyyyyyy\033[30;40;5mhhyyhhdmmmh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyy\033[30;40;5mhhyh\033[38;5;70m\033[48;5;70myyyyyyy\033[30;40;5mmh.\033[96;5;106m''''''''''''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyy\033[30;40;5mhdmhh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mddmdhyyyhhdddmmdddddddddmmddhh\033[38;5;70m\033[48;5;70myyy\033[30;40;5mmo\033[96;5;106m''''''''''''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyy\033[30;40;5mhdmd\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhdmdddddhh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyy\033[30;40;5mhhdhdmdddN/\033[96;5;106m'''''''''''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyy\033[30;40;5mddh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhdmNh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhdmmo-\033[96;5;106m'''''''''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhmm\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mdddh+-\033[96;5;106m''''''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mmm\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhddy-\033[96;5;106m''''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mmm\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mddo.\033[96;5;106m''''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mmmh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhmh:.\033[96;5;106m''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyy\033[30;40;5mhhdddddddddddmmmmmmmmmmmNm\033[38;5;70m\033[48;5;70myyyyyyyyy\033[30;40;5mmmdh\033[38;5;70m\033[48;5;70my\033[30;40;5mmNh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyy\033[30;40;5mhhhyhhhhhhdms-\033[96;5;106m'''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyy\033[30;40;5mhdmmddh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyy\033[30;40;5m\033[38;5;70m\033[48;5;70my\033[30;40;5mdddmddhh\033[38;5;70m\033[48;5;70myyy\033[30;40;5mhhmmddm\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyy\033[30;40;5mhdddmdd\033[38;5;70m\033[48;5;70myyyyy\033[30;40;5mhhhhhddso:\033[96;5;106m''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyy\033[30;40;5mmmdh\033[38;5;70m\033[48;5;70myyy\033[30;40;5mhhddddddddddddddddddmdh\033[38;5;70m\033[48;5;70myyyy\033[30;40;5mhhdmdh\033[38;5;70m\033[48;5;70myyyy\033[30;40;5mhmmMh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyy\033[30;40;5mhhhdm\033[38;5;70m\033[48;5;70myyyy\033[30;40;5mdddddddddmmmms:.\033[96;5;106m'''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyy\033[30;40;5mhdmd\033[38;5;70m\033[48;5;70myy\033[30;40;5mhmmmddhh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyy\033[38;5;70m\033[48;5;70myh\033[30;40;5mhhdmmh\033[38;5;70m\033[48;5;70myyyy\033[30;40;5mdNdh\033[38;5;70m\033[48;5;70myyyy\033[30;40;5m\033[30;40;5mhmmd\033[38;5;70m\033[48;5;70myyyyyyyyyy\033[30;40;5mhdmd\033[38;5;70m\033[48;5;70myyyy\033[30;40;5mhhhhhhhhhhh\033[38;5;70m\033[48;5;70myy\033[30;40;5mh\033[30;40;5mdmmmh/\033[96;5;106m''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyy\033[30;40;5mdNdh\033[38;5;70m\033[48;5;70my\033[30;40;5mhmmhh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhmmddhhhdmmmh\033[38;5;70m\033[48;5;70myyy\033[30;40;5mhmd\033[38;5;70m\033[48;5;70myyyyyy\033[30;40;5mhmmmd\033[38;5;70m\033[48;5;70myy\033[30;40;5mhmmmdhhhhhhhhddmmh\033[38;5;70m\033[48;5;70my\033[30;40;5mhdNds\033[96;5;106m''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyy\033[30;40;5mmNh\033[38;5;70m\033[48;5;70myy\033[30;40;5mdNh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhddmmmdhdmmh\033[38;5;70m\033[48;5;70myy\033[30;40;5mhNh\033[38;5;70m\033[48;5;70myyyy\033[30;40;5mhm\033[38;5;70m\033[48;5;70myy\033[30;40;5m\033[38;5;70m\033[48;5;70myyyyyyyyyyyyy\033[30;40;5m\033[38;5;70m\033[48;5;70myyyyyy\033[30;40;5mhmm\033[38;5;70m\033[48;5;70myy\033[30;40;5mN:\033[96;5;106m''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyy\033[30;40;5mmmhhmNdh\033[38;5;70m\033[48;5;70my\033[30;40;5mhhhhhhhhhhhhddddddmmNmNNNNm\033[30;40;5mddssssssshmNm\033[38;5;70m\033[48;5;70my\033[30;40;5mdN\033[38;5;70m\033[48;5;70mdyy\033[30;40;5mmm\033[38;5;70m\033[48;5;70myyyyyyy\033[30;40;5mhmmmdddddddddhhhhhh\033[38;5;70m\033[48;5;70myyyy\033[30;40;5mNNhm-\033[96;5;106m'''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyy\033[30;40;5mhhhhhddmds/\033[107;97;5m*******\033[30;40;5m/sNMs+hNMMMNMMMMMNo.\033[107;97;5m*******\033[30;40;5m.-dd\033[38;5;70m\033[48;5;70my\033[30;40;5mhmm\033[38;5;70m\033[48;5;70my\033[30;40;5mhN\033[38;5;70m\033[48;5;70myyyyyy\033[30;40;5mmdohmNNNMMMMMNdo\033[107;97;5m.-+y\033[30;40;5mhhhhmMmN:\033[96;5;106m'''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyy\033[30;40;5mhddhhs\033[107;97;5m+-':\033[30;40;5mNMMM\033[107;97;5m+/\033[30;40;5mdMMMMmyyohMMd+\033[107;97;5m*********\033[30;40;5m.dd\033[38;5;70m\033[48;5;70myy\033[30;40;5mdNhm\033[38;5;70m\033[48;5;70myyyy\033[30;40;5mhms\033[107;97;5m-\033[30;40;5mdMy\033[107;97;5m-\033[30;40;5msMMMMMmmNMs\033[107;97;5m***'.:+\033[30;40;5mhmh\033[30;40;5mhh\033[96;5;106m'''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhmhdMMMMMmmMMMM/\033[107;97;5m***\033[30;40;5m:MMM+\033[107;97;5m**********\033[30;40;5m:Nh\033[38;5;70m\033[48;5;70my\033[30;40;5mydN\033[38;5;70m\033[48;5;70myyy\033[30;40;5mhmd\033[107;97;5m::\033[30;40;5mdMMmhmMMMMy\033[107;97;5m-..\033[30;40;5mNN.\033[107;97;5m*******'\033[30;40;5moM\033[30;40;5my\033[96;5;106m'''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyy\033[30;40;5mhh\033[38;5;70m\033[48;5;70myyyyy\033[30;40;5mhmNMMMM\033[107;97;5m+o\033[30;40;5mMMMMh//sNMMM/\033[107;97;5m***********\033[30;40;5m+m\033[38;5;70m\033[48;5;70myyy\033[30;40;5mmdyyhN\033[107;97;5m-*\033[30;40;5myMMMMdmMMMMM\033[107;97;5m''-\033[30;40;5mNN.\033[107;97;5m******\033[30;40;5m':mdd\033[30;40;5m\033[96;5;106m'''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyy\033[30;40;5mhmmdh\033[38;5;70m\033[48;5;70myyyyy\033[30;40;5mhdmmNNMMMMMMMMMMMN.\033[107;97;5m************\033[30;40;5msN\033[38;5;70m\033[48;5;70myy\033[30;40;5mhhyhmh\033[107;97;5m'*\033[30;40;5mhMMMM\033[107;97;5mo\033[30;40;5myMMMMNmmmMm'\033[107;97;5m****\033[30;40;5m'+ymhh\033[30;40;5md\033[96;5;106m'''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhdNmh\033[38;5;70m\033[48;5;70myyyyyyyyy\033[30;40;5mhhdmNMMMMMM/\033[107;97;5m*********'-//+\033[30;40;5mNNmh\033[38;5;70m\033[48;5;70myy\033[30;40;5mhmys/dMMMMMMMMMMMMMmh/\033[107;97;5m--:\033[30;40;5m/oymhyd\033[30;40;5mm+\033[96;5;106m'''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mdmmhh\033[38;5;70m\033[48;5;70myyyyyyyyyy\033[30;40;5myhdddmNhs+++++++ohmdhhhydN\033[38;5;70m\033[48;5;70myyyyy\033[30;40;5mhhhddddddddddddddhhdddhhyy\033[30;40;5mhms-\033[96;5;106m''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhhdmddmddhh\033[38;5;70m\033[48;5;70myyhyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhddNd\033[38;5;70m\033[48;5;70myyy\033[30;40;5mhh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mdNm/\033[96;5;106m''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhdddddmdddmdddddddddddhdmmmhh\033[38;5;70m\033[48;5;70myyyyy\033[30;40;5mhdmmNmmdhh\033[38;5;70m\033[48;5;70myyyyyyyyyy\033[30;40;5mdddddmNN+\033[96;5;106m'''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhhmNh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyy\033[30;40;5mdmmmdddddd\033[38;5;70m\033[48;5;70myyyyyyyyyy\033[30;40;5mhmmhmd:\033[96;5;106m'''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyy\033[30;40;5mhhhhh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mdNm\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyy\033[30;40;5mdmmd\033[38;5;70m\033[48;5;70myyyyyyy\033[30;40;5mhddddddh\033[38;5;70m\033[48;5;70myyy\033[30;40;5mhN/\033[96;5;106m''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyy\033[30;40;5mh\033[38;5;70m\033[48;5;70mmhhm\033[30;40;5mh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mdNm\033[38;5;70m\033[48;5;70mhyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mmN\033[38;5;70m\033[48;5;70mdyyyyyyyyyyyyyyyyy\033[30;40;5mhN+\033[96;5;106m'''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhdNd\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mdNd\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyy\033[30;40;5mdm+.\033[96;5;106m'''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyy\033[30;40;5mhddddddh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhdmdmmh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhmd\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyy\033[30;40;5mhNmm-\033[96;5;106m''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyy\033[30;40;5mhdmmh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhhdNmh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhNydm.\033[96;5;106m'''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyy\033[30;40;5mhm\033[48;5;130;82m\033[38;5;130;82myyy\033[30;40;5mNmmddmdddh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyy\033[30;40;5mhdddhh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mmdyym+\033[96;5;106m'''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyy\033[30;40;5mdm\033[48;5;130;82m\033[38;5;130;82myyyyyy\033[30;40;5mhhhdmmmhh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mmdyhmd:\033[96;5;106m'''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyy\033[30;40;5mdm\033[48;5;130;82m\033[38;5;130;82myyyy\033[30;40;5mhm\033[48;5;130;82m\033[38;5;130;82myyyyyy\033[30;40;5mhdmdmddddddhh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mmmhhNs.\033[96;5;106m''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyy\033[30;40;5mdmm\033[48;5;130;82m\033[38;5;130;82myyy\033[30;40;5mhhdmm\033[48;5;130;82m\033[38;5;130;82mhyyyyy\033[30;40;5mhhhhhhddmmmdmdmdh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhdNhdm/.\033[96;5;106m'''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyy\033[30;40;5mhdmmd\033[48;5;130;82m\033[38;5;130;82myyy\033[30;40;5mhhmmd\033[48;5;130;82m\033[38;5;130;82myyyyyyyyyyyyyy\033[30;40;5mhhhdmddddddhhhhh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhdmmdhhmN:\033[96;5;106m'''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyy\033[30;40;5mhdmmh\033[48;5;130;82m\033[38;5;130;82myyy\033[30;40;5mhhdddmmdddh\033[48;5;130;82m\033[38;5;130;82myyyyyyyyyyy\033[30;40;5mhhhhhdddddmdddddddddddhhddhhhhhhddhhhhhhddddhhhddmdh\033[48;5;130;82m\033[38;5;130;82myyy\033[30;40;5mmN:\033[96;5;106m''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyy\033[30;40;5mddmmdhh\033[48;5;130;82m\033[38;5;130;82myyyy\033[30;40;5mhhhddmddddddd\033[48;5;130;82m\033[38;5;130;82myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhN+\033[96;5;106m''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyy\033[30;40;5mhhmmddddh\033[48;5;130;82m\033[38;5;130;82myyyyyy\033[30;40;5mhhhhhddddddddddddmddd\033[48;5;130;82m\033[38;5;130;82myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5myhm\033[96;5;106m''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhhddmd\033[48;5;130;82m\033[38;5;130;82myyyyyyyyyyyyyyyyyyyy\033[30;40;5mhhhhhhddmmdddddddddddddddddddddddddddddddddhhyyyy\033[30;40;5mdm\033[96;5;106m''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhmmmdh\033[48;5;130;82m\033[38;5;130;82myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhmh:\033[96;5;106m''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhdmmmdhh\033[48;5;130;82m\033[38;5;130;82myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mmd/.\033[96;5;106m'''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhhhdmmdddhh\033[48;5;130;82m\033[38;5;130;82myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mN:\033[96;5;106m'''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhhhhhdddmmmddd\033[48;5;130;82m\033[38;5;130;82mhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhddmmdy\033[30;40;5mm:\033[96;5;106m'''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhhhhhhdhhdddddddddddddddddddddddddddddddhhhyyy\033[30;40;5mhm.\033[96;5;106m'''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mmo\033[96;5;106m''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhddmdmm\033[38;5;70m\033[48;5;70mhyyyyyy\033[30;40;5mdd\033[96;5;106m'''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5myhddNhhyyhhdmdddhdy-\033[96;5;106m'''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhhmmmhy\033[38;5;70m\033[48;5;70myyyyyyy\033[30;40;5mhdhmN+\033[96;5;106m'''''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mdmmdhy\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyy\033[30;40;5mddo:.\033[96;5;106m''''''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhdmdhy\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyy\033[30;40;5mhddy+-.\033[96;5;106m''''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhhhhhh\033[38;5;70m\033[48;5;70myyyh\033[30;40;5mdNmdy\033[38;5;70m\033[48;5;70myyyyyyyyyyy\033[30;40;5mhh\033[38;5;70m\033[48;5;70myyyyyyyyyyy\033[30;40;5mhddhs-\033[96;5;106m''''''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhmmhhhhmmhdmdhhdmd\033[38;5;70m\033[48;5;70myyyyyyy\033[30;40;5mhmmdNddhh\033[38;5;70m\033[48;5;70myyyyhhyyyyy\033[30;40;5mdd+-.\033[96;5;106m'''''''''''''''''''\033[30;40;5m"
	@echo "\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhNhy\033[38;5;70m\033[48;5;70myyyyy\033[30;40;5mhMd\033[38;5;70m\033[48;5;70mhyyyy\033[30;40;5mdN\033[38;5;70m\033[48;5;70myyyy\033[30;40;5mhdNmhhmh  smhhdmmh\033[38;5;70m\033[48;5;70myyyyyy\033[30;40;5mhddh.\033[96;5;106m''''''''''''''''''\033[30;40;5m"
	@echo "\033[186;7;97m                               \033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhNhy\033[38;5;70m\033[48;5;70myyyyyy\033[30;40;5mmm\033[38;5;70m\033[48;5;70myyyy\033[30;40;5mmmh\033[38;5;70m\033[48;5;70my\033[30;40;5mhmmddh\033[38;5;70m\033[48;5;70my\033[30;40;5mhmo   dddmmh\033[38;5;70m\033[48;5;70myyyyyyyyyyy\033[30;40;5mmy-\033[96;5;106m'''''''''''''''''\033[30;40;5m"
	@echo "\033[186;7;97m          \033[30;40;5m:oooo-\033[186;7;97m   \033[30;40;5mooo:+oooo.\033[186;7;97m  \033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mdNdy\033[38;5;70m\033[48;5;70myyyyyy\033[30;40;5mdmdddmddmmh\033[38;5;70m\033[48;5;70myyy\033[30;40;5mdds   NNmd\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyy\033[30;40;5mdmo.\033[96;5;106m''''''''''''''''\033[30;40;5m"
	@echo "\033[186;7;97m         \033[30;40;5m/dMMMh-\033[186;7;97m   \033[30;40;5mNMd:\033[186;7;97m \033[30;40;5mmMMMM-\033[186;7;97m \033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhdNdy\033[38;5;70m\033[48;5;70myyyyyyyyy\033[30;40;5mNh\033[38;5;70m\033[48;5;70myyyyy\033[30;40;5mhd    shdd\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyy\033[30;40;5mhNd:.\033[96;5;106m''''''''''''\033[30;40;5m"
	@echo "\033[186;7;97m       \033[30;40;5m/mMMMh-\033[186;7;97m     \033[30;40;5mh:\033[186;7;97m   \033[30;40;5mmMMMM-\033[186;7;97m \033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mdmdy\033[38;5;70m\033[48;5;70myyyyyyy\033[30;40;5mhm\033[38;5;70m\033[48;5;70my\033[30;40;5mhhdhs  sdmh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhdmd+.\033[96;5;106m'''''''''\033[30;40;5m"
	@echo "\033[186;7;97m     \033[30;40;5m/mMMMh-\033[186;7;97m          \033[30;40;5m.yMMMm/\033[186;7;97m  \033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mNhy\033[38;5;70m\033[48;5;70myyyyyy\033[30;40;5mhNmy    hmh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyy\033[30;40;5mdh\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyy\033[30;40;5mhmh\033[96;5;106m'''''''''\033[30;40;5m"
	@echo "\033[186;7;97m   \033[30;40;5m/mMMMh-\033[186;7;97m          \033[30;40;5m-yMMMm/\033[186;7;97m    \033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhNhy\033[38;5;70m\033[48;5;70myyyyyy\033[30;40;5mmy   +Nhy\033[38;5;70m\033[48;5;70myyyyyyyyyyy\033[30;40;5mymNdhy\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyy\033[30;40;5mm+\033[96;5;106m''''''''\033[30;40;5m"
	@echo "\033[186;7;97m \033[30;40;5m.mMMMMyoooooooo\033[186;7;97m   \033[30;40;5myMMMM+\033[186;7;97m   \033[30;40;5m..\033[186;7;97m \033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mmdy\033[38;5;70m\033[48;5;70myyyyyyy\033[30;40;5mhms/Nhy\033[38;5;70m\033[48;5;70myyyyyyyyyyy\033[30;40;5mmNdy\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyy\033[30;40;5mhms-\033[96;5;106m''''''\033[30;40;5m"
	@echo "\033[186;7;97m \033[30;40;5m:MMMMMMMMMMMMMMN\033[186;7;97m  \033[30;40;5mNMMMM.\033[186;7;97m \033[30;40;5m.yM-\033[186;7;97m \033[186;7;97m\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhmy\033[38;5;70m\033[48;5;70myyyyyyyyy\033[30;40;5mhmMNdy\033[38;5;70m\033[48;5;70myyyyyyyy\033[30;40;5mhmmyy\033[38;5;70m\033[48;5;70myyyyyyyyy\033[30;40;5mdmd\033[38;5;70m\033[48;5;70myyyyyyyyy\033[30;40;5mhN.\033[96;5;106m'''''\033[30;40;5m"
	@echo "\033[186;7;97m  \033[30;40;5msssssssssyMMMMN\033[186;7;97m  \033[30;40;5mNMMMM:yMMM-\033[186;7;97m \033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhN\033[38;5;70m\033[48;5;70myyyyyyyyyyyy\033[30;40;5mdNmNNm\033[38;5;70m\033[48;5;70myyyyy\033[30;40;5mdNh\033[38;5;70m\033[48;5;70myyyyyyyyyy\033[30;40;5mhmNh\033[38;5;70m\033[48;5;70myyyyyy\033[30;40;5mh\033[38;5;70m\033[48;5;70myyyy\033[30;40;5mN.\033[96;5;106m'''''\033[30;40;5m"
	@echo "\033[186;7;97m           \033[30;40;5m.MMMMN\033[186;7;97m              \033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mmN\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyy\033[30;40;5mhmNd\033[38;5;70m\033[48;5;70myyy\033[30;40;5mmh\033[38;5;70m\033[48;5;70myyyyyyyyy\033[30;40;5mdmmh\033[38;5;70m\033[48;5;70myyyyyyy\033[30;40;5mmm\033[38;5;70m\033[48;5;70myyyy\033[30;40;5mms\033[96;5;106m'''''\033[30;40;5m"
	@echo "\033[186;7;97m           \033[30;40;5m.MMMMN\033[186;7;97m              \033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mdmohm\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyy\033[30;40;5mhddddNd\033[38;5;70m\033[48;5;70myyyyyyyy\033[30;40;5mmN\033[38;5;70m\033[48;5;70myyyyyyyy\033[30;40;5mhmm\033[38;5;70m\033[48;5;70myyyyyy\033[30;40;5mN+\033[96;5;106m''''\033[30;40;5m"
	@echo "\033[186;7;97m                            FdF\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhNh   hm\033[38;5;70m\033[48;5;70myyyyyyyyyyyyyyyyyyyyy\033[30;40;5mhNd\033[38;5;70m\033[48;5;70myyyyy\033[30;40;5mdNd\033[38;5;70m\033[48;5;70myyyyyyy\033[30;40;5mhmmd\033[38;5;70m\033[48;5;70myyyyyyy\033[30;40;5mhm-\033[96;5;106m'''\033[30;40;5m"

%.o: srcs/%.c
	@gcc -c $(FLAGS) $(INC) $<
	@tput setaf 142
	@$(ECHO) $@

clean:
	@/bin/rm -f $(OBJ)
	@tput setaf 9
	@make -C libft/ clean
	@$(ECHO) clean done.

fclean: clean
	@/bin/rm -f $(NAME)
	@tput setaf 9
	@$(ECHO) fclean done.
	@make -C libft/ fclean

re:
	@make fclean && make

.PHONY: all clean fclean re
