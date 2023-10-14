SHORT.o : Deborde.h DivZero.h SHORT.h SHORT.cpp
	g++ -c SHORT.cpp

e11.o : Deborde.h DivZero.h SHORT.h e11.cpp
	g++ -c e11.cpp

e11 : SHORT.o e11.o
	g++ SHORT.o e11.o -o e11
