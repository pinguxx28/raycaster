CC 		:=	cc
CLIBS	:=	-lGL -lGLU -lglut -lm
CFLAGS	:=	-O3

SRC_DIR	:= src
OBJ_DIR := obj
SRCS	:= $(wildcard $(SRC_DIR)/*.c)	
OBJS	:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

TARGET	:= game

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CLIBS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm $(OBJS)
	rm game
