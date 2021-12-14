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

fclean:
	@rm -rf $(CNAME) $(SNAME)
