SER=msg_ser
SER_SRC=comm.c msg_ser.c

CLI=msg_cli
CLI_SRC=comm.c msg_cli.c

INCLUDE=./

CC=gcc
FLAGS=-g

.PHONY:all
all:$(SER) $(CLI)

$(SER):$(SER_SRC)
	$(CC) -o $@ $^ $(FLAGS) -I$(INCLUDE)

$(CLI):$(CLI_SRC)
	$(CC) -o $@ $^ $(FLAGS) -I$(INCLUDE)

.PHONY:clean
clean:
	rm -rf $(SER) $(CLI)



