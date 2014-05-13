SRC=src/
INCLUDE=include/
OBJ=obj/
BIN=bin/
CC=gcc
CFLAGS= -Wall -pedantic 
IFLAGS=-I$(INCLUDE) 

vpath %.o $(OBJ)
vpath %.h $(INCLUDE)
vpath %.cpp $(SRC)

all :
	

%.o : |obj
	$(CC) $(CFLAGS) $(IFLAGS) -c $<
	mv $@ $(OBJ)

NetiTron.o : NetiTron.cpp NetiTron.h PrimeNetwork.h RandHomme.h
neuroBot.o : neuroBot.cpp neuroBot.h
PrimeNetwork.o : PrimeNetwork.cpp PrimeNetwork.h neuroBot.h RandHomme.h
RandHomme.o : RandHomme.cpp RandHomme.h
optiMain.o : optiMain.cpp Netitron.h

optiMain : optiMain.o Netitron.o PrimeNetwork.o neuroBot.o RandHomme.o |bin
	$(CC) -o $@ $(OBJ)optiMain.o $(OBJ)Netitron.o $(OBJ)PrimeNetwork.o $(OBJ)neuroBot.o $(OBJ)RandHomme.o
	mv $@ $(BIN)
	
obj :
	mkdir $(OBJ)

bin :
	mkdir $(BIN)

clean :
	rm -r obj/ bin/ doc/

	
