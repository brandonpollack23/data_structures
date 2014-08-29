#Brandon Pollack
#2375-4365
default: main

main: Arraylist.o BinaryTree.o main.o MinHeap.o myException.o PriorityQueue.o
	g++ Arraylist.o BinaryTree.o main.o MinHeap.o myException.o PriorityQueue.o -o main

Arraylist.o: Arraylist.cpp Arraylist.h
	g++ -c Arraylist.cpp
	
BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -c BinaryTree.cpp
	
main.o: main.cpp
	g++ -c main.cpp

MinHeap.o: MinHeap.cpp MinHeap.h
	g++ -c MinHeap.cpp
	
myException.o: myException.cpp myException.h
	g++ -c myException.cpp
	
PriorityQueue.o: PriorityQueue.cpp PriorityQueue.h
	g++ -c PriorityQueue.cpp
	
clean:
	rm *.o main
	
tarfile:
	tar -cvf Brandon_Pollack_2375_4365.tar PriorityQueue.cpp PriorityQueue.h myException.cpp myException.h MinHeap.cpp MinHeap.h main.cpp BinaryTree.cpp BinaryTree.h Arraylist.cpp Arraylist.h main makefile