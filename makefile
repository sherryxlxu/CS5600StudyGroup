all: server fget

server: server.c
	gcc server.c -o server

fget: fget.c
	gcc fget.c -o fget
