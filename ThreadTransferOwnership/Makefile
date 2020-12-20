.PHONY: all clean

out := ThreadTransferOwnership.out

all: $(out)

main.o: main.cpp
	g++ -std=c++17 -Wall -Wextra -g -c $< -o $@

$(out) : main.o
	g++ -lpthread -pthread $^ -o $(out)

clean:
	rm -rf *.o *.out
