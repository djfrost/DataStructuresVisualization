AutomatedMakefile = am
CC = g++ -std=c++11

INC_DIRS=-I./
LIB_DIRS=-L./
LIBS=

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS) -o
FILES = WindowedDriver.o
all: GUIDriver

GUIDriver: $(FILES)
			$(LINK) GUIDriver.exe $(FILES) 

WindowedDriver.o: WindowedDriver.cpp
			$(COMPILE) WindowedDriver.cpp
