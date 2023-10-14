Vehicule.o : Vehicule.h Vehicule.cpp
	g++ -c Vehicule.cpp

Moto.o : Vehicule.h Moto.h Moto.cpp
	g++ -c Moto.cpp

e6.o : Vehicule.h Moto.h e6.cpp
	g++ -c e6.cpp

e6 : Vehicule.o Moto.o e6.o
	g++ Vehicule.o Moto.o e6.o -o e6
