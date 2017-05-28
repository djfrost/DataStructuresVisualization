AutomatedMakefile = am
CC = g++ -std=c++11

INC_DIRS=-I./
LIB_DIRS=-L./
LIBS=

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS) -o
FILES = CommandDriver.o
all: CMDDriver

CMDDriver: $(FILES)
			$(LINK) CMDDriver.exe $(FILES) $(LIBS)

CommandDriver.o: CommandDriver.cpp
			$(COMPILE) CommandDriver.cpp
