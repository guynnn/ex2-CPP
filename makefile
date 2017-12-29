GCC_FLAGS = g++ -std=c++11 -Wextra -Wall 

chess: chess.o Board.o Rook.o Bishop.o Knight.o King.o Queen.o Pawn.o Piece.o
	$(GCC_FLAGS) chess.o Board.o Rook.o Bishop.o King.o Queen.o Pawn.o Knight.o Piece.o -o chess

all: chess.o Board.o Rook.o Bishop.o Knight.o King.o Queen.o Pawn.o Piece.o
	$(GCC_FLAGS) chess.o Board.o Rook.o Bishop.o King.o Queen.o Pawn.o Knight.o Piece.o -o chess

King.o: King.cpp King.h
	$(GCC_FLAGS) -c King.cpp -o King.o

Piece.o: Piece.h Piece.cpp
	$(GCC_FLAGS) -c Piece.cpp -o Piece.o

Board.o: Board.h Board.cpp
	$(GCC_FLAGS) -c Board.cpp -o Board.o

Pawn.o: Pawn.cpp Pawn.h
	$(GCC_FLAGS) -c Pawn.cpp -o Pawn.o

Bishop.o: Bishop.cpp Bishop.h
	$(GCC_FLAGS) -c Bishop.cpp -o Bishop.o

Knight.o: Knight.cpp Knight.h
	$(GCC_FLAGS) -c Knight.cpp -o Knight.o

chess.o: chess.cpp Board.h
	$(GCC_FLAGS) -c chess.cpp -o chess.o

Queen.o: Queen.cpp Queen.h
	$(GCC_FLAGS) -c Queen.cpp -o Queen.o

Rook.o: Rook.cpp Rook.h
	$(GCC_FLAGS) -c Rook.cpp -o Rook.o

tar: 
	tar cvf ex2.tar *.cpp *.h makefile

valgrind:
	valgrind --leak-check=full --show-possibly-lost=yes --show-reachable=yes --undef-value-errors=yes ./chess

clean:
	rm *.o chess
