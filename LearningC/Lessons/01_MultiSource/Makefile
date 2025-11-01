#vim: noexpandtab: ts=8: softtabstop=8

# names and places
SRC_DIR	= src
INC_DIR	= src
TARGET 	= testing_C
BLD_DIR	= build
#tools
CC 		= gcc
#CPPFLAGS= -I $(SRC_DIR)
CPPFLAGS+= --save-temps
CFLAGS	= -g -Wall
CFLAGS	= -Os -g -Wall
LDFLAGS	= -g
LDFLAGS	= -g -Os
# -----  automated filenames -----
C_SRCS	= $(wildcard $(SRC_DIR)/*.c)
INC_FILES	= $(wildcard $(SRC_DIR)/*.h)
OBJ_FILES	= $(C_SRCS:$(SRC_DIR)/%.c=$(BLD_DIR)/%.o)

#targets - elements
# the colours are bonus ("\033[....]")
$(BLD_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@echo "\033[07;36m"
	@echo $< generates $@
	$(CC) -c $(CFLAGS) $< -o $@
	@echo "\033[00m"


$(TARGET): $(OBJ_FILES)
	@echo "\033[01;33m"
	@echo building $@ from $(OBJ_FILES)
	@echo "\033[00m"
	$(CC) $(LDFLAGS) -o $@ $(OBJ_FILES)

#not necessary, but really useful to get rid of stray files ans errors
clean:
	rm -rf $(BLD_DIR)/*
	rm $(TARGET)

#=======================#
# what follows is bonus to make life cool

# the target is not a file <> "PHONY"
.PHONY: all run clean listfiles test hello

check:	$(OBJ_FILES) $(TARGET)

test:	$(C_SRCS) $(OBJ_FILES)
	@echo "includes \t:" $(INC_FILES)
	@echo "sources  \t:" $(C_SRCS)
	@echo "objects  \t:" $(OBJ_FILES)
	@echo "test  \t\t:" $(C_SRCS:$(SRC_DIR)/%.c=$(BLD_DIR)/%.o)

hello:
	@echo "\n\tHey Dude, nice to see you!\n"

all: run listfiles hello


run: $(TARGET)
	@echo "\033[01;32;44m"
	@echo "-+-+-+-"
	./$(TARGET)
	@echo "-+-+-+-"
	@echo "\033[00m"

listfiles:
	@echo current dir:
	@ls
	@echo "\033[01;32m"sources"\033[00m"
	@ls -lAh $(SRC_DIR)
	@echo "\033[01;32m"objects"\033[00m"
	@ls -lAh $(BLD_DIR)
