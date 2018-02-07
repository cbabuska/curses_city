CC = gcc
CFLAGS = -pedantic -Wall -I inc 
LD = g++
LDFLAGS = -lncurses
RM = /bin/rm 
OBJS = Main.o Logger.o View.o Cell_factory.o Grid.o Cursor.o Status.o Cell.o Zone.o Municipal.o Status_grid.o 
PROG = Curses_City

all: $(PROG)

$(PROG): $(OBJS)
	$(LD) $(OBJS) -o $(PROG) $(LDFLAGS) 

Main.o: src/Main.cpp inc/Constants.h inc/Logger.h inc/View.h inc/Cell_factory.h inc/Grid.h inc/Cursor.h inc/Status.h inc/Cell.h inc/Status_grid.h  
	$(CC) $(CFLAGS) -c src/Main.cpp

Logger.o: src/Logger.cpp inc/Logger.h
	$(CC) $(CFLAGS) -c src/Logger.cpp

View.o: src/View.cpp inc/View.h
	$(CC) $(CFLAGS) -c src/View.cpp

Cell_factory.o: src/Cell_factory.cpp inc/Cell_factory.h inc/Zone.h inc/Municipal.h
	$(CC) $(CFLAGS) -c src/Cell_factory.cpp

Grid.o: src/Grid.cpp inc/Grid.h inc/Logger.h inc/Constants.h 
	$(CC) $(CFLAGS) -c src/Grid.cpp

Cursor.o: src/Cursor.cpp inc/Cursor.h inc/Logger.h inc/Constants.h 
	$(CC) $(CFLAGS) -c src/Cursor.cpp

Status.o: src/Status.cpp inc/Status.h inc/Logger.h inc/Constants.h 
	$(CC) $(CFLAGS) -c src/Status.cpp

Cell.o: src/Cell.cpp inc/Cell.h inc/Logger.h
	$(CC) $(CFLAGS) -c src/Cell.cpp

Zone.o: src/Zone.cpp inc/Zone.h inc/Constants.h inc/Logger.h inc/Cell.h 
	$(CC) $(CFLAGS) -c src/Zone.cpp

Municipal.o: src/Municipal.cpp inc/Municipal.h inc/Logger.h inc/Cell.h 
	$(CC) $(CFLAGS) -c src/Municipal.cpp

Status_grid.o: src/Status_grid.cpp inc/Status_grid.h inc/Logger.h inc/Constants.h 
	$(CC) $(CFLAGS) -c src/Status_grid.cpp


clean:
	$(RM) $(PROG) $(OBJS) log.txt *~ */*~ 


