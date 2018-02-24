CC=g++
CFLAGS= -pedantic -Wall -Werror -std=c++17

all: makedir
	$(CC) $(CFLAGS)  ./main.cpp -o ./build/program

makedir:
	mkdir ./build

clean:
	rm -rf ./build
