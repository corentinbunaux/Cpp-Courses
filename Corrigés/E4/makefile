String.o : String.h String.cpp
	g++ -c String.cpp

Compte.o : String.h Compte.h Compte.cpp
	g++ -c Compte.cpp

e4.o : String.h Compte.h e4.cpp
	g++ -c e4.cpp

e4 : String.o Compte.o e4.o
	g++ String.o Compte.o e4.o -o e4
