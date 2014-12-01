PROG = bin/prog
BIN_DIR = bin/
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = -I/. -Iinc/. -I/usr/local/include -I/usr/include
LIB_DIR = -L/usr/lib
EXTRA_LIBS = -lmraa -lcurses
CC = gcc

_OBJS = setpwm.o util.o main.o 
OBJS = $(patsubst %,$(OBJ_DIR)%,$(_OBJS))

all: DIR $(OBJS)
	$(CC) $(INC_DIR) -o $(PROG) $(OBJS)  $(LIB_DIR) $(EXTRA_LIBS) 

DIR:
	mkdir obj; mkdir bin

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(INC_DIR) -Wall -c -g -o $@ $<$(CFLAGS) 

clean:
	$(RM) -r obj bin *.o

