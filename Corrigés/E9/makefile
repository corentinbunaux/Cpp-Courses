Point.o : Point.h Point.cpp
	g++ -c Point.cpp

Segment.o : Point.h Segment.h Segment.cpp
	g++ -c Segment.cpp

Forme.o : Forme.h Forme.cpp
	g++ -c Forme.cpp

Cercle.o : Point.h Forme.h Cercle.h Cercle.cpp
	g++ -c Cercle.cpp

Rectangle.o : Segment.h Forme.h Rectangle.h Rectangle.cpp
	g++ -c Rectangle.cpp

Carre.o : Segment.h Rectangle.h Carre.h Carre.cpp
	g++ -c Carre.cpp

ListeFormes.o : Forme.h ListeFormes.h ListeFormes.cpp
	g++ -c ListeFormes.cpp

e9.o : Point.h Segment.h Cercle.h Rectangle.h Carre.h ListeFormes.h e9.cpp
	g++ -c e9.cpp

OBJ = Point.o Segment.o Forme.o Cercle.o Rectangle.o Carre.o ListeFormes.o e9.o

e9 : $(OBJ)
	g++ $(OBJ) -o e9
