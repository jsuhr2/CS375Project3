P=program3
CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14

all: $(P)

$(P).o: $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(P): $(P).o
	g++ $(CFLAGS) $(P).o -o submission

run: all
	./submission smallInput.txt smallOutputGreedy2.txt 1
	./submission smallInput.txt smallOutputBacktracking.txt 2
	./submission input.txt outputGreedy2.txt 1
	./submission input.txt outputBacktracking.txt 2
	./submission badGreedyInput.txt outputbadGreedy1.txt 0
	./submission badGreedyInput.txt outputbadGreedy2.txt 1
	./submission badImprovedGreedyInput.txt outputbadImprovedGreedy2.txt 1
	./submission mediumInput.txt mediumOutputGreedy2.txt 1
	./submission mediumInput.txt mediumOutputBacktracking.txt 2

clean:
	rm $(P).o
	rm submission
