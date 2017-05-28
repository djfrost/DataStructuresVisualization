AutomatedMakefile = am
CC = g++ -w -Wl,-subsystem,windows


INC_DIRS=-I./ -I./SDL2/include/
LIB_DIRS=-L./ -L./SDL2/lib/
LIBS=-lmingw32 -lSDL2main -lSDL2

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS) -o
FILES = WindowedDriver.o
all: GUIDriver

GUIDriver: $(FILES)
			$(LINK) GUIDriver.exe $(FILES) $(LIBS)

WindowedDriver.o: WindowedDriver.cpp
			$(COMPILE) WindowedDriver.cpp
