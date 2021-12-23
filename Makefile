# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majjig <majjig@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 13:13:13 by majjig            #+#    #+#              #
#    Updated: 2021/12/23 14:52:35 by majjig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC = minitalk.h

CSRC = client.c
CSRC_OBJ = ${CSRC:.c=.o}

SSRC = server.c
SSRC_OBJ = ${SSRC:.c=.o}

CNAME = client

BNSSERVER = server_bonus.c
BNSCLIENT = client_bonus.c

SNAME = server

all: $(CNAME) $(SNAME)

$(CNAME): $(CSRC_OBJ) $(INC)
	$(CC) $(CFLAGS) $(CSRC_OBJ) -o $(CNAME)
$(SNAME): $(SSRC_OBJ) $(INC)
	$(CC) $(CFLAGS) $(SSRC_OBJ) -o $(SNAME)

clean:
	@rm -rf $(SSRC_OBJ) $(CSRC_OBJ)

fclean: clean
	@rm -rf $(CNAME) $(SNAME)

bonus: $(BNSCLIENT) $(BNSSERVER)
	$(CC) $(CFLAGS) $(BNSCLIENT) -o $(CNAME)
	$(CC) $(CFLAGS) $(BNSSERVER) -o $(SNAME)

re: fclean all
