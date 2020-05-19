CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb
CXX_DEMO := -Wall -Wextra -std=c++17 -ggdb -D=DEMO
CXX_ESTA := -Wall -Wextra -std=c++17 -ggdb -D=ESTA

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_DEMO) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
