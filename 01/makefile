CC=g++
FLAGS=-std=c++17 -Wall -Werror -fsanitize=address -Wextra

all: tests.o alloc.o
	$(CC) $(FLAGS) tests.o alloc.o -o tests

tests.o: tests.cpp
	$(CC) $(FLAGS) tests.cpp -c

alloc.o: alloc.h alloc.cpp
	$(CC) $(FLAGS) alloc.cpp -c

test: tests.o alloc.o
	$(CC) $(FLAGS) tests.o alloc.o -o test
	./test

clean:
	rm -f *.o tests
