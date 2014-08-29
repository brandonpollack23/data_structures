#Brandon Pollack
#Section 1087
#2375-4365
#Assignment 2
default: main

main: main.o
	g++ main.o -o main

main.o: ArrayLinearList.h main.cpp
	g++ main.cpp

clean:
	rm *.o main
	
tarfile:
	tar -cvf Brandon_Pollack_2375_4365.tar main.cpp ArrayLinearList.h makefile