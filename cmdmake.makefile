AutomatedMakefile = am
CC = g++

INC_DIRS=-I./ -I./DataStructures
LIB_DIRS=-L./ -L./DataStructures
LIBS=

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS) -o
FILES = CommandDriver.o
all: CMDDriver

CMDDriver: $(FILES)
			$(LINK) CMDDriver.exe $(FILES) $(LIBS)

CommandDriver.o: CommandDriver.cpp DataStructures/HashTable.h
			$(COMPILE) CommandDriver.cpp
