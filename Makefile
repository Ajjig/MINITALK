# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majjig <majjig@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 13:13:13 by majjig            #+#    #+#              #
#    Updated: 2021/12/23 13:13:14 by majjig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CSRC = client.c
CSRC_OBJ = ${CSRC:.c=.o}

SSRC = server.c
SSRC_OBJ = ${SSRC:.c=.o}

CNAME = client

SNAME = server

all: $(CNAME) $(SNAME)

$(CNAME): $(CSRC_OBJ)
	$(CC) $(CFLAGS) $(CSRC_OBJ) -o $(CNAME)
$(SNAME): $(SSRC_OBJ)
	$(CC) $(CFLAGS) $(SSRC_OBJ) -o $(SNAME)

clean:
	@rm -rf $(SSRC_OBJ) $(CSRC_OBJ)

fclean: clean
	@rm -rf $(CNAME) $(SNAME)

re: fclean all
