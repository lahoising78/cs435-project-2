.DEFAULT_GOAL := all
CC = g++

SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

TEST_DIR = tests
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(wildcard $(TEST_FILES)))

OBJ_DIR = bin
OBJS = 	$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(wildcard $(SRC_FILES)))

INC_DIR = include
INC_PARAMS = $(foreach d, $(INC_DIR), -I$d)

LFLAGS = -g -o
CFLAGS =
ifdef letters
	CFLAGS += -DLETTER_NODES
endif

ODIR = executables

EXECS =	$(patsubst $(TEST_DIR)/%.cpp,%,$(wildcard $(TEST_FILES)))

$(EXECS) : $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(OBJ_DIR)/$(@).o $(LFLAGS) $(ODIR)/$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(LFLAGS) $@ $^ $(CFLAGS) $(INC_PARAMS)

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) -c $(LFLAGS) $@ $^ $(CFLAGS) $(INC_PARAMS)

.PHONY: directories clean all letters

all: directories $(EXECS)

letters: 
	${MAKE} letters=1

directories: $(ODIR) $(OBJ_DIR)
	
$(ODIR):
	mkdir -p $(ODIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -R $(OBJ_DIR)
	rm -R $(ODIR)