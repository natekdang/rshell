$(shell mkdir -p bin)
CC = g++
CC_FLAGS = -Wall -Werror -pedantic -ansi -std=c++11
EXEC = bin/rshell
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

clean:
	rm -rfv $(EXEC) $(OBJECTS)
