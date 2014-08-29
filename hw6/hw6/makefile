#Brandon Pollack
#2375-4365

default: main

main: BinarySearchTree.o BinaryTree.o BinPacking.o MaxWinnerTree.o main.o
	g++ BinarySearchTree.o BinaryTree.o BinPacking.o MaxWinnerTree.o main.o -o main
	
BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp
	g++ -c BinarySearchTree.cpp
	
BinaryTree.o: BinaryTree.h BinaryTree.cpp
	g++ -c BinaryTree.cpp
	
BinPacking.o: BinPacking.h BinPacking.cpp
	g++ -c BinPacking.cpp
	
MaxWinnerTree.o: MaxWinnerTree.h MaxWinnerTree.cpp
	g++ -c MaxWinnerTree.cpp
	
main.o: main.cpp
	g++ -c main.cpp
	
clean:
	rm *.o main
	
tarfile:
	tar -cvf Brandon_Pollack_2375_4365.tar BinPacking.h BinPacking.cpp BinarySearchTree.h BinarySearchTree.cpp BinaryTree.h BinaryTree.cpp MaxWinnerTree.h MaxWinnerTree.cpp main.cpp main makefile
