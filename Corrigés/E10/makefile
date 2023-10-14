String.o : String.h String.cpp
	g++ -c String.cpp

e10.o : String.h Ensemble.h e10.cpp
	g++ -c e10.cpp

e10 : String.o e10.o
	g++ String.o e10.o -o e10
