Vehicule.o : Vehicule.h Vehicule.cpp
	g++ -c Vehicule.cpp

Terrestre.o : Vehicule.h Terrestre.h Terrestre.cpp
	g++ -c Terrestre.cpp

Marin.o : Vehicule.h Marin.h Marin.cpp
	g++ -c Marin.cpp

Amphibie.o : Terrestre.h Marin.h Amphibie.h Amphibie.cpp
	g++ -c Amphibie.cpp

e8.o : Terrestre.h Marin.h Amphibie.h e8.cpp
	g++ -c e8.cpp

e8 : Vehicule.o Terrestre.o Marin.o Amphibie.o e8.o
	g++ Vehicule.o Terrestre.o Marin.o Amphibie.o e8.o -o e8
