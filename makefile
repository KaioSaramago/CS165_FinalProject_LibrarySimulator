PROGS := lib

all: $(PROGS)


lib: LibraryItem.o Book.o Album.o Movie.o Patron.o Library.o Menu.o
	g++ -g LibraryItem.o Book.o Album.o Movie.o Patron.o Library.o Menu.o -o lib

LibraryItem.o: LibraryItem.cpp LibraryItem.hpp
	g++ -c LibraryItem.cpp

Book.o: Book.cpp Book.hpp
	g++ -c Book.cpp

Album.o: Album.cpp Album.hpp
	g++ -c Album.cpp

Movie.o: Movie.cpp Movie.hpp
	g++ -c Movie.cpp

Patron.o: Patron.cpp Patron.hpp
	g++ -c Patron.cpp

Library.o: Library.cpp Library.hpp
	g++ -c Library.cpp

Menu.o: Menu.cpp
	g++ -c Menu.cpp


clean:
	rm -f $(PROGS) *.o *~
