#Brandon Pollack
#2375-4365
default: main

main: Graph.o GraphSolver.o main.o
	g++ Graph.o GraphSolver.o main.o -o main
	
main.o: main.cpp
	g++ -c main.cpp

Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp
	
GraphSolver.o: GraphSolver.cpp GraphSolver.h
	g++ -c GraphSolver.cpp
	
clean:
	rm *.o main
	
tarfile:
	tar -cvf BrandonPollack_2375_4365.tar Graph.cpp Graph.h GraphSolver.cpp GraphSolver.h main.cpp main
	
