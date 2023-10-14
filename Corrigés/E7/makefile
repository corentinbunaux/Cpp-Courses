ListeAnimaux.o : Animal.h ListeAnimaux.h ListeAnimaux.cpp
	g++ -c ListeAnimaux.cpp

e7.o : Animal.h Chien.h Cheval.h Oiseau.h Pigeon.h Corbeau.h Rossignol.h \
        ListeAnimaux.h e7.cpp
	g++ -c e7.cpp

e7 : ListeAnimaux.o e7.o
	g++ ListeAnimaux.o e7.o -o e7
