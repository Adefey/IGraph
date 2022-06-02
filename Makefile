Compiler=g++
Flags=-I . -Ofast -std=c++2a -Wall -Werror -Wpedantic

all: Prepare BuildArcGraph BuildListGraph BuildMatrixGraph BuildSetGraph BuildMain BuildAll CleanObj RunTests

Prepare:
	clang-format -i *.h *.cpp

BuildArcGraph: IGraph.h ArcGraph.h ArcGraph.cpp
	$(Compiler) $(Flags) -c ArcGraph.cpp -o ArcGraph.o

BuildListGraph: IGraph.h ListGraph.h ListGraph.cpp
	$(Compiler) $(Flags) -c ListGraph.cpp -o ListGraph.o

BuildMatrixGraph: IGraph.h MatrixGraph.h MatrixGraph.cpp
	$(Compiler) $(Flags) -c MatrixGraph.cpp -o MatrixGraph.o

BuildSetGraph: IGraph.h SetGraph.h SetGraph.cpp
	$(Compiler) $(Flags) -c SetGraph.cpp -o SetGraph.o

BuildMain: Main.cpp
	$(Compiler) $(Flags) -c Main.cpp -o Main.o

BuildAll:  ArcGraph.o ListGraph.o MatrixGraph.o SetGraph.o Main.o
	$(Compiler) $(Flags) ArcGraph.o ListGraph.o MatrixGraph.o SetGraph.o Main.o -o Executable -lgtest

CleanObj: ArcGraph.o ListGraph.o MatrixGraph.o SetGraph.o Main.o
	rm *.o

RunTests: Executable
	valgrind ./Executable

