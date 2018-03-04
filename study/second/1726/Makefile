CC=g++
CFLAGS= -pedantic -Wall -Werror -std=c++17

all:
	$(CC) $(CFLAGS)  ./main.cpp -o ./program

generate:
	$(CC) $(CFLAGS)  ./generator.cpp -o ./generate

clean:
	rm -rf ./program ./generate

clean-data:
	rm -rf data.txt
