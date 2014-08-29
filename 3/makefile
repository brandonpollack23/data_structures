#Makefile for assighment 3
#Brandon Pollack
#2375-4365
default: main1

main1: IOcode.o Myexception.o Arraylist.o main1.o 
	g++ Arraylist.o IOcode.o main1.o Myexception.o -o main1
	
main2: IOcode.o Myexception.o Chain.o main2.o
	g++ IOcode.o Myexception.o Chain.o main2.o -o main2
	
Chain.o: Chain.cpp 
	g++ -c Chain.cpp

Arraylist.o: Arraylist.cpp 
	g++ -c Arraylist.cpp

IOcode.o: IOcode.cpp
	g++ -c IOcode.cpp

main1.o: main1.cpp
	g++ -c main1.cpp

Myexception.o: Myexception.cpp Myexception.h
	g++ -c Myexception.cpp

clean:
	rm -rf *.o main1 main2

tarfile:
	tar -cvf Brandon_Pollack_2375-4365.tar main1.cpp main2.cpp Arraylist.cpp Arraylist.h Myexception.cpp Myexception.h IOcode.cpp IOcode.h Chain.cpp Chain.h ChainNode.h makefile 
