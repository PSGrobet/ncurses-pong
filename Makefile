CXX          := g++

BIN          := bin
SRC          := ./src

LIBRARIES    := -lncurses -lncursesw
EXECUTABLE   := main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	#clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
