SRC=src/
INCLUDE=include/
OBJ=obj/
BIN=bin/
CC=g++
CFLAGS= -Wall -pedantic 
IFLAGS=-I$(INCLUDE) 

vpath %.o $(OBJ)
vpath %.h $(INCLUDE)
vpath %.cpp $(SRC)

optiMain : optiMain.o Netitron.o PrimeNetwork.o neuroBot.o RandHomme.o |bin
	$(CC) -o $@ $(OBJ)optiMain.o $(OBJ)Netitron.o $(OBJ)PrimeNetwork.o $(OBJ)neuroBot.o $(OBJ)RandHomme.o
	mv $@ $(BIN)

%.o : |obj
	$(CC) $(CFLAGS) $(IFLAGS) -c $<
	mv $@ $(OBJ)

Netitron.o : Netitron.cpp Netitron.h PrimeNetwork.h RandHomme.h
neuroBot.o : neuroBot.cpp neuroBot.h
PrimeNetwork.o : PrimeNetwork.cpp PrimeNetwork.h neuroBot.h RandHomme.h
RandHomme.o : RandHomme.cpp RandHomme.h
optiMain.o : optiMain.cpp Netitron.h

obj :
	mkdir $(OBJ)

bin :
	mkdir $(BIN)

clean :
	rm -r obj/ bin/ doc/

	
