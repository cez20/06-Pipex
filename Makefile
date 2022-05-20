# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 13:59:50 by cemenjiv          #+#    #+#              #
#    Updated: 2022/05/20 10:19:39 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex  #nom de l'executable que l'on veut creer 

SRCS			= srcs/main.c srcs/input_validation.c srcs/error_handling.c srcs/pipex.c \
				  srcs/free.c

HEADER			= -Iinclude/
				  	  
OBJS			= $(SRCS:.c=.o) #Declaration OBJS (objets). Tous les fichiers terminant par le suffixe .c vont devenir .o

CC				= gcc  #name of C compiler
CFLAGS			= -Wall -Wextra -Werror -g  #nom des differents flags a utiliser 
RM				= rm -f  #shortcut Rm fait ce que fait normalement rm -f 

.c.o:		
				gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o) 
	
all:			$(NAME)  #commande "make all" fait ce que la variable NAME fait

$(NAME):		$(OBJS)  #Convertis tous les fichiers sources (.c) and fichier objet (.o)
				$(MAKE) bonus -C ./libft 
				$(CC) ${OBJS} -L libft -l ft -o ${NAME}			

				
clean:		
				$(MAKE) clean -C ./libft
				$(RM) $(OBJS)
				
fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)
				
re:				fclean all
				



