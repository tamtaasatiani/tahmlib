# Test Linux Makefile

CXX := g++
OPT := 
INC := `sdl2-config --cflags`
LIB := -lSDL2 -lSDL2_ttf
TAHM_SRC := $(wildcard tahm/*.cpp)
TAHM_OBJ := $(patsubst tahm/%.cpp,%.o,$(TAHM_SRC))
PROJECT = test

all: $(PROJECT)

debug: OPT = -g -Wall
debug: clean
debug: $(PROJECT)

$(PROJECT): $(TAHM_OBJ) main.cpp
	$(CXX) $(OPT) $(INC) main.cpp engine.cpp *.o -o $(PROJECT) $(LIB)

$(TAHM_OBJ): %.o: tahm/%.cpp
	$(CXX) $(OPT) -c $< $(INC) 

tell:
	@echo $(TAHM_OBJ)

.PHONY: clean
clean:
	rm -rf $(PROJECT)
	rm -rf *.o

