CC=gcc
RPC=rpcgen

OBJ_INTERFACE = get_free_token.x  

OBJ_SERVER = servico.c get_free_token_svc.c

OBJ_CLIENT = cliente.c get_free_token_clnt.c

DELETE = get_free_token_svc.c get_free_token_clnt.c get_free_token.h

interface: $(OBJ_INTERFACE)
	$(RPC) $^

server: $(OBJ_SERVER)
	$(CC) $^ -o $@

client: $(OBJ_CLIENT)
	$(CC) $^ -o $@ 

all: interface server client

clean:
	rm server client $(DELETE)
