CC = g++  # compiler

CFLAGS = -std=c++17 -Wall -Werror # compiler flags -- tell compiler what to compile

OBJS = main.o cell.o gameboard.o

gameoflife: $(OBJS)  # making GOL executable. Dependencies come after ":" 
	$(CC) $(CFLAGS) $(OBJS) -o gameoflife

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
	
cell.o: cell.cpp
	$(CC) $(CFLAGS) -c cell.cpp

gameboard.o: gameboard.cpp
	$(CC) $(CFLAGS) -c gameboard.cpp

clean:
	rm -rf $(OBJS) gameoflife
	