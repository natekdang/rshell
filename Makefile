COMPILE = g++
FLAGS =  -Wall -Werror -ansi -pedantic -std=c++11 

all: move
	$(COMPILE) $(FLAGS) ./src/main.cpp -o ./bin/rshell
	

rshell: move
	$(COMPILE) $(FLAGS) ./src/main.cpp -o ./bin/rshell

move: 
	@mkdir bin

