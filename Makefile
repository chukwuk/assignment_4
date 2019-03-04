CC=g++
EXE_F=wumpusgame


all: $(EXE_F)

$(EXE_F):bats.o bats.hpp main.cpp pit.o pit.hpp gold.o gold.hpp wumpus.o wumpus.hpp room.o room.hpp event.hpp
	$(CC) room.o main.cpp bats.o pit.o wumpus.o gold.o -o $(EXE_F)

room.o:room.cpp room.hpp event.hpp
	$(CC) -c room.cpp -o room.o

bats.o:bats.cpp bats.hpp event.hpp
	$(CC) -c bats.cpp -o bats.o

pit.o:pit.cpp pit.hpp event.hpp
	$(CC) -c pit.cpp -o pit.o

gold.o:gold.cpp gold.hpp event.hpp
	$(CC) -c gold.cpp -o gold.o

wumpus.o:wumpus.cpp wumpus.hpp event.hpp
	$(CC) -c wumpus.cpp -o wumpus.o


clean:
	rm -rf o*
