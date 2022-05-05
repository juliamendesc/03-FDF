# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julcarva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 15:45:52 by julcarva          #+#    #+#              #
#    Updated: 2022/01/05 15:45:54 by julcarva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS		+=	--quiet

NAME			=
FDF				=	fdf

CC				=	gcc

CFLAGS			=	-fsanitize=address -fstack-protector -Werror -Wextra -Wall -g

SRCS			=	./srcs/*.c

LIBFT			=	./libft/libft.a

LIBFT_DIR		=	./libft

INCLUDES	=	-I./includes -I$(LIBFT_DIR)

INCLUDES_MAC	=	mlx_mac/libmlx.a

INCLUDES_LINUX	=	-Lmlx_linux -lmlx_Linux -Imlx_linux

USE				=	-lmlx -framework OpenGL -framework AppKit -lm

USE_LINUX		=	-lbsd -lmlx -lXext -lX11 -lm

# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all:			$(FDF)

$(NAME):		all

$(FDF):		$(LIBFT) $(SRCS)
			@make -C mlx_mac/ all
			@ $(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(INCLUDES_MAC) $(USE) -o $(FDF)
			@printf "$(GREEN)fdf created.\n"

linux:		$(LIBFT) $(SRCS)
			@make -C mlx_linux/ all
			@ $(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(INCLUDES_LINUX) $(USE_LINUX) -o $(FDF)
			@printf "$(GREEN)fdf created.\n"

$(LIBFT):
				@ $(MAKE) -C ./libft

clean:
				@ rm -f $(NAME)
				@printf "$(YELLOW)fdf removed.\n"

cleanlinux:
				@ rm -f $(NAME)
				@printf "$(YELLOW)fdf removed.\n"

fclean:			clean
				@make -C libft/ fclean
				@make -C mlx_mac/ fclean
				@rm -rf $(NAME)
				@printf "$(YELLOW)fdfremoved.\n"

fcleanlinux:	clean
				@make -C libft/ fclean
				@make -C mlx_linux/ clean
				@rm -rf $(NAME)
				@printf "$(YELLOW)fdf removed.\n"

re:				fclean all

.PHONY:
				all clean fclean re
