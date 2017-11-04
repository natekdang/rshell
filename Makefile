COMPILE = g++
FLAGS =  -Wall -Werror -ansi -pedantic 

all: move
		$(COMPILE)$(FLAGS) ./src/main.cpp -o ./bin/rshell

rshell: move
		$(COMPILE)$(FLAGS) ./src/main.cpp -o ./bin/rshell
	
move:
		@mkdir bin
